//
// Created by ahogek on 9/26/21.
//
#include "listing_2.cuh"

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

/**
 * A program printing several floating points
 */
void listing_2_3() {
    double an = 6.0221409e23;
    /* l 代表 double le 科学计数 lf 普通计数 lg 计算机选择最合适的计数方式 */
    printf("Avogaadro's Number: %le %lf %lg\n", an, an, an);
    float hp = 9.75;
    printf("Hogwarts' Platform: %e %f %g\n", hp, hp, hp);
}

/**
 * A program that assigns several character-typed variables and prints them
 */
void listing_2_4() {
    char x = 'M';

    /* 前缀L用于wchar_t类型的字面量 */
    wchar_t y = L'Z';
    /* %lc 指 wchar_t 类型 */
    printf("Windows binaries start with %c%lc.\n", x, y);
}

/**
 * Printing bool variables with a <i>printf<i> statement
 */
void listing_2_5() {
    bool b1 = true; // b1 is true
    bool b2 = false; // b2 is false
    printf("%d %d\n", b1, b2);
}

/**
 * Using comparison operators
 */
void listing_2_6() {
    printf(" 7 == 7: %d\n", 7 == 7);
    printf(" 7 != 7: %d\n", 7 != 7);
    printf("10 > 20: %d\n", 10 > 20);
    printf("10 >= 20: %d\n", 10 >= 20);
    printf("10 < 20: %d\n", 10 < 20);
    printf("20 <= 20: %d\n", 20 <= 20);
}

/**
 * A program that illustrates the use of logical operators
 */
void listing_2_7() {
    bool t = true;
    bool f = false;
    printf("!true: %d=n", !t);
    printf("true && false: %d\n", t && f);
    printf("true && !false: %d\n", t && !f);
    printf("true || false: %d\n", t || f);
    printf("false || false: %d\n", f || f);
}

/**
 * A program that prints the sizes in bytes of several integer types.
 */
void listing_2_8() {
    size_t size_c = sizeof(char);
    printf("char: %zd\n", size_c);
    size_t size_s = sizeof(short);
    printf("short: %zd\n", size_s);
    size_t size_i = sizeof(int);
    printf("int: %zd\n", size_i);
    size_t size_l = sizeof(long);
    printf("long: %zd\n", size_l);
    size_t size_ll = sizeof(long long);
    printf("long long: %zd\n", size_ll);
}

/**
 * A program that indexes into an array
 */
void listing_2_9() {
    int arr[] = {1, 2, 3, 4};
    printf("The third element is %d \n", arr[2]);
    arr[2] = 100;
    printf("The third element is %d. \n", arr[2]);
}

/**
 * Finding hte maximum value contained in an array
 */
void listing_2_10() {
    unsigned long maximum = 0;
    unsigned long values[] = {10, 50, 20 ,40 ,0};
    for (unsigned long value : values) {
        if (value > maximum) maximum = value;
    }
    printf("The maximum value is %lu", maximum);
}

/**
 * Printing the letters of the alphabet in lowercase and uppercase using ASCII
 */
void listing_2_12() {
    char alphabet[27];
    for (int i = 0; i < 26; i++) {
        alphabet[i] = i + 97;
    }
    alphabet[26] = 0;
    printf("%s\n", alphabet);
    for (int i = 0; i < 26; i++) {
        alphabet[i] = i + 65;
    }
    printf("%s\n", alphabet);
}

/**
 * An enumeration class containing all the races from Neal Stephenson's Seveneves
 */
enum class Race {
    Dinan,
    Teklan,
    Ivyn,
    Moiran,
    Camite,
    Julian,
    Aidan
};