#include<cstring>
#include<iostream>
using namespace std;

int main(void) {
    char *c1 = new char[10];
    char *c2 = new char[20];

    cin >> c1 >> c2;

    cout << strlen(c1) <<endl;
    strcat(c1,c2);
    cout << c1 << endl;
    strcpy(c1,c2);
    cout << c1 <<" " << c2 << endl;
    cout << strcmp(c1, c2) << endl;
}