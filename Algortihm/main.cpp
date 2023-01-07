#include<iostream>
#include <unistd.h>
#include<stack>
#include<queue>
using namespace std;

void dfs(int start, int n, int **graph) {
    cout << "dfs start!" << endl;

    stack<int> dfs;
    dfs.push(start);
    bool *d_visit = new bool[n];
    for(int i = 0; i < n; i++) {
        d_visit[i] = false;
    }

    while(!dfs.empty()) {
        int temp = dfs.top();
        cout << temp;
        dfs.pop();
        if(!d_visit[temp-1]) {
            cout << temp;
            d_visit[temp-1] = true;
        }

        for(int k = 0; k < n; k++) {
            if(graph[temp-1][k] == 1) {
                dfs.push(k);
            }
        }

        sleep(2);
    }
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

    dfs(v,n,arr);

    // int *b_visit = new int*[n];
    // queue<int> bfs;



    for(int i = 0; i< n; i++) {
        for(int j = 0; j< n; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }

}