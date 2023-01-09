#ifndef __POINT_H__
#define __POINT_H__

#include<iostream>

class Point {
    private:
        int x;
        int y;
    public:
        Point (const int xpos, const int ypos) : x(xpos), y(ypos) { }
        void ShowPointInfor() const {
            std::cout << "(" << x << ", " << y << ")" << std::endl;
        }
};

#endif