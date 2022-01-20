//
// Created by ahogek on 1/19/22.
//

#include <cstdio>

// Alignment requirements
// (typical 32 bit machine)

// char         1 byte
// short int    2 bytes
// int          4 bytes
// double       8 bytes

// structure A

using structa_t = struct structa_tag {
    char c;
    short int s;
};

// structure B
using structb_t = struct structb_tag {
    short int s;
    char c;
    int i;
};

// structure C
using structc_t = struct structc_tag {
    char c;
    double d;
    int s;
};

// structure D
using structd_t = struct structd_tag {
    double d;
    int s;
    char c;
};

int main() {
    printf("sizeof(structa_t) = %lu\n", sizeof(structa_t));
    printf("sizeof(structb_t) = %lu\n", sizeof(structb_t));
    printf("sizeof(structc_t) = %lu\n", sizeof(structc_t));
    printf("sizeof(structd_t) = %lu\n", sizeof(structd_t));

    return 0;
}