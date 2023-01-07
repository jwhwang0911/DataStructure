#include<iostream>
#include <unistd.h>
#include<stack>
#include<queue>
using namespace std;

// void dfs(int start, int n, int **graph) {
//     int temp;
//     stack<int> dfs;
//     dfs.push(start);
//     bool *d_visit = new bool[n];
//     for(int i = 0; i < n; i++) {
//         d_visit[i] = false;
//     }

//     int cnt = 1;

//     while(!dfs.empty()) {
//         temp = dfs.top();
//         dfs.pop();
//         if(!d_visit[temp-1]) {
//             cout << temp << " ";
//             d_visit[temp-1] = true;
//         }

//         for(int i = n-1; i >= 0; i--) {
//             if(graph[temp-1][i] == 1 && !d_visit[i]) {
//                 dfs.push(i+1);
//             }
//         }
//     }

//     cout << endl;
// }

void dfs(int start, int n, int **graph, bool *visit) {
    cout << start << ' ';
    if(visit[start-1]) {
        return;
    }
    visit[start-1] = true;
    for(int i = 0; i < n; i++) {
        if(graph[start-1][i] == 1 && !visit[i] ) {
            dfs(i+1, n, graph, visit);
        }
    }
}

void bfs(int start, int n, int **graph) {
    int temp;
    queue<int> bfs;
    bfs.push(start);
    bool *d_visit = new bool[n];
    for(int i = 0; i < n; i++) {
        d_visit[i] = false;
    }

    int cnt = 1;

    while(!bfs.empty()) {
        temp = bfs.front();
        bfs.pop();
        if(!d_visit[temp-1]) {
            cout << temp << " ";
            d_visit[temp-1] = true;
        }

        for(int i = 0; i < n; i++) {
            if(graph[temp-1][i] == 1 && !d_visit[i]) {
                bfs.push(i+1);
            }
        }
    }

    cout << endl;
}

int main(void) {
    int n,m,v;
    cin >> n >> m >> v;

    int **arr = new int* [n];

    for(int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }

    int x, y;
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        arr[x-1][y-1] = 1;
        arr[y-1][x-1] = 1;
    }

    bool *visit = new bool[n];

    dfs(v,n,arr , visit);
    cout << endl;
    bfs(v,n,arr);
}