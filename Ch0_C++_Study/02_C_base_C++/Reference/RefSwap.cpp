#include<iostream>
using namespace std;

template<typename T>
void RefSwap(T &t1, T &t2) {
    T temp = t1;
    t1 = t2;
    t2 = temp;
}

int main(void) {
    int a = 10;
    int b = 20;
    cout << "before swap (a,b) : " << a << b << endl;
    RefSwap(a,b);
    cout << "after swap (a,b) : " << a << b << endl;
    return 0;
}