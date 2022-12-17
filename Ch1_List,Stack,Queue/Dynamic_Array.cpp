#include<string>
#include<algorithm>
#include<iostream>

template <typename T>
class dynamic_array {
    T* data;
    size_t n;

    public:
    // 생성자
        dynamic_array(int num) {
            n = num;
            // this->n = num; 만약 num이 n이었다면 이렇게 구분가능
            data = new T[n]; // T type list만들기, 포인터니까
        }

    // 복사생성자
        dynamic_array(const dynamic_array<T>& other) {
            n = other.n;
            data = new T[n];

            for (int i; i < n; i++) {
                data[i] = other[i];
            } 
        }

        T& operator[] (int index) {
            return data[index];
        }

        // 뒤의 CONST는 이 함수는 어떠한 멤버 변수도 변경할수 없음을 내포하고 있음. + 함수 내부에서는 오직 const함수만 호출가능
        // 함수 앞의 const는 반환값을 변경하지 못하게할 때 사용됨.
        const T& operator[] (int index) const{
            return data[index];
        }

        T& at(int index) {
            if (index < n) {
                if (index < n){
                    
                }
            }
        }
}