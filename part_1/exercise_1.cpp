//
// Created by ahogek on 9/24/21.
//
#include <cstdio>

int absolute_value(int x) {
    if (x >= 0) return x;
    else return x * -1;
}

void exercise_1_1() {
    int my_num = -10;
    printf("The absolute value of %d is %d. \n", my_num, absolute_value(my_num));
}