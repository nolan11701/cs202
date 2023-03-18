#include <iostream>
#include <queue>
using namespace std;
int m, n, A, B;
struct Point {
    int row;
    int col;
};
Point src[100000], dst[100000];
int vis[600][600];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(){
    queue<Point> que;
    for (int i = 0; i < A; i++){
        vis[src[i].row][src[i].col] = 0;
        que.push(src[i]);
    }
    while (que.size()){
        Point pt = que.front();
        que.pop();
        for (int k = 0; k < 4; k++){
            int tx = pt.row + dx[k];
            int ty = pt.col + dy[k];
            if (tx >= 1 && tx <= n && ty >= 1 && ty <=m && vis[tx][ty] < 0) {
                vis[tx][ty] = vis[pt.row][pt.col] + 1;
                que.push((Point){tx, ty});        
                
            }
        }
    }
}
int main(){
    int r, c;
    scanf("%d%d%d%d" , &n, &m, &A, &B);
    for (int i = 0; i < A; i++){
        scanf("%d%d" , &src[i].row, &src[i].col);
    }
    for (int i = 0; i < B; i++){
        scanf("%d%d" , &r, &c);
        dst[i] = (Point){r, c};
    }
    for (int i = 0; i < 600; i++){
        for (int j = 0; j < 600; j++){
            vis[i][j] = -1;
        }
    }
    
    bfs();
    for (int i = 0; i < B; i++){
        printf("%d\n" , vis[dst[i].row][dst[i].col]);
    }
    return 0;

}