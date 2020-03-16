//
//  Created by BK Allen on 3/13/20.
//  Copyright © 2020 BK Allen. All rights reserved.
//
#include "functions.h"
#include "infixCalc.h"
#include "ArrayStack.h"

std::string getExpression(std::string &equation) {
    std::cout << "Please enter an equation: " << std::endl
              << "\x1b[32m> \x1b[0m";
    getline(std::cin, equation);
    return equation;
};

void toConsole(const std::string &infixEquation, const std::string &postfixEquation) {
    std::cout << "Expression: " << infixEquation << std::endl
              << "Postfix form: " << postfixEquation << std::endl
              << "Result: " << calculation(postfixEquation) << std::endl;

}

bool loopProgram() {
    std::cout << "Would you like to process another equation?" << std::endl
              << "> ";
    std::string userInput;
    std::cin >> userInput;
    userInput = makeLowerCase(userInput);
    return userInput == "y" ? true : false;
}

std::string makeLowerCase(const std::string &in) {
    std::string out;
    std::transform(in.begin(), in.end(), std::back_inserter(out), ::tolower);
    return out;
}

void stackMovement(ArrayStack<int> &stack, int &numberOne, int &numberTwo) {
    if (stack.isEmpty())//check stack before peeking to prevent the assertion
        throw std::logic_error("Invalid equation!");
    numberOne = stack.peek();
    stack.pop();
    if (stack.isEmpty())
        throw std::logic_error("Invalid equation!");
    numberTwo = stack.peek();
    stack.pop();
}//used to clean up the code on the switch, makes all the popping and value retention happen



std::string toPostfix(ArrayStack<int> &stack, const std::string &infixExp) {
    std::string postfix;
    std::string stackStorage;
    bool end = false;
    for (auto character : infixExp) {

        if (isdigit(character)) {
            postfix += character;
        } else if (stackStorage.length() == 0) {
            stackStorage += character;
        } else {
            switch (character) {
                case multiplication:
                case division: {
                    char symbol;
                    while (!end) {
                        symbol = stackStorage.back();
                        // End is true if the next operator is an open
                        // parentheses or an operator of lesser precedence
                        end = symbol == leftBracket ||
                              symbol == addition ||
                              symbol == subtraction ||
                              stackStorage.length() == 1;
                        if (!end) {
                            // Then we remove the operator from the stack
                            stackStorage.pop_back();
                            // And add it to the postfix expression
                            postfix += symbol;
                        }
                    }
                    // Now we're done and we can add the current operator
                    // to the operator stack.
                    stackStorage += character;
                    break;
                }
                case addition:
                case subtraction: {
                    end = false;
                    char nextOperator = '\0';

                    while (!end) {
                        // Get the next operator on the stack
                        nextOperator = stackStorage.back();
                        end = nextOperator == '(' ||
                              stackStorage.length() == 1;

                        if (!end) {
                            // Then we remove the operator from the stack
                            stackStorage.pop_back();
                            // And add it to the postfix expression
                            postfix += nextOperator;
                        }
                    }
                    // Now we're done and we can add the current operator
                    // to the operator stack.
                    stackStorage += character;
                    break;
                }
                case leftBracket: {
                    // Push open parenthesis to stack
                    stackStorage += character;
                    break;
                }
                case rightBracket: {
                    // Pop operands to stack until we find a closing parenthesis
                    while (stackStorage.back() != '(') {
                        postfix += stackStorage.back();
                        stackStorage.pop_back();
                    }
                    // Pop closing parenthesis off
                    stackStorage.pop_back();
                    break;
                }
                default:
                    break;
            }
        }
    }
    // Add remaining operators to postfix expression
    for (auto iterator = stackStorage.rbegin(); iterator != stackStorage.rend(); iterator++) {
        postfix += *iterator;
    }
    return postfix;
}

int calculation(const std::string &equation) {
    ArrayStack<int> stack;
    int result = 0;
    for (auto ch : equation) {
        // If we hit a number, push onto stack
        if (isdigit(ch)) {
            stack.push((int) ch - 48);  // Convert char to int
        } else {
            int firstNumber;
            int secondNumber;
            // Get operands and pop them from stack
            secondNumber = stack.peek();
            stack.pop();
            firstNumber = stack.peek();
            stack.pop();
            switch (ch) {
                case addition:
                    result = firstNumber + secondNumber;
                    break;
                case subtraction:
                    result = firstNumber - secondNumber;
                    break;
                case multiplication:
                    result = firstNumber * secondNumber;
                    break;
                case division:
                    result = firstNumber / secondNumber;
                    break;
                default:
                    break;
            }
            stack.push(result);
        }
    }
    return result;
}
