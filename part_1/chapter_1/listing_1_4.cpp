//
// Created by ahogek on 9/24/21.
//
#include <cstdio>

int a_program_with_conditional_behavior() {
    int x = 0;
    if (x > 0) printf("Positive. ");
    else if (x < 0) printf("Negative. ");
    else printf("Zero. ");
}