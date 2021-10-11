//
// Created by ahogek on 9/26/21.
//

#ifndef LEARN_CPP_LISTING_2_CUH
#define LEARN_CPP_LISTING_2_CUH

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

struct Book {
    char name[256];
    int year;
    int pages;
    bool hardcover;
};

struct ClockOfTheLongNow {
    void add_year() {
        year++;
    }
    int year;
};

union Variant {
    char string[10];
    int integer;
    double floating_point;
};

void listing_2_1();

void listing_2_2();

void listing_2_3();

void listing_2_4();

void listing_2_5();

void listing_2_6();

void listing_2_7();

void listing_2_8();

void listing_2_9();

void listing_2_10();

void listing_2_12();

void listing_2_15();

void listing_2_16();

void listing_2_18();

void listing_2_19();

#endif //LEARN_CPP_LISTING_2_CUH
