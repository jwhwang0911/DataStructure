#include<iostream>
using namespace std;

int x;
int menu() {
    int check;
    cout << "판매 금액을 만원 단위로 입력 :";
    cin >> check;
    x = check;
    return check;
}
int main() {
    while(1) {
        switch(menu()) {
            case -1:
                cout << "프로그램 종료";
                return -1;
            default:
                cout << "이번달 급여 : " << 50 + x*0.12 << "만원" << endl;
        }
    }
}