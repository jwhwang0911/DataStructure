/*
    크기 N인 수열 A = A1 .. An
    수열의 각 원소 Ai에 대해 오큰수
    오큰수 : Ai보다 큰 수 중 가장 왼쪽에 있는 수를 의미함 
    오른쪽에 큰수가 없으면 -1
*/

#include<iostream>
#include<stack>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    int *A = new int[N];
    int *NGE = new int[N];

    stack<int> st;
    
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        NGE[i] = -1;
    }

    for(int i = N-1; i >= 0; i--) {
        while( !st.empty() &&  st.top() <= A[i] ) {
            st.pop();
        }

        if(!st.empty()){
            NGE[i] = st.top();
        }
        st.push(A[i]);
    }

    for(int i = 0 ; i < N; i++) {
        cout << NGE[i] << " ";
    }
}