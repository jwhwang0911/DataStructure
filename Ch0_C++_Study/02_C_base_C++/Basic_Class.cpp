#include <iostream>

using namespace std;

class FruitSeller
{
private:
    int applePrice;
    int numOfApples;
    int myMoney;
public:
    void InitMembers(int price, int num, int money)
    {
        applePrice = price;
        numOfApples = num;
        myMoney = money;
    }
    int  SaleApples(int money)
    {
        int num = money / applePrice;
        numOfApples -= num;
        myMoney += money;
        return num;
    }
    void ShowSalesResult()
    {
        cout << "남은 사과: " << numOfApples << endl;
        cout << "판매 수익: " << myMoney << endl << endl;
    }
};

class FruitBuyer
{
private:
    int myMoney;
    int numOfApples;
public:
    void InitMembers(int money)
    {
        myMoney = money;
        numOfApples = 0;
    }
    void BuyApples(FruitSeller& seller, int money)
    {
        numOfApples += seller.SaleApples(money);  // 메시지 전달(Message Passing)
        myMoney -= money;
    }
    void ShowBuyResult()
    {
        cout << "현재 잔액: " << myMoney << endl;
        cout << "사과 개수: " << numOfApples << endl << endl;
    }
};


// int main(void)
// {
//     FruitSeller seller;
//     seller.InitMembers(1000, 20, 0);
//     FruitBuyer buyer;
//     buyer.InitMembers(5000);
//     buyer.BuyApples(seller, 2000);

//     cout << "과일 판매자의 현황: " << endl;
//     seller.ShowSalesResult();
//     cout << "과일 구매자의 현황: " << endl;
//     buyer.ShowBuyResult();
// }

/* Use Pointer */

int main(void) {
    FruitSeller *pseller = new FruitSeller;
    pseller->InitMembers(1000,20,0);
    FruitBuyer *pbuyer = new FruitBuyer;
    pbuyer->InitMembers(5000);
    pbuyer->BuyApples(*pseller, 2000);
    cout << "과일 판매자의 현황: " << endl;
    pseller->ShowSalesResult();
    cout << "과일 구매자의 현황: " << endl;
    pbuyer->ShowBuyResult();
}