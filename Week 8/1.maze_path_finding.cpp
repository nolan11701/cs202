#include <iostream>
#include <stack>
using namespace std;


struct Point {
    int x, y;
    int dir;
};

int n, m, t, sx, sy, fx, fy;
bool maze[6][6]; 
   bool vis[6][6];

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int dfs(){
    vis[sx][sy] = true;
    stack<Point> s;
    s.push((Point){sx, sy, -1});
    int cnt = 0;

    while(s.size()){
        s.top().dir += 1;
        Point p = s.top();

        if (p.x == fx && p.y == fy) {
            cnt++;
            s.pop();
            vis[p.x][p.y] = false;
            continue;
        }

        if (p.dir == 4){
            s.pop();
            vis[p.x][p.y] = false;
            continue;
        }
        
        int row = p.x + dir[p.dir][0];
        int col = p.y + dir[p.dir][1];
        if ( 1 <= row && row <= n && 1 <= col && col <= m && !vis[row][col] && !maze[row][col]){
            vis[row][col] = true;
            s.push((Point){row, col, -1});
        }
    }

    return cnt;
}

int main(){
    int x, y;
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    for (int i = 0; i < t; i++){
        cin >> x >> y;
        maze[x][y] = 1;
    }
    cout << dfs() << "\n";
    return 0;
}