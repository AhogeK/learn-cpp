//
// Created by ahogek on 9/26/21.
//

#ifndef LEARN_CPP_LISTING_2_H
#define LEARN_CPP_LISTING_2_H

#include <cstdint>
#include <cstddef>
#include <cstdio>

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

/**
 * Listing 2-20: An updated ClockOfTheLongNow from Listing 2-19 that encapsulates year
 */
struct ClockOfTheLongNow2 {
    void add_year() {
        year++;
    }

    bool set_year(int new_year) {
        if (new_year < 2019) return false;
        year = new_year;
        return true;
    }

    int get_year() {
        return year;
    }

private:
    int year;
};

struct ClockOfTheLongNow3 {
    ClockOfTheLongNow3(int year_in) {
        if (!set_year(year_in)) {
            year = 2019;
        }
    }

    void add_year() {
        year++;
    }

    bool set_year(int new_year) {
        if (new_year < 2019) return false;
        year = new_year;
        return true;
    }

    int get_year() {
        return year;
    }

private:
    int year;
};

struct PodStruct {
    uint64_t a;
    char b[256];
    bool c;
};

/**
 * A class announcing witch of its several constructors gets called during initialization
 */
struct Taxonomist {
    Taxonomist() {
        printf("(no argument)\n");
    }

    Taxonomist(char x) {
        printf("char: %c\n", x);
    }

    Taxonomist(int x) {
        printf("int: %d\n", x);
    }

    Taxonomist(float x) {
        printf("float: %f\n", x);
    }
};

class ClockOfTheLongNowClass {
    int year;
public:
    void add_year() {
        year++;
    }

    bool set_year(int new_year) {
        if (new_year < 2019) return false;
        year = new_year;
        return true;
    }

    int get_year() {
        return year;
    }
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

void listing_2_21();

void listing_2_23();

void listing_2_24();

void listing_2_25();

void listing_2_27();

#endif //LEARN_CPP_LISTING_2_H
