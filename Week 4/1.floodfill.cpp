#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int grid[100][100];
int visited[100][100];
int cell_visited = 0;
int n;
queue<pair<int, int> > q;

int dx[4] = {1, -1, 1, -1};
int dy[4] = {0, 0, 1, -1};

bool is_possible(int x, int y) {
    // cout << (x >= 0 && y >= 0 && x < n && y < n && visited[x][y] != 1);
    return (x >= 0 && y >= 0 && x < n && y < n && visited[x][y] != 1 && grid[x][y]!= 1);
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

        // cout << x << ", " << y << "\n";

        for (int i = 0; i < 4; i++) {
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
    int x, y;
    cin >> n >> x >> y;
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

    BFS(x, y);
    cout << cell_visited + 1;
}