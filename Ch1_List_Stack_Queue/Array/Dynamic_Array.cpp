#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

template <typename T>
class dynamic_array {
	T* data;
	size_t n;

    public:
    // 생성자
        dynamic_array(int num) {
            // n = num;
            this->n = num; //만약 num이 n이었다면 이렇게 구분가능
            data = new T[num]; // T type list만들기, 포인터니까
        }

    // 복사생성자
        dynamic_array(const dynamic_array<T>& other) {
            n = other.n;
            data = new T[n];

            for (int i = 0; i < n; i++) {
                data[i] = other[i];
            } 
        }

        // & ref 리턴은 해당 값을 변경할 수 있게 하고 싶을때
        // 데이터구조 연산자는 이런식으로 operator로써 사용할 수 있음
        T& operator[](int index) {
            return data[index];
        }

        // 뒤의 CONST는 이 함수는 어떠한 멤버 변수도 변경할수 없음을 내포하고 있음. + 함수 내부에서는 오직 const함수만 호출가능
        // 함수 앞의 const는 반환값을 변경하지 못하게할 때 사용됨.
        const T& operator[](int index) const{
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
        const T* begin() const {
            return data;
        }
        T* end() {
            return data+n;
        }
        const T* end() const {
            return data+n;
        }

        friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2)
        {
            dynamic_array<T> result(arr1.size() + arr2.size());
            copy(arr1.begin(), arr1.end(), result.begin());
            copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

            return result;
        } 

        std::string to_string(const std::string& sep = ", ")
        {
            if (n == 0)
                return "";

            std::ostringstream os;
            os << data[0];

            for (int i = 1; i < n; i++)
                os << sep << data[i];

            return os.str();
        }

        ~dynamic_array() {
            delete[] data;
        }
};

struct student
{
	string name;
	int standard;
};

ostream& operator<<(ostream& os, const student& s)
{
	return (os << "[" << s.name << ", " << s.standard << "]");
}

int main()
{
	int nStudents;
	cout << "Number of Class 1 Students : ";
	cin >> nStudents;

	dynamic_array<student> class1(nStudents);
	for (int i = 0; i < nStudents; i++)
	{
		string name;
		int standard;
		cout << i + 1 << "th student name and ages: ";
		cin >> name >> standard;
		class1[i] = student{name, standard};
	}

	// 배열 크기보다 큰 인덱스의 학생에 접근
	try
	{
		// 아래 주석을 해제하면 프로그램이 비정상 종료합니다.
		// class1[nStudents] = student {"John", 8}; // 예상할 수 없는 동작

		class1.at(nStudents) = student{"John", 8}; // 예외 발생
	}
	catch (...)
	{
		cout << "Exception!" << endl;
	}

	// 깊은 복사
	auto class2 = class1;
	cout << "Copy Class 1, Create 2: " << class2.to_string() << endl;

	// 두 학급을 합쳐서 새로운 큰 학급을 생성
	auto class3 = class1 + class2;
	cout << "Class 1 , Class 2 concat | Create 3 : " << class3.to_string() << endl;

	return 0;
}