#include <iostream>
#include<string>

using namespace std;

const int max_accounts = 100;
const int account_idx = 0;

enum {
    Make = 1,
    Deposit,
    Withdraw,
    inquire,
    EXIT
};

struct Account {
    string name;
    int id;
    int balance;
};
Account account_list[max_accounts];

int check_menu(void) {
    int menu;
    cout << "-----------Menu-----------" << endl;
    cout << "1. 계좌 개설" << endl;
    cout << "2. 입금" << endl;
    cout << "3. 출금" << endl;
    cout << "4. 계좌 정보" << endl;
    cout << "5. 프로그램 종료" << endl;
    cout << "선택 : ";
    cin >> menu;

    return menu;
}


void make_account() {
    cout << "[계좌 개설]" << endl;
    cout << "계좌 ID : ";
    cin >> account_list[account_idx].id;
    cout << "이름 :";
    cin >> account_list[account_idx].name; 
    cout << "입금액 : ";
    cin >> account_list[account_idx].balance;
}

void deposit() {
    int id;
    int balance;
    int i;
    cout << "[입금]" << endl;
    cout << "계좌 ID : ";
    cin >> id;
    cout << endl;
    for (i = 0; i <= account_idx; i++) {
        if (account_list[i].id == id) {
            break;
        }
    }
    if(i == account_idx+1) {
        cout << "계좌를 만드십시오" << endl;
        return;
    }

    cout << "입금액 : ";
    cin >> balance;
    account_list[i].balance += balance;
    cout << endl;
    cout << "입금완료" << endl;
}

void withdraw() {
    int id;
    int balance;
    int i;
    cout << "[출금]" << endl;
    cout << "계좌 ID : ";
    cin >> id;
    cout << endl;
    for (i = 0; i <= account_idx; i++) {
        if (account_list[i].id == id) {
            break;
        }
    }
    if(i == account_idx+1) {
        cout << "계좌를 만드십시오" << endl;
        return;
    }

    cout << "출금액 : ";
    cin >> balance;
    account_list[i].balance -= balance;
    cout << endl;
    cout << "출금완료" << endl;
}

void info() {
    cout << "[모든 계좌 정보]" << endl;
    for(int i = 0; i <= account_idx; i++) {
        cout << "계좌 ID :" << account_list[i].id << endl;
        cout << "이름 : " << account_list[i].name << endl;
        cout << "잔액 : " << account_list[i].balance << endl;
    }
}

int main(void) {
    while(1) {
        switch (check_menu())
        {
            case Make:
                make_account();
                break;
            case Deposit:
                deposit();
                break;
            case Withdraw:
                withdraw();
                break;
            case inquire:
                info();
                break;
            case EXIT:
                return 0;
            default:
                cout << "메뉴 안에서 고르시오!" << endl;
                break;
        }
    }
}