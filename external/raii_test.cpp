//
// Created by ahogek on 1/6/22.
//

#include <mutex>
#include <iostream>

std::mutex m;

void f() {
    throw std::runtime_error("111");
}

bool everything_ok() {
    std::cout << "ok" << "\n";
    return true;
}

void bad() {
    m.lock();                    // acquire the mutex
    f();                         // if f() throws an exception, the mutex is never released
    if (!everything_ok()) return; // early return, the mutex is never released
    m.unlock();                  // if bad() reaches this statement, the mutex is released
}

void good() {
    std::lock_guard<std::mutex> lk(m); // RAII class: mutex acquisition is initialization
    f();                               // if f() throws an exception, the mutex is released
    if (!everything_ok()) return;       // early return, the mutex is released
}                                      // if good() returns normally, the mutex is released