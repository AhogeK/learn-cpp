//
// Created by ahogek on 1/6/22.
//

#include <cstdio>

int main() {
    int arr[] = {10, 20, 30};
    int *p = arr;
    printf("arr[0] = %d, arr[1] = %d, *p = %d\n",
           arr[0], arr[1], *p);
    // 指针值自增
    ++*p;
    printf("arr[0] = %d, arr[1] = %d, *p = %d\n",
           arr[0], arr[1], *p);
    // 指针地址自增
    *p++;
    printf("arr[0] = %d, arr[1] = %d, *p = %d\n",
           arr[0], arr[1], *p);
    // 指针地址自增
    *++p;
    printf("arr[0] = %d, arr[1] = %d, *p = %d",
           arr[0], arr[1], *p);
    return 0;
}