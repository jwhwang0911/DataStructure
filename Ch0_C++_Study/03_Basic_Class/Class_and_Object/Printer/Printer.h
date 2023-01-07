#include<iostream>
#include<string>
class Printer{
    private:   
        std::string str;
    public:
        void SetString(std::string par) {
            str = par;
        }

        void ShowString() {
            std::cout << str << std::endl;
        }
};