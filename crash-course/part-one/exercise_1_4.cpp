//
// Created by Ahoge Knight on 2022/8/12.
//

#include <cstdio>

int sum(int a, int b) {
    return a + b;
}

int main() {
    int a = 13;
    int b = 36;
    printf("%d + %d = %d\n", a, b, sum(a, b));
}