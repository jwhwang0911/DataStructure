#include "Account.h"
#include <iostream>
#define MAX_NAME 20
using namespace std;



enum {
    MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT
};

int check_menu();
void Make_Account();
void Deposit();
void WithDraw();

Account *Aarr[100];
int accNum = 0;

int main(void) {

    while(true) {
        switch(check_menu()) {
            case MAKE:
                Make_Account();
                break;
            case DEPOSIT:
                Deposit();
                break;
            case WITHDRAW:
                WithDraw();
                break;
            case INQUIRE:
                cout << endl << "[모든계좌 정보]" << endl;
                for(int i = 0; i < accNum; i++) {
                    Aarr[i]->Account_Info();
                }
                break;            
            case EXIT:
                cout << endl << "[프로그램 종료]" << endl;
                for(int i = 0; i < accNum; i++) {
                    delete Aarr[i];
                }
                return 0;
            default:
                cerr << "메뉴를 잘못 입력하였습니다. 다시 입력해주세요" << endl;
                break;
        }
    }

    return 0;

}

int check_menu() {
    int temp;

    cout << "------" << "Menu" << "------" << endl;
    cout << "1. 계좌 개설" << endl;
    cout << "2. 입금" << endl;
    cout << "3. 출금" << endl;
    cout << "4. 계좌 정보" << endl;
    cout << "5. 프로그램 종료" << endl;
    cout << endl;
    cout << "선택 : "; cin >> temp;
    
    return temp;
}
void Make_Account() {
    int id;
    char name[MAX_NAME];
    int balance;
    cout << endl << "[계좌 개설]" << endl;
    cout << "계좌 ID : "; cin >> id;
    cout << "이름 : "; cin >> name;
    cout << "입금액 : "; cin >> balance;
    
    Aarr[accNum] = new Account(id,name,balance);
    accNum++;
}
void Deposit() {
    int ID;
    int money;
    cout << endl << "[입금]" << endl;
    cout << "계좌 ID :" ; cin >> ID;
    cout << "입금액 : " ; cin >> money;

    for(int i = 0; i < accNum; i++) {
        if(Aarr[i]->GetId() == ID) {
            Aarr[i]->Deposit(money);
            cout << "입금완료" << endl;
            return;
        }
    }

    cerr << "유효하지 않은 ID 입니다 !" <<endl;
    return;
}
void WithDraw() {
    int ID;
    int money;

    cout << endl << "[출금]" << endl;
    cout << "계좌 ID :" ; cin >> ID;
    cout << "출금액 : " ; cin >> money;

    for(int i = 0; i < accNum; i++) {
        if(Aarr[i]->GetId() == ID) {
            Aarr[i]->Withdraw(money);
            cout << "출금완료" << endl;
            return;
        }
    }

    cerr << "유효하지 않은 ID 입니다 !" <<endl;
    return;
}
