#include<iostream>
using namespace std;

class FruitSeller{
    private:
        int APPLE_PRICE;
        int numOfApples;
        int myMoney;

    public:
        void InitMembers(int price, int num, int money) {
            APPLE_PRICE = price;
            numOfApples = num;
            myMoney = money;
        }

        int SaleApples (int money) {
            if (money < 0) {
                cerr << "사과를 음수의 금액으로 판매할 수 없습니다!" << endl;
                exit(-1);
            }

            int num = money / APPLE_PRICE;
            numOfApples -= num;
            myMoney += money;
            return num;
        }

        void ShowSalesResult() const{
            cout << "남은 사과 : " << numOfApples << endl;
            cout << "판매 수익 : " << myMoney << endl;
        }
};

class FruitBuyer {
    int myMoney;
    int numOfApples;

    public:
        void InitMembers(int money) {
            myMoney = money;
            numOfApples = 0;
        }

        void BuyApples(FruitSeller &seller, int money) {
            if (money < 0) {
                cerr << "사과를 음수의 금액으로 구매할 수 없습니다!" << endl;
                exit(-1);
            }

            numOfApples += seller.SaleApples(money);
            myMoney -= money;
        }

        void ShowByReulst() const{
            cout << "현재 잔액 : " << myMoney << endl;
            cout << "사과 개수 : " << numOfApples << endl;
        }
};

int main(void) {
    FruitSeller seller;
    seller.InitMembers(1000, 20,0);
    FruitBuyer buyer;
    buyer.InitMembers(5000);
    buyer.BuyApples(seller, -1);

    cout << "과일 판매자의 현황" << endl;
    seller.ShowSalesResult();

    cout << "과일 구매자의 현황" << endl;
    buyer.ShowByReulst();

    return 0;
}

