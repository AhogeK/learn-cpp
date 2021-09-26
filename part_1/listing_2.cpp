//
// Created by ahogek on 9/26/21.
//
#include <cstdio>

/**
 * 一个指定一些整型变量利用不同的进制进行打印的程序
 */
void listing_2_1() {
    unsigned short a = 0b10101010;
    printf("%hu\n", a);
    int b = 0123;
    printf("%d\n", b);
    unsigned long long d = 0xFFFFFFFFFFFFFFF;
    printf("%llu\n", d);
}

/**
 * 打印十六进制，十进制，八进制
 */
void listing_2_2() {
    unsigned int a = 3669732608;
    printf("Yabba %x!\n", a);
    unsigned int b = 69;
    printf("There are %u, %o leaves here. \n", b, b);
}