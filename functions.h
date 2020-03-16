//
//  Created by BK Allen on 3/13/20.
//  Copyright © 2020 BK Allen. All rights reserved.
//

#ifndef INC_2188HW6_FUNCTIONS_H
#define INC_2188HW6_FUNCTIONS_H

#include <cstdio>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "ArrayStack.h"

enum arithmeticSymbols {
    multiplication = '*',
    division = '/',
    addition = '+',
    subtraction = '-',
    space = ' ',
    leftBracket = '(',
    rightBracket = ')'
};
std::string getExpression(std::string &equation);



void toConsole(const std::string&, const std::string&);
/// @brief Exits program successfully with message
inline std::string exitProgram() {
    std::cout << "Exiting program!" << std::endl;
    /// @brief I used EXIT_SUCCESS here to unwind the stack
    exit(EXIT_SUCCESS);
}

std::string makeLowerCase(const std::string &infile);

inline void unknownInput() {
    std::cerr << "\nError?! Unknown input.\n" << std::endl;
    exitProgram();
}
 bool loopProgram();
std::string toPostfix(ArrayStack<int> &stack,const std::string &infixExp);
int calculation(const std::string &equation);
#endif //INC_2188HW6_FUNCTIONS_H
