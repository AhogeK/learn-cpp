//
// Created by Ahoge Knight on 2022/8/12.
//

#include <cstdio>

int absolute_value(int x) {
    if (x >= 0) return x;
    else return x * -1;
}

int main() {
    int myNum = -10;
    printf("The absolute value of %d is %d\n", myNum, absolute_value(myNum));
}