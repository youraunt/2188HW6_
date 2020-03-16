//
//  main.cpp
//  2188HW6
//
//  Created by BK Allen on 3/13/20.
//  Copyright © 2020 BK Allen. All rights reserved.
//

#include "infixCalc.h"
#include "functions.h"

using namespace std;

int main() {
    auto again = true;
    ArrayStack<int> arrayStack;
    try {
        do {
            std::cin.exceptions(std::istream::failbit);
            std::ifstream infile;
            std::string infixEquation;
            std::string postfixEquation;
            getExpression(infixEquation);
            postfixEquation = toPostfix(arrayStack, infixEquation);
            toConsole(infixEquation, postfixEquation);
            again = loopProgram();
        } while (again);
    } catch (const std::exception &exc) {
        std::cerr << exc.what() << std::endl;
        unknownInput();
    }
}
