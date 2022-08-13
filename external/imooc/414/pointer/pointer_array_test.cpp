//
// Created by ahogek on 1/3/22.
//

#include <iostream>

using namespace std;

int main() {
    // Pointer to an integer
    int *p;

    // Pointer to an array of 5 integers
    int (*ptr)[5];
    int arr[5] = {1, 2, 3, 4, 5};

    // Points to 0th element of the arr.
    p = arr;

    // Points to the whole array arr.
    ptr = &arr;

    // 因为 p 是指针，所以打印会是指针地址，ptr是一个指针数组，而数组相当于指针也是一个地址，所以打印ptr相当于是指针数组的地址
    cout << "p = " << p << ", ptr = " << ptr << endl;
    cout << "*p = " << *p << ", **ptr = " << **ptr << endl;
    p++;
    ptr++;
    cout << "p = " << p << ", ptr = " << ptr << endl;
    ptr--;
    cout << "*p = " << *p << ", **ptr = " << (*ptr)[1] << endl;
    return 0;
}