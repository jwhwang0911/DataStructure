#include<iostream>
using namespace std;

int main(void ) {

    int num = 10;
    int i = 0;

    cout << "true : " << true << endl;
    cout << "fasle : " << false << endl;

    while(true) { // 일반적으로 무한루프를 위해서 c에서는 1을 사용함, but true 사용가능
        cout << i++ << ' ';
        if (i > num) {
            break;
        }
    }
    cout << endl;

    cout << "size of 1 : " << sizeof(1) << endl;
    cout << "size of 0 : " << sizeof(0) << endl;
    cout << "size of true : " << sizeof(true) << endl;
    cout << "size of false : " << sizeof(false) << endl;

    return 0;

}