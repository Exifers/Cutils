# Cutils
Basic scripts to generate header files, and all kind of stuff in C.

# Prerequisites
- Linux
- bash, as /bin/bash
- glibc
- gcc

# Hgen

## Description
Looks for all function headers in C in .c files of directory and subdirectories
and puts them as prototypes in .h files whose name match the source files.
Resulting files contain common preprocessor directives #ifndef, #define, etc.

## Usage
```bash
./hgen.sh [search_dir]
```
If *'search_dir* is not provided, it searches from current directory.

# Prostarter

## Description
Creates basic directories and file to start a project in C.

## Features
- choose project name
- choose source directory name
- AUTHORS file generated
- README and TODO generated (empty)
- Makefile generated, finds source files on its own
- basic main.c generated
- eventual linked lists and dictionary APIs added to the project

# Licence
Public domain.

# Authors
Exifers
