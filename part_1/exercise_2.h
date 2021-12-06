//
// Created by ahogek on 10/31/21.
//

#ifndef LEARN_CPP_EXERCISE_2_H
#define LEARN_CPP_EXERCISE_2_H

enum class Operation {
    Add,
    Subtract,
    Multiply,
    Divide
};

struct Calculator {
    explicit Calculator(Operation op = Operation::Add) {
        this->op = op;
    }

    int calculate(int a, int b) {
        switch (op) {
            case Operation::Add:
                return a + b;
            case Operation::Subtract:
                return a - b;
            case Operation::Multiply:
                return a * b;
            case Operation::Divide:
                return a % b;
        }
        return -1;
    }
private:
    Operation op;
};
#endif //LEARN_CPP_EXERCISE_2_H
