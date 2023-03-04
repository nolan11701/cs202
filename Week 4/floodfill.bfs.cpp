#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int grid[100][100];
int visited[100][100];
int cell_visited = 0;
int n,m;
queue<pair<int, int> > q;
const int NUM_DIRS = 4;

int dx[NUM_DIRS] = {0, 0, 1, -1};
int dy[NUM_DIRS] = {1, -1, 0, 0};
//change three things
//1. check the grid dimension
//2. check what is possible to flood and what isn't
//3. check the directions (8, 4)
//4. if there is an ending point, break the loop when reaches it

bool is_possible(int x, int y) {
    // cout << (x >= 0 && y >= 0 && x < n && y < n && visited[x][y] != 1);
    return (x >= 0 && y >= 0 && x < n && y < m && visited[x][y] != 1);
}

void BFS(int x, int y) {
    // push start position to the queue
    q.push(make_pair(x, y));

    // while queue is not empty:
    while (q.size()) {
        // collect the point at the front + pop front
        pair<int, int> e = q.front();
        q.pop();
        // for all neighbors of current point:
        int x = e.first;
        int y = e.second;
        visited[x][y] = 1;

        cout << x << ", " << y << "\n";

        // if x y are x2y2 (ending point) break

        for (int i = 0; i < NUM_DIRS; i++) {
            pair<int, int> point = make_pair(x + dx[i], y + dy[i]);

            // if the point is possible to visit:
            if (is_possible(point.first, point.second)) {
                // mark the cell as visited
                visited[point.first][point.second] = 1;
                // increment the number of cells visited
                cell_visited++;
                // push the cell to the queue
                q.push(point);
                //cout << "push: " << point.first << ", " << point.second << "\n";
            }
        }
    }
}

int main() {
    n = 5;
    m = 5;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = ++cnt;
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    BFS(0, 0);
    cout << cell_visited;
}