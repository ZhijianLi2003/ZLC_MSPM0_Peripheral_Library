let Common = system.getScript("/ti/driverlib/Common.js");

/* Extract compiler from system data, if ccs default to ticlang. */
let compiler = system.compiler;
/* Startup files for Keil are .s, other compilers are .c files */
let compiler_extension = (system.compiler == "keil")?("s"):("c")
let compiler_file_name = (system.compiler == "keil")?("uvision"):(system.compiler)

var references = [
    {
        name: "startup",
        path: "../source/ti/devices/msp/m0p/startup_system_files/${COMPILER_NAME}/startup_${DEVICE_NAME}_${COMPILER_FILE_NAME}.${STARTUP_EXTENSION}",
        alwaysInclude: false,
    },
]


function getReferencePath(name)
{
    for (var ref of references)
    {
        if (ref.name == name)
        {
            return ref.path
        }
    }
}

var componentReferences = []
for (var ref of references)
{
    /* DEVICE_NAME : MSPM0G350X */
    ref.path = ref.path.replace(/\$\{DEVICE_NAME\}/g, system.deviceData.device.toLowerCase())
    /* COMPILER_NAME: ticlang */
    ref.path = ref.path.replace(/\$\{COMPILER_NAME\}/g, compiler)
    /* COMPILER_FILE_NAME: ticlang */
    ref.path = ref.path.replace(/\$\{COMPILER_FILE_NAME\}/g, compiler_file_name)
    /* STARTUP_EXTENSION : .c */
    ref.path = ref.path.replace(/\$\{STARTUP_EXTENSION\}/g, compiler_extension)
    if(compiler == "ccs"){
        // do nothing - we dont add reference on non-specific compiler
    }
    else if(compiler == "iar"){
        componentReferences.push({
            path: ref.path,
            iarPath: ref.path.replace("..", "$SDK_ROOT$"),
            alwaysInclude: ref.alwaysInclude
        })
    }
    else{
        componentReferences.push({
            path: ref.path,
            alwaysInclude: ref.alwaysInclude
        })
    }
}

function appendReferences(refObjs)
{
    componentReferences = componentReferences.concat(refObjs);
}

exports = {
    references: references,
    getReferencePath : getReferencePath,
    appendReferences : appendReferences,
    componentReferences : componentReferences
}
