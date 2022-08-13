//
// Created by ahogek on 1/3/22.
//

#include <iostream>

int main() {
    std::cout << "##################### 内存单元与地址 #######################" << '\n';
    int a = 112;
    float b = 3.14f;
    int *c = &a;
    float *d = &b;
    std::cout << "a = 112 | b = 3.14f | *c = &b | *d = &b" << '\n';
    std::cout << "a " << a << '\n';
    std::cout << "b " << b << '\n';
    std::cout << "c " << c << '\n';
    std::cout << "d " << d << '\n';
    std::cout << "&a " << &a << '\n';
    std::cout << "&b " << &b << '\n';
    std::cout << "&c " << &c << '\n';
    std::cout << "&d " << &d << '\n';
    std::cout << "c[0] " << c[0] << '\n';
    std::cout << "d[0] " << d[0] << '\n';
    std::cout << "*c " << *c << '\n';
    std::cout << "*d " << *d << '\n';
}