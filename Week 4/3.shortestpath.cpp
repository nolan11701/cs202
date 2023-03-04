#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int grid[100][100];
int visited[100][100];
int steps[100][100];
int x1, y1, x2, y2;

int n, m;

queue<pair<int, int> > q;
const int NUM_DIRS = 4;

int dx[NUM_DIRS] = {0, 0, 1, -1};
int dy[NUM_DIRS] = {1, -1, 0, 0};
// change three things
// 1. check the grid dimension
// 2. check what is possible to flood and what isn't
// 3. check the directions (8, 4)

bool is_possible(int x, int y) {
    // cout << (x >= 0 && y >= 0 && x < n && y < n && visited[x][y] != 1);
    return (x >= 0 && y >= 0 && x < n && y < m && visited[x][y] != 1 &&
            grid[x][y] == 0);
}

void BFS(int sx, int sy) {
    // push start position to the queue
    q.push(make_pair(sx, sy)); // {sx, sy}
    steps[sx][sy] = 1;  // set [0][0] = 1
    visited[sx][sy] = 1;
    // while queue is not empty:
    while (q.size()) {
        // collect the point at the front + pop front
        pair<int, int> e = q.front();
        q.pop();
        // for all neighbors of current point:
        int x = e.first;
        int y = e.second;

        // cout << x << ", " << y << "\n";

        for (int i = 0; i < NUM_DIRS; i++) {
            pair<int, int> point = make_pair(x + dx[i], y + dy[i]);

            // if the point is possible to visit:
            if (is_possible(point.first, point.second)) {
                // mark the cell as visited
                visited[point.first][point.second] = 1;

                // set neighbours steps to +1
                if (steps[point.first][point.second] == 0)
                    steps[point.first][point.second] = steps[x][y] + 1;

                // push the cell to the queue
                q.push(point);
            }
        }
    }
}
int main() {
    // starting point x1 y1
    // ending point x2 y2
    // create steps[100][100]
    // while looping neighbors
    // if stpes[f][s] == 0 mark steps[f][s] = steps[x][y] +1
    // output steps[x2][y2]
    cin >> n;
    m = n;

    x1 = 0;
    y1 = 0;
    x2 = n - 1;
    y2 = n - 1;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    BFS(x1, y1);
    if (steps[x2][y2] != 0) {
        cout << steps[x2][y2];
    } else {
        cout << "-1";
    }
}