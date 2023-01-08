/*
    N*N 정사각 보드
    몇칸에는 사과, 보드 상하좌우에는 벽
    뱀은 맨위, 좌측에서 위치, 길이는 1 , 처음에는 오른쪽을 향함

    뱀의 이동규칙
        - 몸길이를 늘려 머리를 다음칸에 위치시킨다
        - 이동한 칸에 사관가 있다면 그 칸에 있던 사과가 없어지고
            꼬리는 움직이지 않는다.
        - 사과가 없다면 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다
            즉 몸길이는 변하지 않는다.

    뱀이 벽 또는 자기자신의 몸과 부딫히면 게임이 끝난다.
*/

#include<iostream>
#include<deque>
using namespace std;

struct Point {
    int x,y;
};

enum {
    L,
    D
};

struct Move {
    int Time;
    int Direction;
};

int main(void) {
    int N, K, L;
    int apple_X, apple_Y;
    int cnt = 0;
    
    cin >> N >> K;

    deque<Point> snake;
    snake.push_back({0,0});

    bool **Map = new bool*[N];
    for(int i = 0 ; i < N; i++) {
        Map[i] = new bool[N];
    }

    for (int i = 0; i < K; i++) {
        cin >> apple_X >> apple_Y;
    }

    cin >> L;
    Move *moves = new Move[L];

    for (int i = 0 ; i < L; i++) {
        char Di;
        cin >> moves->Time >> Di;
        if(Di == 'D') {
            moves->Direction = D;
        } else if( Di == 'L') {
            moves->Direction = L;
        }
    }

    for(int d_info = 0; d_info < L; d_info++) {
        int start = cnt + 1;

        for(int j = start; j < moves[d_info].Time; j++ ) {
            after_x = snake.front().x ;
        }
    }

}