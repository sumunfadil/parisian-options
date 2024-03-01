## About

The `parisian-options` repository contains implementation of different methods used to price Parisian options.

## Folder structure
- `lib` 
    - `docs` : documentation for function and class signatures  
    - `source`
        - `include` : header files `*.hpp`
        - `src` : source files `*.cpp`
- `main`
    - `main01` : Project 1
        - `build` : build files
        - `CMakeLists.txt`
        - `main01.cpp`
        $\newline\vdots$
    - `main100` : Project 100
        - `build` : build files
        - `CMakeLists.txt`
        - `main100.cpp`
- `.gitignore`
- `README.md`

## How to generate binary file in `build` folder?

### Using `CMake` basic option

- cd to `build` folder
- Run CMake (MY DEFAULT)
    - `cmake -GNinja ..\source\` (uses GCC by default)
    - `cmake --build .`
- Run executable file `*.exe`

### Using `CMake` with other generators

- cd to `build` folder
- Run `cmake -G"generator_name" ..\source\` to generate build files
- Some examples of generators are:
    - `MinGW` generator
        - `cmake -G "MinGW Makefiles" ..\source\`
        - `mingw32-make`
    - `Ninja` generator (need to install `Ninja`)
        - `cmake -G "Ninja" ..\source\`
        - `ninja`
    - Simpler way (THE DEFAULT IS `MinGW`)
        - `cmake ..\source\`
- Run `cmake --build .` to generate executable file 

### Using `CMake` with other compilers

- Generate build files
    - `MinGW` generator
        - `cmake -G"MinGW Makefiles" -D CMAKE_CXX_COMPILER=g++ ..\source\`
		- `cmake -G"MinGW Makefiles" -D CMAKE_CXX_COMPILER=clang++ ..\source\`
    - `Ninja` generator
        - `cmake -GNinja CMAKE_CXX_COMPILER=g++ ..\source\`
		- `cmake -GNinja CMAKE_CXX_COMPILER=clang++ ..\source\`
- `cmake --build .`
- If needed, delete build folder (to use other generators or compilers) using `rm -r ..\build\` or `rm *`

### A note on compilers and generators
- Generators have default compilers:
	- MinGW Makefiles: `gcc` compiler
	- Ninja: `gcc` compiler
- Each generator has a set of compilers which we can change:
	- MinGW Makefiles: `g++` and `clang`
	- Ninja: `g++`, `clang` and `MSVC`
