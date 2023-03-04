#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int grid[401][401];
int visited[401][401];
int steps[401][401];
int x1, y1, x2, y2;

int n, m;

queue<pair<int, int> > q;
const int NUM_DIRS = 8;

int dx[NUM_DIRS] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[NUM_DIRS] = {2, -2, 2, -2, -1, 1, -1, 1};
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
    q.push(make_pair(sx, sy));
    steps[sx][sy] = 0;  // set [0][0] = 1
    // while queue is not empty:
    while (q.size()) {
        // collect the point at the front + pop front
        pair<int, int> e = q.front();
        q.pop();
        // for all neighbors of current point:
        int x = e.first;
        int y = e.second;
        visited[x][y] = 1;

        for (int i = 0; i < NUM_DIRS; i++) {
            pair<int, int> point = make_pair(x + dx[i], y + dy[i]);

            // if the point is possible to visit:
            if (is_possible(point.first, point.second)) {
                // mark the cell as visited
                visited[point.first][point.second] = 1;

                // set neighbours steps to +1
                if (steps[point.first][point.second] == -1)
                    steps[point.first][point.second] = steps[x][y] + 1;

                // push the cell to the queue
                q.push(point);
            }
        }
    }
}
int main() {
    cin >> n >> m >> x1 >> y1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            steps[i][j] = -1;
        }
    }

    BFS(x1-1, y1-1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << steps[i][j] << " ";
        }
        cout << "\n";
    }
}