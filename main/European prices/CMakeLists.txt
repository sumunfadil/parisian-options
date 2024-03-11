cmake_minimum_required(VERSION 3.5)

project(FDMApp
    VERSION 1.0
    DESCRIPTION "Description"
    LANGUAGES CXX)

set(Librarypath "C:/Users/SUMUN/OneDrive - London School of Economics/Research/Code/CPP_LSE/parisian-options/lib/source")

# Target
add_executable(FDMApp main.cpp
    ${Librarypath}/src/BlackScholesModel.cpp
    ${Librarypath}/src/Option.cpp
    ${Librarypath}/src/BlackScholesEquation.cpp
    ${Librarypath}/src/FiniteDifferenceMethod.cpp
    ${Librarypath}/src/ExplicitMethod.cpp)

target_compile_features(FDMApp PRIVATE cxx_std_20)

target_include_directories(FDMApp PRIVATE ${Librarypath}/include)