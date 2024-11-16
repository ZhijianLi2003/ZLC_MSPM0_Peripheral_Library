# this is a wrapper function to allow additional parsing and arguments such
# as a custom TLV with a hash to be added dynamically based on a key being 
# provided

import subprocess
import click
import json
import platform

@click.command()
@click.option('-s','--sdk', help='Path to the SDK to find additional scripts and tools as needed')
@click.option('-t','--toolchain',help='Path to the toolchain')
@click.option('-n','--name',help="name of project")
@click.option('-c','--color',help="color of the LED")
def make_binary(sdk,toolchain,name,color):
    # Select the proper default python executable depending on OS
    python_exe = "python3"
    if "Window" in platform.system():
        python_exe = "python"

    print("sdk:", sdk)
    print("toolchain:", toolchain)
    print("projectName:", name)

    f = open('../signingArgs.json')

    config = json.load(f)

    f.close()
    # config = {
    #     "version" : "1.0.0",
    #     "addKey" : True
    #     "privateKeyPath" : "/source/third_party/mcuboot/image_signTEST.pem"
    # }
    subprocess.run([toolchain+'/bin/tiarmobjcopy',name+'.out',
                '--output-target','binary','sample_image-unsigned.bin'],
                capture_output=True)


    if(type(config["version"]) is not list):
        versionList = [config["version"]]
    else:
        versionList = config["version"]

    # iterate over all versions provided
    for ver in versionList:

        versionStr = ver.replace('.','_')

        imgtool_optional_args = ['--header-size','0x100','--align','4','--slot-size','0x2800',
                '--pad','--version',ver,'--pad-header','--overwrite-only','--key',
                sdk+config["privateKeyPath"]]

        if "addKey" in config: 
            print("adding a key")
            imgtool_optional_args.extend(["--custom-tlv", "0xCC", "0xb93c72b74bc8487d29827005f80d635918f91bc22b14d7ed05714d58f96702dd"])
            keyFile = open("keyFile.bin", 'wb')
            keyArray = [0x603deb10, 0x15ca71be, 0x2b73aef0, 0x857d7781,
                        0x1f352c07, 0x3b6108d7, 0x2d9810a3, 0x0914dff4]
            keyString = ''.join(format(x, '08x') for x in keyArray)
            keyFile.write(bytearray.fromhex(keyString))
            keyFile.close()

        if "removeKey" in config:
            print("removing a key")
            imgtool_optional_args.extend(["--custom-tlv", "0xCD", "0x555555555555555555555555555555"])

        outFilename = 'sample_image_signed_0x4800_v'+versionStr+'_'+color

        imgtool_args = [python_exe,sdk+'/source/third_party/mcuboot/scripts/imgtool.py',
                    'sign'] + imgtool_optional_args + ['sample_image-unsigned.bin',
                        outFilename+'.bin']

        print(imgtool_args)
        proc = subprocess.run(imgtool_args, capture_output=True)
        print(proc)

        txtConversion_args = [python_exe,sdk+'/source/third_party/mcuboot/scripts/bin-to-ti-txt.py',
                            '-f',outFilename+'.bin','-o',outFilename+'.txt','--encrypt','-c',
                            outFilename+'_encrypted.txt','-s',"24800"]

        proc = subprocess.run(txtConversion_args, capture_output=True)
        print(proc)

if __name__ == "__main__":
    make_binary()

