#include<iostream>
using namespace std;
int main() {
    int n;
    cout << "구구단을 입력하시오: ";
    cin >> n;
    for(int i = 1; i <= 9; i++) {
        cout << n << " x " << i << " = " << n * i << endl;
    }
}