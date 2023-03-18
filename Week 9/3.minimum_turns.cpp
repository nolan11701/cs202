#include <iostream>
#include <queue>
using namespace std;
int n, m, a[105][105], cnt[105][105];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Point {
    int row;
    int col;
    int dir;
};
int bfs(Point st, Point ed){
    if (st.row == ed.row && st.col == ed.col){
        return 0;
    }
    queue<Point> q;
    q.push((Point){st.row, st.col, -1});
    cnt[st.row][st.col] = -1;
    
    while (!q.empty()){
        Point pt = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = pt.row + dx[i];
            int y = pt.col + dy[i];
            
            if (x>=1 && x <=n && y>=1 && y<=m && a[x][y] ==0)  {
                int tmp = (i!=pt.dir);
                if (cnt[pt.row][pt.col]+tmp < cnt[x][y]) {
                    cnt[x][y] = cnt[pt.row][pt.col] + tmp;
                    q.push((Point){x, y, i});
                }
            }
        }
    }
    return cnt[ed.row][ed.col];
}
int main(){
    Point st, ed;

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            cnt[i][j] = INT16_MAX;
        }
    }
    cin >> st.row >> st.col >> ed.row >> ed.col;
    cout << bfs(st, ed) << "\n";
    return 0;
}