#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "Point.h"
#include <iostream>

class Circle {
    private:
        Point center;
        int radius;
    public:
        Circle (const int x, const int y, const int r) : center(x,y) {
            radius = r;
        }

        void showCircle() const{
            std::cout << "radius : " << radius << ", center : ";
            center.ShowPointInfor();
        }
};

#endif