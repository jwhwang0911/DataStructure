#include<sstream>
#include<algorithm>
#include<string>

template<typename T>
class Dynamic_Array {
    private:
        size_t n;
        T *data;
    public:
        Dynamic_Array : n(num) (int num) {
            data = new T[n];
        }
};


/*

배열 크기를 인자로 받는 생성자와 복사 생성자
[]로 index 접근
at() 함수  인덱스로 접근
size
소멸자
iterater에 사용하는 

*/