

For linux compilation, it just works.

For windows compilation, set these Environment Variables:
CGO_LDFLAGS=${PATH_TO_CALCULATOR_BIN}
CGO_CFLAGS=${PATH_TO_CALCULATOR_INCLUDE}
For example:
CGO_LDFLAGS='-L "C:\\Program Files (x86)\\Calculator\\bin"'
CGO_CFLAGS='-I "C:\\Program Files (x86)\\Calculator\\include"'

Then add the folder with the libraries (${PATH_TO_CALCULATOR_BIN}) to the PATH envvar and it works.