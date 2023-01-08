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