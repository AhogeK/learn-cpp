//
// Created by ahogek on 1/3/22.
//

#include <cstdio>

int main() {
    int some = 20;
    int *iptr = &some;  /* iptr initialized with address of 'some' */
    printf("\nAddress of integer \'some\' in exp. \'int some = 20\' is %p\n"
           "and where \'iptr\' is pointing to, in exp. 'int *iptr = &some',"
           " is\n%p\n", &some, iptr);
    printf("\nLet's see what happens when we access initialized pointer "
           "\'ptr\' in exp.\n\'int *iptr = &some\'\n");
    printf("This gives Value %d of variable \'some\'\n\n", *iptr);

    int *ip1;   /* ip1 declared pointer-to-integer, but not initialized */
    int *ip2;   /* ip2 declared pointer-to-integer, but not initialized */
    char *cp;   /* cp declared pointer-to-character, but not initialized */
    float *fp;  /* fp declared pointer-to-float, but not initialized */
    printf("Default Address \'ip1\' holds as %p\n", ip1);
    printf("Default Address \'ip2\' holds as %p\n", ip2);
    printf("Default Address \'cp\' holds as %p\n", cp);
    printf("Default Address \'fp\' holds as %p\n", fp);
    printf("\nNow, see, what happens when we access uninitialized pointers"
           "...\n");
    printf("%d %d %c %f\n", *ip1, *ip2, *cp, *fp);
    return 0;
}