////
////  Created by BK Allen on 3/13/20.
////  Copyright © 2020 BK Allen. All rights reserved.
////
//#include "infixCalc.h"
//#include <algorithm>
//#include <vector>
//
/////
///// \param infixExp
///// \return
//std::string InfixCalc::toPostfix(const std::string &infixExp) {
//    std::string postfix;
//    std::string stackStorage;
//    bool end = false;
//    for (auto character : infixExp) {
//        if (isdigit(character)) {
//            postfix += character;
//        } else if (stackStorage.length() == 0) {
//            stackStorage += character;
//        } else {
//            switch (character) {
//                case '*':
//                case '/': {
//                    char symbol;
//                    while (!end) {
//                        symbol = stackStorage.back();
//                        // End is true if the next operator is an open
//                        // parentheses or an operator of lesser precedence
//                        end = symbol == '(' ||
//                              symbol == '+' ||
//                              symbol == '-' ||
//                              stackStorage.length() == 1;
//                        if (!end) {
//                            // Then we remove the operator from the stack
//                            stackStorage.pop_back();
//                            // And add it to the postfix expression
//                            postfix += symbol;
//                        }
//                    }
//                    // Now we're done and we can add the current operator
//                    // to the operator stack.
//                    stackStorage += character;
//                    break;
//                }
//                case '+':
//                case '-': {
//                    end = false;
//                    char nextOperator = '\0';
//
//                    while (!end) {
//                        // Get the next operator on the stack
//                        nextOperator = stackStorage.back();
//                        end = nextOperator == '(' ||
//                              stackStorage.length() == 1;
//
//                        if (!end) {
//                            // Then we remove the operator from the stack
//                            stackStorage.pop_back();
//                            // And add it to the postfix expression
//                            postfix += nextOperator;
//                        }
//                    }
//                    // Now we're done and we can add the current operator
//                    // to the operator stack.
//                    stackStorage += character;
//                    break;
//                }
//                case '(': {
//                    // Push open parenthesis to stack
//                    stackStorage += character;
//                    break;
//                }
//                case ')': {
//                    // Pop operands to stack until we find a closing parenthesis
//                    while (stackStorage.back() != '(') {
//                        postfix += stackStorage.back();
//                        stackStorage.pop_back();
//                    }
//                    // Pop closing parenthesis off
//                    stackStorage.pop_back();
//                    break;
//                }
//                default:
//                    break;
//            }
//        }
//    }
//
//    // Add remaining operators to postfix expression
//    for (auto it = stackStorage.rbegin(); it != stackStorage.rend(); it++) {
//        postfix += *it;
//    }
//    return postfix;
//}
//
//int InfixCalc::calculation(const std::string &expression) {
//    std::vector<int> stack;
//    int result = 0;
//
//    for (auto ch : expression) {
//        // If we hit a number, push onto stack
//        if (isdigit(ch)) {
//            stack.push_back((int) ch - 48);  // Convert char to int
//        } else {
//            int n1 = 0, n2 = 0;
//
//            // Get operands and pop them from stack
//            n2 = stack.back();
//            stack.pop_back();
//            n1 = stack.back();
//            stack.pop_back();
//
//            switch (ch) {
//                case '+':
//                    result = n1 + n2;
//                    break;
//
//                case '-':
//                    result = n1 - n2;
//                    break;
//
//                case '*':
//                    result = n1 * n2;
//                    break;
//
//                case '/':
//                    result = n1 / n2;
//                    break;
//
//                default:
//                    break;
//            }
//
//            stack.push_back(result);
//        }
//    }
//
//    return result;
//}
