#include "Calculator.h"
#include<iostream>

double Calculator::Add(double d1, double d2) {
    add_num++;
    return d1 + d2;
}

double Calculator::Min(double d1, double d2) {
    min_num++;
    return d1 - d2;
}

double Calculator::Mul(double d1, double d2) {
    mul_num++;
    return d1 * d2;
}

double Calculator::Div(double d1, double d2) {
    div_num++;
    return d1 / d2;
}

void Calculator::ShowOpCount() {
    std::cout << " 덧셈 : " << add_num;
    std::cout << " 뺄셈 : " << min_num;
    std::cout << " 곱셈 : " << mul_num;
    std::cout << " 나눗셈 : " << div_num << std::endl;
}