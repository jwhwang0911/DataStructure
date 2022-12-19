// C에서의 문제점
/*
    1. 메모리의 직접 할당 및 해제
    2. 배열 크기보다 큰 원소를 참조 X
    3. 중첩배열이 복잡
    4. 깊은 복사 작동 X. 수동으로 함수제작해야함.
*/

#include<iostream>
#include<array>
using namespace std;

// 매개변수로 크기 지정해서 초기화
void print(array<int,5> arr) {
    // auto 는 type 유추해줌
    for (auto ele : arr) {
        cout << ele << ",";
    }
    cout << endl;
}

// Template은 함수의 타입이 모호할때 사용가능
template<size_t N>
void print_2(array<int, N> arr) {
    for(auto it = arr.begin(); it != arr.end(); it++) {
        auto ele = *it;
        cout << ele << " ";
    }
    cout << endl;
}

int main() {
    array<int, 5> arr = {1,2,3,4,5};
    print_2(arr);

    //에러처리코드
    try{
        cout << arr.at(6);
    }
    catch(const out_of_range &ex) {
        cerr << ex.what() << endl;
    }
}