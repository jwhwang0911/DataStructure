#include "NameCard.h"

int main(void) {
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manASSIST("Kim", "SoGoodComp", "010-5678-9876", COMP_POS::ASSIST);
    NameCard *manMANAGER = new NameCard("Jang", "BestComp", "010-1213-1234", COMP_POS::MANAGER);

    manClerk.ShowNameCardInfo();
    manSENIOR.ShowNameCardInfo();
    manASSIST.ShowNameCardInfo();
    manMANAGER->ShowNameCardInfo();

    return 0;
}