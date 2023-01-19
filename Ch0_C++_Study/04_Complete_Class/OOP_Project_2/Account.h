#include<cstring>
#include<iostream>

using namespace std;

class Account {
    private:
        const int ID;
        char *Name;
        int balance;

    public:
        Account(int _ID, char* Name, int _balance = 0) : ID(_ID), balance(_balance) {
            this->Name = new char[strlen(Name) + 1];
            strcpy(this->Name, Name);
        }

        Account(Account &copy) : ID(copy.ID), balance(copy.balance) {
            Name = new char[strlen(Name) + 1];
            strcpy(this->Name, copy.Name);
        }

        void Account_Info() const {
            cout << "계좌 ID : " << ID << endl;
            cout << "이름 : " << Name << endl;
            cout << "잔액 : " << balance << endl;
        }

        const int GetId() const {
           return ID; 
        }

        void Deposit(int money) {
            balance += money;
        }

        void Withdraw(int money) {
            if(balance < money) {
                cout << "출금 금액이 잔액보다 큽니다! 잔액을 확인하세요" << endl;
                return;
            }
            balance -= money;
            return;
        }

        ~Account() {
            delete []Name;
        }

};