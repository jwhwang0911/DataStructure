// #include<iostream>

// namespace Company1
// {
//     void test(void) {
//         std::cout << "Compnay1이 정의한 함수" << std::endl;
//     }
// }

// namespace Company2
// {
//     void test(void) {
//         std::cout << "Company2가 정의한 함수" << std::endl;
//     }
// }

// int main(void) {
//     Company1::test();
//     Company2::test();

// //     Compnay1이 정의한 함수
// //     Company2가 정의한 함수

//     return 0;
// }

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// #include <iostream>

// using namespace std;

// namespace AAA
// {
//     namespace BBB
//     {
//         namespace CCC
//         {
//             int num1;
//             int num2;
//         }
//     }
// }

// int main(void)
// {
//     AAA::BBB::CCC::num1 = 20;
//     AAA::BBB::CCC::num2 = 30;

//     namespace ABC = AAA::BBB::CCC;

//     cout << ABC::num1 << endl;
//     cout << ABC::num2 << endl;

// // 20
// // 30

//     return 0;
// }

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// #include <iostream>

// using namespace std;

// int val = 100;

// int main(void)
// {
//     int val = 20; // 지역 변수
//     val += 3;  // 지역 변수 val의 값 증가
//     ::val += 3; // 전역변수 val의 값 증가

//     cout << "지역변수 val의 값: " << val << endl;
//     cout << "전역변수 val의 값: " << ::val << endl;

//     // 지역변수 val의 값: 23
//     // 전역변수 val의 값: 103  

//     return 0;
// }