//
// Created by ahogek on 1/6/22.
//

#include <memory>
#include <iostream>

int main() {
    std::auto_ptr<int> p1(new int);
    *p1.get() = 10;

    std::auto_ptr<int> p2(p1);

    std::cout << "p2 points to " << *p2 << '\n';
    // (p1 is now null-pointer auto_ptr)
    // std::cout << "p1 " << *p1 << '\n';
    return 0;
}