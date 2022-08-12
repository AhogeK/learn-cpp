//
// Created by ahogek on 1/6/22.
//

#include <memory>
#include <iostream>

struct C {
    int *data;
};

int main() {
    std::shared_ptr<int> p1;
    std::shared_ptr<int> p2(nullptr);
    std::shared_ptr<int> p3(new int);
    std::shared_ptr<int> p4(new int, std::default_delete<int>());
    std::shared_ptr<int> p5(new int, [](int *p) { delete p; }, std::allocator<int>());
    std::shared_ptr<int> p6(p5);
    std::shared_ptr<int> p7(std::move(p6));
    std::shared_ptr<int> p8(std::unique_ptr<int>(new int));
    std::shared_ptr<C> obj(new C);
    std::shared_ptr<int> p9(obj, obj->data);

    std::cout << "use_count:\n";
    std::cout << "p1: " << p1.use_count() << '\n';
    std::cout << "p2: " << p2.use_count() << '\n';
    std::cout << "p3: " << p3.use_count() << '\n';
    std::cout << "p4: " << p4.use_count() << '\n';
    std::cout << "p5: " << p5.use_count() << '\n';
    std::cout << "p6: " << p6.use_count() << '\n';
    std::cout << "p7: " << p7.use_count() << '\n';
    std::cout << "p8: " << p8.use_count() << '\n';
    std::cout << "p9: " << p9.use_count() << '\n';

    auto deleter = [](int *p) {
        std::cout << "[deleter called]\n";
        delete p;
    };

    std::shared_ptr<int> foo(new int, deleter);
    std::shared_ptr<int> bar(new int(10));

    std::cout << "use_count: " << foo.use_count() << '\n';

    foo = bar;                          // copy

    bar = std::make_shared<int>(20);   // move

    std::unique_ptr<int> unique(new int(30));
    foo = std::move(unique);            // move from unique_ptr

    std::cout << "*foo: " << *foo << '\n';
    std::cout << "*bar: " << *bar << '\n';

    foo.swap(bar);

    std::cout << "*foo: " << *foo << '\n';
    std::cout << "*bar: " << *bar << '\n';

    std::shared_ptr<int> sp;  // empty

    sp.reset(new int);       // takes ownership of pointer
    *sp = 10;
    std::cout << "*sp: " << *sp << '\n';

    sp.reset(new int);       // deletes managed object, acquires new pointer
    *sp = 20;
    std::cout << "*sp: " << *sp << '\n';

    sp.reset();               // deletes managed object

    int *p = new int(10);
    std::shared_ptr<int> a(p);

    if (a.get() == p)
        std::cout << "a and p point to the same location\n";

    // three ways of accessing the same address:
    std::cout << "*a.get(): " << *a.get() << "\n";
    std::cout << "*a: " << *a << "\n";
    std::cout << "*p: " << *p << "\n";

    return 0; // [deleter called]
}