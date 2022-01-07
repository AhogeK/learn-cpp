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