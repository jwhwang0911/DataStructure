#ifndef __RING_H__
#define __RING_H__

#include "Circle.h"
#include<iostream>
#include <cmath>

class Ring {
    private:
        Circle inner, outer;
    public:
        Ring ( const int i_x, const int i_y, const int i_r, const int o_x, const int o_y, const int o_r):
        inner(i_x, i_y, i_r) , outer(o_x, o_y, o_r) {
            if( (pow((i_x - o_x), 2.0) + pow((i_y - o_y), 2.0)) > o_r - o_x ) {
                std::cerr << "inner circle has been invade out of the outer circle" << std::endl;
                exit(-1);
            }
        }

        void ShowInfo() {
            std::cout << "Inner Circle" << std::endl;
            inner.showCircle();
            std::cout << "Outer Circle" << std::endl;
            outer.showCircle();
        } 
};

#endif