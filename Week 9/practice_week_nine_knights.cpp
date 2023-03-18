#include <iostream>
#include <queue>

using namespace std;

struct Point {
    int row;
    int col;
};

int n;
int vis[300][300];  // visited and store step
Point st, ed;

// index 0~7 for move
int dr[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dc[8] = {2, 1, -1, -2, -2, -1, 1, 2};

bool is_possible(int x, int y) {
    // cout << (x >= 0 && y >= 0 && x < n && y < n && visited[x][y] != 1);
    return (x >= 0 && y >= 0 && x < n && y < n && vis[x][y] == -1);
}
int bfs() {
    // Initialization
    queue<Point> q;
    q.push(st);

    // memset(vis, -1, sizeof vis);
    for (int i = 0; i < 300; i++) {
        for (int j = 0; j < 300; j++){
            vis[i][j] = -1;
        }
    }

    vis[st.row][st.col] = 0;
    int ans = -1;

    // Search
    while (q.size()) {
        // collect the point at the front + pop front
        Point e = q.front();
        q.pop();
        // for all neighbors of current point:
        int x = e.col;
        int y = e.row;
        if (x == ed.col && y == ed.row) {
            ans = vis[x][y];
            return ans;
        }
        for (int i = 0; i < 8; i++) {
            Point point = {x + dc[i], y + dr[i]};

            // if the point is possible to visit:
            if (is_possible(point.col, point.row)) {
                // mark the cell as visited
                vis[point.col][point.row] = vis[x][y] + 1;

                // push the cell to the queue
                q.push(point);
            }
        }
    }

    return ans;
}

int main() {
    // Input
    cin >> n;
    cin >> st.row >> st.col;
    cin >> ed.row >> ed.col;

    // Search and Output
    cout << bfs();
}