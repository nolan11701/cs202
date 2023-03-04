#include <iostream>
#include <queue>
#include <utility>
using namespace std;

// define glabal variables
char grid[1001][1001];
int visited[1001][1001];

int n, m;

queue<pair<int, int> > q;

const int NUM_DIRS = 4;
int dx[NUM_DIRS] = {0, 0, 1, -1};
int dy[NUM_DIRS] = {1, -1, 0, 0};

int min_x, min_y, max_x, max_y;

bool is_possible(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m && visited[x][y] != 1 &&
            grid[x][y] == '#');
}

void BFS(int sx, int sy) {
    min_x = max_x = sx;
    min_y = max_y = sy;
    // push start position to the queue
    q.push(make_pair(sx, sy));

    // while queue is not empty:
    while (q.size()) {
        // collect the point at the front + pop front
        pair<int, int> e = q.front();
        q.pop();
        int x = e.first;
        int y = e.second;
        visited[x][y] = 1;

        // for all neighbors of current point:
        for (int i = 0; i < NUM_DIRS; i++) {
            pair<int, int> point = make_pair(x + dx[i], y + dy[i]);

            // if the point is possible to visit:
            if (is_possible(point.first, point.second)) {
                // mark the cell as visited
                visited[point.first][point.second] = 1;

                min_x = min(min_x, point.first);
                min_y = min(min_y, point.second);
                max_x = max(max_x, point.first);
                max_y = max(max_y, point.second);

                // push the cell to the queue
                q.push(point);
            }
        }
    }
}
bool is_rectangle() {
    for (int i = min_x; i <= max_x; i++) {
        for (int j = min_y; j <= max_y; j++) {
            if (grid[i][j] == '.') return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            grid[i][j] = line[j];
        }
    }

    int f_count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#' && visited[i][j] == 0) {
                BFS(i, j);
                f_count++;
                if (!is_rectangle()) {
                    cout << "Bad placement.";
                    return 0;
                }
            }
        }
    }

    cout << "There are " << f_count << " ships.";
}