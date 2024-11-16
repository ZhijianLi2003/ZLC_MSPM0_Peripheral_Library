#   Copyright (C) 2024 Texas Instruments Incorporated - http://www.ti.com/
#
#   Redistribution and use in source and binary forms, with or without
#   modification, are permitted provided that the following conditions
#   are met:
#
#    Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#
#    Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the
#    distribution.
#
#    Neither the name of Texas Instruments Incorporated nor the names of
#    its contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
#   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
#   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
#   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
#   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
#   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
#   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
#   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
#   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
#   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

import click
import string
from encryptImage import Encryptor

@click.command()
@click.option('-f','--binfile',help="input binary file")
@click.option('-o','--outfile', default="image.txt", help="output file")
@click.option('--encrypt/--no-encrypt', default=False)
@click.option('-c','--cipherfile', default="image_encrypted.txt", help="ciphertext output file")
@click.option('-s','--startaddr',help="start Address")
def bin_to_titxt_encrypt(binfile, outfile, encrypt, cipherfile, startaddr): 
    print("converting {} to {}".format(binfile, outfile))
    f = open(binfile,'rb')
    o = open(outfile, 'w')

    if encrypt: 
        c = open('ctxt_temp.txt', 'w')
        cipher = Encryptor(cipherfile)

    o.write("@{}\n".format(startaddr))

    if encrypt: 
        c.write("@{}\n".format(startaddr))
    
    x = f.read(1)
    i = 0
    len = 0
    while x:
        len += 1 
        a = int.from_bytes(x, "little")
        o.write("{:02x}".format(a).upper())
        
        if encrypt: 
            y = cipher.encrypt(x)
            b = int.from_bytes(y, "little")
            c.write("{:02x}".format(b).upper())

        
        if i < 15: 
            space_char = " "
        else :
            space_char = "\n"
        
        o.write(space_char)
        if encrypt: 
            c.write(space_char)

        i = (i + 1) % 16
        x = f.read(1)

    # if not a full aligned row, change the data length
    if (i != 0): 
        o.write("\n")
        if encrypt:
            while i < 15: 
                c.write("00 ")
                i += 1
            c.write("00\n")

    o.write('q')

    if encrypt: 
        c.write('q')
        c.close()

        cipher.set_image_length(len)
        print("Generating Encrypted Image: {}.".format(cipherfile))
        cipher.generate_header()

        # create one file, the cipherfile by appending temporary ciphertext 
        c1 = open(cipherfile, 'a+')
        c2 = open('ctxt_temp.txt', 'r')

        c1.write(c2.read())
        c1.close()
        c2.close()

    f.close()
    o.close()



if __name__ == "__main__":
    bin_to_titxt_encrypt()