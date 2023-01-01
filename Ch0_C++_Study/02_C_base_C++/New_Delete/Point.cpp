#include<iostream>
using namespace std;

typedef struct __Point {
    int xpos;
    int ypos;
} Point;

Point& PntAdderr(const Point &p1, const Point &p2) {
    Point *t = new Point;
    t->xpos = p1.xpos + p2.xpos;
    t->ypos = p1.ypos + p2.ypos;
    return *t;
}

int main(void) {
    Point *p1 = new Point;
    p1->xpos = 10;
    p1->ypos = 20;

    Point *p2 = new Point;
    p2->xpos = 30;
    p2->ypos = 40;

    Point &p3 = PntAdderr(*p1,*p2);
    cout << p3.xpos << p3.ypos << endl;
}