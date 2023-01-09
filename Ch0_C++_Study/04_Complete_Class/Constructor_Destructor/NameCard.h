#ifndef __NAMECARD_H__
#define __NAMECARD_H__

#include<iostream>
#include<cstring>
#include "NameCard.h"

using namespace std;

class NameCard {
    private:
        char * name;
        char * company;
        char * phone_num;
        int comp_pos;
    public:
        NameCard(char * _name, char *_company, char * phone_num, int _comp_pos);
        void ShowNameCardInfo() ;
        ~NameCard();
};

namespace COMP_POS {
    enum {
        CLERK,
        SENIOR,
        ASSIST,
        MANAGER
    };

    void show_info(int x) {
        switch(x) {
            case CLERK :
                cout << "사원" << endl;
                break;
            case SENIOR :
                cout << "주임" << endl;
                break;
            case ASSIST:
                cout << "대리" << endl;
                break;
            case MANAGER :
                cout << "과장" << endl;
                break;
            default:
                cerr << "사용자의 직급이 불분명합니다!" << endl;
                break;
        }
    }
};

NameCard::NameCard(char * _name, char *_company, char * _phone_num, int _comp_pos)
: comp_pos(_comp_pos)
{
    name = new char[strlen(_name + 1)];
    company = new char[strlen(_company + 1)];
    phone_num = new char[strlen(_phone_num + 1)];\
    strcpy(name, _name);
    strcpy(company, _company);
    strcpy(phone_num, _phone_num);
}

void NameCard::ShowNameCardInfo() {
    cout << "이름 : " << name << endl;
    cout << "회사 : " << company << endl;
    cout << "전화번호 : " << phone_num << endl;
    cout << "직급 : " ;
    COMP_POS::show_info(comp_pos);
}

NameCard::~NameCard() {
    delete []name;
    delete []company;
    delete []phone_num;
}

#endif