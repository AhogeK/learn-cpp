//
// Created by ahogek on 1/6/22.
//

int global; /* Uninitialized variable stored in bss*/
int global2 = 10; /* initialized global variable stored in DS*/

int main() {
    static int i; /* Uninitialized static variable stored in bss */
    static int j = 100; /* Initialized static variable stored in DS*/
    return 0;
}