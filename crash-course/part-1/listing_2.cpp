//
// Created by ahogek on 9/26/21.
//
#include "listing_2.h"

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

    /* 前缀L用于wchar_t类型的字面量 wchar_t 代表宽字符 */
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
 * Finding maximum value contained in an array
 */
void listing_2_10() {
    unsigned long maximum = 0;
    unsigned long values[] = {10, 50, 20, 40, 0};
    for (unsigned long value: values) {
        if (value > maximum) maximum = value;
    }
    printf("The maximum value is %lu\n", maximum);
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
 * Listing 2-15: A program that prints a greeting that depends on the race selected
 */
void listing_2_15() {
    Race race = Race::Dinan;

    switch (race) {
        case Race::Dinan: {
            printf("You work hard.\n");
        }
            break;
        case Race::Teklan: {
            printf("You are very strong.\n");
        }
            break;
        case Race::Ivyn: {
            printf("You are a great leader.\n");
        }
            break;
        case Race::Moiran: {
            printf("My, how versatile you are!\n");
        }
            break;
        case Race::Camite: {
            printf("You're incredibly helpful.\n");
        }
            break;
        case Race::Julian: {
            printf("Anything you want!\n");
        }
            break;
        case Race::Aidan: {
            printf("What an enigma.\n");
        }
            break;
        default: {
            printf("Error: unknown race!\n");
        }
    }
}

/**
 * Example using hte POD type Book to read and write members
 */
void listing_2_16() {
    Book neuromancer;
    neuromancer.pages = 271;
    printf("Neuromancer has %d pages.\n", neuromancer.pages);
}

/**
 * A program using the union Variant
 */
void listing_2_18() {
    Variant v;
    v.integer = 42;
    printf("The ultimate answer: %d\n", v.integer);
    v.floating_point = 2.7182818284;
    printf("Euler's number e: %f\n", v.floating_point);
    printf("A dumpster fire: %d\n", v.integer);
}

/**
 * A program using the ClockOfTheLongNow struct
 */
void listing_2_19() {
    ClockOfTheLongNow clock{};
    clock.year = 2017;
    clock.add_year();
    printf("year: %d\n", clock.year);
    clock.add_year();
    printf("year: %d\n", clock.year);
}

/**
 * A program using the ClockOfTheLongNow2 to illustrate the use of methods
 */
void listing_2_21() {
    ClockOfTheLongNow2 clock{};
    if (!clock.set_year(2018)) { // will file; 2018 < 2019
        clock.set_year(2019);
    }
    clock.add_year();
    printf("year: %d", clock.get_year());
}

/**
 * Elaborating ClockOfTheLongNow3 with another constructor
 */
void listing_2_23() {
    ClockOfTheLongNow3 clock{2020};
    printf("Year: %d", clock.get_year());
}

/**
 * A program illustrating various ways to initialize a POD
 */
void listing_2_24() {
    PodStruct initialized_pod1{}; // All fields zeroed;
    PodStruct initialized_pod2 = {}; // All fields zeroed;

    PodStruct initialized_pod3 = {42, "Hello"}; // fields a & b set; c = 0;
    PodStruct initialized_pod4{42, "Hello", true}; // All fields set
}

/**
 * Listing 2-25 illustrates some ways to initialize an array
 */
void listing_2_25() {
    int array_1[]{1, 2, 3}; // Array of length 3; 1, 2, 3
    int array_2[5]{}; // Array of length 5; 0, 0, 0, 0, 0
    int array_3[5]{1, 2, 3}; // Array of length 5; 1, 2, 3, 0, 0
    int array_4[5]; // Array of length 5; uninitialized values
}

void listing_2_27() {
    Taxonomist t1;
    Taxonomist t2{'c'};
    Taxonomist t3{65537};
    Taxonomist t4{6.024e23f};
    Taxonomist t5('g');
    Taxonomist t6 = {'l'};
    Taxonomist t7{};
//    Taxonomist t8();
}