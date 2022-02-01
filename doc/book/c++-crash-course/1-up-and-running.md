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

## Bootstrapping C++

### Conditional Statements

```c++
void listing_1_2() {
int x = 0;
std::cout << "42 == x" << (42 == x) << '\n'; // Equality
std::cout << "42 != x" << (42 != x) << '\n'; // Inequality
std::cout << "100 > x" << (100 > x) << '\n'; // greater than
std::cout << "123 >= x" << (123 >= x) << '\n'; //Greater than or equal to
std::cout << "-10 < x" << (-10 < x) << '\n'; // Less than
std::cout << "-99 <= x" << (-99 <= x) << '\n'; // Less than or equal to
}
```
> Listing 1-2: A program using comparison operators

```c++
#include <cstdio>

int main() {
    int x = 0;
    if (x > 0) printf("Positive.");
    else if (x < 0) printf("Negative.");
    else printf("Zero.");
}
```
> Listing 1-4: A program with conditional behavior

Compile and run this program, the result will be 'Zero.'. You can change the x value to print another result.

main is a special function, return statements are optional.

### Functions

#### Example: A Step Function

```c++
int step_function(int x) {
    int result = 0;
    if (x < 0) {
        result = -1;
    } else if (x > 0) {
        result = 1;
    }
    return result;
}
```
> Listing 1-6: A step function that returns ``-1`` for negative value, ``0`` for zero, and ``1`` for positive values

#### Calling Functions

```c++
int main() {
    int value1 = step_function(100); // value1 is 1
    int value2 = step_function(0);   // value2 is 0
    int value3 = step_function(-10)  // value3 is -1
}
```

> Listing 1-7: A program using the ``step_function``. (This program produces no output.)

### printf Format Specifies

#### Revisiting step_function

```c++
#include <cstdio>

int main() {
    int num1 = 42;
    int result1 = step_function(num1);
    
    int num2 = 0;
    int result2 = step_function(num2);
    
    int num3 = -32767;
    int result3 = step_function(num3);
    
    printf("Num1: %d, Step: %d\n", num1, result1);
    printf("Num2: %d, Step: %d\n", num2, result2);
    printf("Num3: %d, Step: %d\n", num3, result3);
}
```

> Listing 1-8: A program that prints the results of applying ``step_function`` to several integers

### Comments

The comments similar to other programming languages, just like ``//`` ``/* */`` ``/** */``

## Debugging

### GCC and Clang Debugging with GDB

```shell
# compile first
gdb gdb_test

# breaking point
(gdb) break main.cpp:5
# or
(gdb) break main

# execution
(gdb) run

# next step and you can use return key to next
(gdb) step

# finish
(gdb) finish

# enter a function
(gdb) next

# view local variables
(gdb) info locals

# continue to next break point
(gdb) continue

# exit gdb
(gdb) quit
```

## EXERCISES

## 1-1

> Create a function called ``absolute_value`` that returns the absolute value of its single argument. The absolute value of
> an integer xis the following: x (itself) if x is greater than or equal to 0; otherwise, it is x times -1. You can use the 
> program in ``Listing 1-9`` as a template:

```c++
int absolute_value(int x) {
    if (x >= 0) return x;
    else return x * -1;
}

void exercise_1_1() {
    int my_num = -10;
    printf("The absolute value of %d is %d. \n", my_num, absolute_value(my_num));
}
```

## 1-4

> Write another function called ``sum`` that takes two int arguments and returns their sum. How can you modify the template
> in Listing 1-9 to test your new function?

```c++
int sum(int a, int b) {
    return a + b;
}

void exercise_1_4() {
    int a = -10, b = 12;
    printf("%d + %d = %d\n", a, b, sum(a, b));
}
```