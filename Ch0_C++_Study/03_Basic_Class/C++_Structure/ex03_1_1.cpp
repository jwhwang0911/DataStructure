#include<iostream>

using namespace std;

struct Point {
    int xpos;
    int ypos;

    void MovePos(int x, int y);
    void AddPoint(const Point &pos);
    void ShowPoistiion() {
        cout << "(x,y) : " << xpos << ',' << ypos << endl;
    } // inline 으로 처리해라라는 뜻
};

void Point::MovePos(int x, int y) {
    xpos += x;
    ypos += y;
}

void Point::AddPoint(const Point &pos) {
    xpos += pos.xpos;
    ypos += pos.ypos;
}

int main(void) {
    Point pos1 = {12,4};
    Point pos2 = {20,30};

    pos1.MovePos(-7,10);
    pos1.ShowPoistiion();

    pos1.AddPoint(pos2);
    pos1.ShowPoistiion();

    return 0;
}