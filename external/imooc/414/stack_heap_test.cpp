//
// Created by ahogek on 1/6/22.
//

int main() {
    // All these variables get memory
    // allocated on stack
    int a;
    int b[10];
    int n = 20;
    int c[n];

    // This memory for 10 integers
    // is allocated on heap.
    int *ptr = new int[10];
    return 0;
}