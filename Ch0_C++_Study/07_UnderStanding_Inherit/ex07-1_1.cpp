#include<iostream>
using namespace std;

class Car {
    private:
        int gasolineGauge;
    public:
        Car(int gasol) : gasolineGauge(gasol) {
            cout << "차 생성자 호출" << endl;
        }

        int GetGasGauge() {
            return gasolineGauge;
        }

        ~Car() {
            cout << "차 소멸자" << endl;
        }
};

class HybridCar : public Car {
    private:
        int electricGauge;
    public :
        HybridCar(int Electric, int gasol) : Car(gasol), electricGauge(Electric) {
            cout << "하이브리드 생성잔" << endl;
        }

        int GetElectricGauge() {
            return electricGauge;
        }

        ~HybridCar() {
            cout << "하이브리드 소멸자" <<endl;
        }
};

class HybridWaterCar: public HybridCar {
    private:
        int waterGauge;
    public:
        HybridWaterCar(int water, int Electric, int gasol) : HybridCar(Electric = Electric, gasol = gasol), waterGauge(water) {
            cout << "물하이브리드 생성자" << endl;
        }

        int GetWaterGauge() {
            return waterGauge;
        }

        void ShowCurrentGauge() {
            cout << "잔여 가솔린 " << GetGasGauge() << endl;
            cout << "잔여 전기" << GetElectricGauge() << endl;
            cout << "잔여 물" << GetWaterGauge() << endl;
        }

        ~HybridWaterCar() {
            cout << "물 하이브리드 소멸자" << endl;
        }
};

int main (void) {
    HybridWaterCar t(5,5,5);

    t.ShowCurrentGauge();

    return 0;
}