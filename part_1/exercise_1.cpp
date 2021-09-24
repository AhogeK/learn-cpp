//
// Created by ahogek on 9/24/21.
//
#include <cstdio>

int absolute_value(int x) {
    if (x >= 0) return x;
    else return x * -1;
}

int sum(int a, int b) {
    return a + b;
}

void exercise_1_1() {
    int my_num = -10;
    printf("The absolute value of %d is %d. \n", my_num, absolute_value(my_num));
}

void exercise_1_4() {
    int a = -10, b = 12;
    printf("%d + %d = %d", a, b, sum(a, b));
}