#include<iostream>

int main() {
    int sum =0; 
    int a;
    for(int i = 1; i<=5; i++) {
        std::cin >> a; 
        sum += a;
    }
    std::cout << sum;
}