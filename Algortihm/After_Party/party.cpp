#include<iostream>
using namespace std;

int main() {
    int L;
    int P;
    int predict[5];

    cin >> L >> P;
    for(int i = 0; i < 5; i++) {
        cin >> predict[i];
    }

    for (int i = 0; i< 5; i++) {
        cout << predict[i] - P*L << ' ';
    }
}