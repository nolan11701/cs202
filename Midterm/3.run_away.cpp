#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int grid[100][100][100];
int visited[100][100][100];

int x1, y1, x2, y2, z1, z2;

int n, m, k, p, t;
struct point {
    int x, y, z, s;
    point(int a, int b, int c, int d) : x(a), y(b), z(c), s(d) {}
};

queue<point> q;
const int NUM_DIRS = 6;
int shortest_path = -1;

int dx[NUM_DIRS] = {0, 0, 1, -1, 0, 0};
int dy[NUM_DIRS] = {1, -1, 0, 0, 0, 0};
int dz[NUM_DIRS] = {0, 0, 0, 0, 1, -1};


bool is_possible(int x, int y, int z) {
    return (x >= 0 && y >= 0 && z >= 0 && x < n && y < m && z < p && visited[x][y][z] != 1 &&
            grid[x][y][z] == 0);
}

void BFS(int x, int y, int z) {
    // push start position to the queue
    point p(x, y, z, 0);
    q.push(p);
    // while queue is not empty:
    while (q.size()) {
        // collect the point at the front + pop front
        point e = q.front();
        q.pop();

        // for all neighbors of current point:
        int x = e.x;
        int y = e.y;
        int z = e.z;
        int s = e.s;
        visited[x][y][z] = 1;

        // cout << x << ", " << y << "\n";
        if (x == x2 && y == y2 && z == z2) {
            shortest_path = s;
            break;
        }

        for (int i = 0; i < NUM_DIRS; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            point np(nx, ny, nz, s + 1);

            // if the point is possible to visit:
            if (is_possible(np.x, np.y, np.z)) {
                // mark the cell as visited
                visited[np.x][np.y][np.z] = 1;
                // push the cell to the queue
                q.push(np);
            }
        }
    }
}
int main() {
    cin >> k;
    cin >> n >> m >> p >> t;
    x1 = y1 = z1 = 0;
    x2 = n - 1;
    y2 = m - 1;
    z2 = p - 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int h = 0; h < p; h++) {
                cin >> grid[i][j][h];
            }
        }
    }
    BFS(x1, y1, z1);
    cout << shortest_path;
}