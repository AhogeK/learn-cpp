//
// Created by ahogek on 1/3/22.
//

#include <cstdio>

int main() {
    int variable = 789;
    // pointer for variable
    int *pointer2;
    // double pointer for ptr2
    int **pointer1;
    // storing address of var in ptr2
    pointer2 = &variable;
    // Storing address of ptr2 in ptr1
    pointer1 = &pointer2;
    // Displaying value of var using
    // both single and double pointers
    printf("Value of var = %d\n", variable);
    printf("Value of var using single pointer = %d\n", *pointer2);
    printf("Value of var using double pointer = %d\n", **pointer1);
    return 0;
}