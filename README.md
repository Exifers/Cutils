# Cutils
Basic scripts to generate header files, and all kind of stuff in C

# Prerequisites
Linux

# Description
Looks for all function headers in C in .c files of directory and subdirectories
and puts them as prototypes in .h files whose name match the source files.
Resulting files contain common preprocessor directives #ifndef, #define, etc.

# Usage
./hgen.sh <outputname> <search_dir>

# Licence
Public domain.

# Authors
Exifers
