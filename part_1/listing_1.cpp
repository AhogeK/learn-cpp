//
// Created by ahogek on 9/24/21.
//
#include <cstdio>

void a_program_with_conditional_behavior() {
    int x = 0;
    if (x > 0) printf("Positive. ");
    else if (x < 0) printf("Negative. ");
    else printf("Zero. ");
}

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
    printf("val1: %d, val2: %d, val3: %d", val1, val2, val3);
}