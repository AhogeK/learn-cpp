//
// Created by ahogek on 1/3/22.
//

#include <iostream>

int main() {
    int high{100};
    int low{66};
    const int *score{&high};
    // Pointer variable are read from
    // the right to left
    std::cout << *score << " via score change ";
    // Score is a pointer to integer
    // which is constant *score = 78
    // Error: *score = 78;
    // It will give you an Error:
    // assignment of read-only location
    // ‘* score’ because value stored in
    // constant cannot be changed
    score = &low;
    // This can be done here as we are
    // changing the location where the
    // score points now it points to low
    std::cout << *score << "\n";

    int numberA{90};
    int numberB{50};
    int *const ptr{&numberA};
    std::cout << *ptr << " ";
    std::cout << ptr << "\n";
    // Address what it points to
    *ptr = 56;
    // Acceptable to change the
    // value of numberA
    // Error: assignment of read-only
    // variable ‘ptr’
    // ptr = &numberB;
    std::cout << *ptr << " ";
    std::cout << ptr << "\n";

    // ptr points to a
    const int *const ptr2{&numberA};
    // *ptr = 90;
    // Error: assignment of read-only
    // location ‘*(const int*)ptr’
    // ptr = &numberB;
    // Error: assignment of read-only
    // variable ‘ptr’
    // Address of a
    std::cout << ptr << " ";
    // Value of a
    std::cout << *ptr << "\n";
}