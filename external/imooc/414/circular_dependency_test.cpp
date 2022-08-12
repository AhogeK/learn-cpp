//
// Created by ahogek on 1/6/22.
//

#include <iostream>
#include <memory> // for std::shared_ptr
#include <string>

class Person {
    std::string m_name;
    std::shared_ptr<Person> m_partner; // initially created empty

public:

    Person(const std::string &name) : m_name(name) {
        std::cout << m_name << " created\n";
    }

    ~Person() {
        std::cout << m_name << " destroyed\n";
    }

    friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2) {
        if (!p1 || !p2)
            return false;

        p1->m_partner = p2;
        p2->m_partner = p1;

        std::cout << p1->m_name << " is now partnered with " << p2->m_name << "\n";

        return true;
    }
};

int main() {
    auto lucy{std::make_shared<Person>("Lucy")}; // create a Person named "Lucy"
    auto ricky{std::make_shared<Person>("Ricky")}; // create a Person named "Ricky"

    partnerUp(lucy, ricky); // Make "Lucy" point to "Ricky" and vice-versa

    return 0;
}