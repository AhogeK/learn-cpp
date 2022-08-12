//
// Created by ahogek on 1/17/22.
//

#include <iostream>

using namespace std;

// Define structure
struct Test {
    int T1;
    char T2;
    float T3;
};

// Declaration of typedef
using TT = struct TestTypedef {
    int TT1;
    char TT2;
    float TT3;
};

// Defining a Union
union TestUnion {
    struct {
        int U1;
        char U2;
        float U3;
    } one;
};

int main() {
    // Declaring a Structure
    struct Test test;
    test.T1 = 1;
    test.T2 = '2';
    test.T3 = 3.3f;

    cout << " T1: " << test.T1 << "\n"
         << " T2: " << test.T2 << "\n"
         << " T3: " << test.T3 << "\n";

    TT tt;
    tt.TT1 = 11;
    tt.TT2 = 'b';
    tt.TT3 = 33.33f;

    cout << " TT1: " << tt.TT1 << "\n"
         << " TT2: " << tt.TT2 << "\n"
         << " TT3: " << tt.TT3 << "\n";

    union TestUnion U1{};
    U1.one.U1 = 64;
    U1.one.U2 = 64;
    U1.one.U3 = 64.64f;
    // Printing values
    cout << U1.one.U1 << "\n";

    cout << U1.one.U2 << "\n";

    cout << U1.one.U3 << "\n";
    return 0;
}