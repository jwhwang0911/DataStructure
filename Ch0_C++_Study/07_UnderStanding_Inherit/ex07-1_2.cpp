#include<iostream>
#include<cstring>
using namespace std;

class MyFriednInfo {
    private:
        char *name;
        int age;
    public:
        MyFriednInfo(char *name, int age) : age(age) {
            this->name = new char[strlen(name)+1];
            strcpy(this->name, name);
        }

        void ShowMyFriendInfo() {
            cout << "이름 : " << name << endl;
            cout << "나이 : " << age << endl;
        }

        ~MyFriednInfo() {
            delete[] name;
        }
};

class MyFriendDetail : public MyFriednInfo {
    private:
        char *addr;
        char *phone;

    public:
        MyFriendDetail(char *addr, char *phone, char*name, int age) : MyFriednInfo(name, age) {
            this->addr = new char[strlen(addr) + 1];
            this->phone = new char[strlen(phone) + 1];
            strcpy(this->addr, addr);
            strcpy(this->phone, phone);
        }

        void ShowMyFriendDetail() {
            ShowMyFriendInfo();
            cout << "주소 " << addr << endl;
            cout << "전화 " << phone << endl;
        }

        ~MyFriendDetail() {
            delete[] addr;
            delete[] phone;
        }
};

int main() {
    MyFriendDetail t("경기도", "010-1234-5678", "김아무개", 15);
    t.ShowMyFriendDetail();
}