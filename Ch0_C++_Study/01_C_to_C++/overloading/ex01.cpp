#include<iostream>
using namespace std;

template <typename T>
void swap(T *t1, T*t2) {
    T temp = *t1;
    *t1 = *t2;
    *t2 = temp;
}

int main() {

    int num1 = 20;
    int num2 = 30;
    swap(&num1, &num2);
    cout << num1 << " " << num2 << endl;    

    char ch1 = 'A';
    char ch2 = 'Z';
    swap(&ch1, &ch2);
    cout << ch1 << " " << ch2 << endl;

    double db1 = 1.1111;
    double db2 = 2.222222; 
    swap(&db1, &db2);
    cout << db1 << " " << db2 << endl;
}