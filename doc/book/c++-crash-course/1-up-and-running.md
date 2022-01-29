# 1 UP AND RUNNING

## The Structure of a Basic C++ Program

### Creating Your First C++ Source File
> try Vim Emacs gedit on Linux or TextEdit on Mac or Notepad on Windows to create your first Hello World!

```c++
# include <cstdio>

int main() {
    printf("Hello, world!");
    return 0;
}
```

*Listing 1-1: Your first C++ program prints ``Hello, world!`` to the screen.*

## The Compiler Tool Chain

1. The preprocessor performs basic source code manipulation.
2. The compiler reads a translation unit and generates an object file.
3. The linker generates programs from object files.

### Setting Up Your Development Environment

just try ``interactive development environment``(IDE)

* Windows 10 and Later: Visual Studio
* Linux and GCC or Clang

Also, you can try Qt Creator, Eclipse CDT, and Jetbrains's CLion. This Book's author highly recommend taking a look at
Jetbrains's Clion.