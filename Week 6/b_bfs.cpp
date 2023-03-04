#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int grid[100][100];
int visited[100][100];
int steps[100][100];
int shortest_path = -1;

int n, m;

queue<pair<int, int> > q1, q2;

const int NUM_DIRS = 4;

int dx[NUM_DIRS] = {0, 0, 1, -1};
int dy[NUM_DIRS] = {1, -1, 0, 0};
// change three things
// 1. check the grid dimension
// 2. check what is possible to flood and what isn't
// 3. check the directions (8, 4)

bool is_possible(int x, int y) {
    // cout << (x >= 0 && y >= 0 && x < n && y < n && visited[x][y] != 1);
    return (x >= 0 && y >= 0 && x < n && y < m && visited[x][y] == 0 &&
            grid[x][y] == 0);
}

void BBFS(int sx, int sy, int ex, int ey) {
    q1.push(make_pair(sx, sy));
    q2.push(make_pair(ex, ey));
    visited[sx][sy] = 1;
    visited[ex][ey] = 2;
    steps[sx][sy] = 1;
    steps[ex][ey] = 1;

    while (!q1.empty() && !q2.empty()) {
        // BFS for start
        // - collect and pop the front from the start queue

        pair<int, int> e1 = q1.front();
        q1.pop();
        int x1 = e1.first;
        int y1 = e1.second;

        // for all neighbors of current point:
        for (int i = 0; i < NUM_DIRS; i++) {
            pair<int, int> point = make_pair(x1 + dx[i], y1 + dy[i]);

            // if the point is possible to visit:
            if (is_possible(point.first, point.second)) {
                // mark the cell as visited
                visited[point.first][point.second] = 1;

                // set neighbours steps to +1
                if (steps[point.first][point.second] == -1)
                    steps[point.first][point.second] = steps[x1][y1] + 1;

                // push the cell to the queue
                q1.push(point);
            } else if (visited[point.first][point.second] == 2) {
                // found the connection
                shortest_path =
                    steps[x1][y1] + steps[point.first][point.second];
                cout << shortest_path;
                exit(1);
            }
        }
    
        pair<int, int> e2 = q2.front();
        q2.pop();
        int x2 = e2.first;
        int y2 = e2.second;

        // for all neighbors of current point:
        for (int i = 0; i < NUM_DIRS; i++) {
            pair<int, int> point = make_pair(x2 + dx[i], y2 + dy[i]);

            // if the point is possible to visit:
            if (is_possible(point.first, point.second)) {
                // mark the cell as visited
                visited[point.first][point.second] = 2;

                // set neighbours steps to +1
                if (steps[point.first][point.second] == -1)
                    steps[point.first][point.second] = steps[x2][y2] + 1;

                // push the cell to the queue
                q2.push(point);
            } else if (visited[point.first][point.second] == 1) {
                // found the connection
                shortest_path =
                    steps[x2][y2] + steps[point.first][point.second];
                cout << shortest_path;
                exit(1);
            }
        }
    }
}

int main() {
    cin >> n;
    m = n;

    int sx = 0;
    int sy = 0;
    int ex = n - 1;
    int ey = n - 1;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            steps[i][j] = -1;
        }
    }

    // BFS(sx, xy);
    BBFS(sx, sy, ex, ey);
    cout << -1;
}