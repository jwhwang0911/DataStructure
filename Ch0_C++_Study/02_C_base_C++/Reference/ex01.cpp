#include<iostream>
using namespace std;

void increment(int& num) {
    num++;
}

void minus_sign(int& num) {
    num = -num;
}

int main(void) {
    int i = 100;
    cout << "initial num : " << i << endl;
    increment(i);
    cout << "increment num : " << i << endl;
    minus_sign(i);
    cout << "minus sign num : " << i << endl;

}