#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
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

        // & ref 리턴은 해당 값을 변경할 수 있게 하고 싶을때
        // 데이터구조 연산자는 이런식으로 operator로써 사용할 수 있음
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
                return data[index];
            }
            throw "Index out of range";
        }

        size_t size() const {
            return n;
        }

        T* begin() {
            return data;
        }

        T* end() {
            return data+n;
        }

        friend dynamic_array<T> operator+(const dynamic_array<T> &arr1, const dynamic_array<T> &arr2) {
            dynamic_array<T> result(arr1.size() + arr2.size());
            copy(arr1.begin(), arr1.end(), result.begin());
            copy(arr2.begin(), arr2.end(), result.begin()+arr1.size());
            return result;
        }   

        string to_string(const string& sep = ",") {
            if (n==0) {
                return "";
            }
            std::ostringstream os;
            os << data[0];

            for (int i =1; i < n; i++) {
                os << sep << data[i];
            }

            return os.str();
        }

        ~dynamic_array() {
            delete[] data;
        }
};

struct student{
    string name;
    int standard;
};

ostream& operator<< (ostream& os, const student& s) {
    return (os << "[" << s.name << "," << s.standard << "]");
}

int main() {
    int nStudents;
    cout << "1반 학생 수 : ";
    cin >> nStudents;

    dynamic_array<student> class1(nStudents);
    for(int i = 0; i< nStudents; i++) {
        string name;
        int standard;

        cout << i+1 << "번 학생 이름과 나이를 입력하세요 : ";
        cin >> name >> standard;
        class1[i] = student{name,standard};
    }

    try {
        class1.at(nStudents) = student{"John,18"};
    } catch(string err) {
        cout << err << endl;
    }

    auto class2 = class1;
    cout << "copy class1 and create class 2 : " << class2.to_string() << endl;

    auto class3 = class1 + class2;
    cout << "concat class1 and class2 to class3 : " << class3.to_string() << endl;

    return 0;
}