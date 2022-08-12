//
// Created by ahogek on 1/7/22.
//

#include <string>
#include <iostream>

using namespace std;

int main() {
    string food = "Pizza";
    string &meal = food;

    cout << food << "\n";  // Outputs Pizza
    cout << meal << "\n";  // Outputs Pizza
}