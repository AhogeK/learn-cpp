//
// Created by ahogek on 9/24/21.
//
#include <cstdio>
#include <iostream>
#include "listing_1.h"

int step_function(int x) {
    int result = 0;
    if (x < 0) {
        result = -1;
    } else if (x > 0) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

void listing_1_7() {
    int val1 = step_function(100);
    int val2 = step_function(0);
    int val3 = step_function(-100);
    printf("val1: %d, val2: %d, val3: %d\n", val1, val2, val3);
}

/**
 * Conditional Statements
 * Listing 1-2: A program using comparison operators
 */
void listing_1_2() {
    int x = 0;
    std::cout << "42 == x" << (42 == x) << '\n'; // Equality
    std::cout << "42 != x" << (42 != x) << '\n'; // Inequality
    std::cout << "100 > x" << (100 > x) << '\n'; // greater than
    std::cout << "123 >= x" << (123 >= x) << '\n'; //Greater than or equal to
    std::cout << "-10 < x" << (-10 < x) << '\n'; // Less than
    std::cout << "-99 <= x" << (-99 <= x) << '\n'; // Less than or equal to
}

/**
 * Conditional Statements
 * Listing 1-4: A program with conditional behavior
 */
void listing_1_4() {
    int x = 0;
    if (x > 0) printf("Positive.\n");
    else if (x < 0) printf("Negative.\n");
    else printf("Zero.\n");
}

/**
 * A Step Function
 * Listing 1-6:  A step function that returns - 1 for negative values, 0 for zero, and 1 for positive values
 */
int listing_1_6(int x) {
    int result = 0;
    if (x < 0) {
        result = -1;
    } else if (x > 0) {
        result = 1;
    } else {
        result = 1;
    }
    return result;
}

/**
 * Revisiting step_function
 * Listing 1-8: A program that prints the results of applying step_function to several integers
 */
void listing_1_8() {
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