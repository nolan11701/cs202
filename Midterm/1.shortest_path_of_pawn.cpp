#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int grid[100][100];
int visited[100][100]; 

int x1, y1, x2, y2;

int n, m;  
struct point {
    int x, y, s;
    point(int a, int b, int c) : x(a), y(b), s(c) {}
};

queue<point> q;
const int NUM_DIRS = 8;
int shortest_path = -1;

int dx[NUM_DIRS] = {0, 0, 1, -1, 0, 0, 2, -2};
int dy[NUM_DIRS] = {1, -1, 0, 0, 2, -2, 0, 0};


bool is_possible(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m && visited[x][y] != 1 && grid[x][y] == 0);
}

void BFS(int x, int y) {
    // push start position to the queue
    point p(x,y,0);
    q.push(p);
    // while queue is not empty:
    while (q.size()) {
        // collect the point at the front + pop front
        point e = q.front();
        q.pop();
        
        // for all neighbors of current point:
        int x = e.x;
        int y = e.y;
        int s = e.s;
        visited[x][y] = 1;

        // cout << x << ", " << y << "\n";
        if (x == x2 && y == y2) {
            shortest_path = s;
            break; 
        }

        for (int i = 0; i < NUM_DIRS; i++) {

            int nx = x+dx[i];
            int ny = y+dy[i];
            point np(nx, ny, s+1);

            // if the point is possible to visit:
            if (is_possible(np.x, np.y)) {
                // mark the cell as visited
                visited[np.x][np.y] = 1;
                // push the cell to the queue
                q.push(np);
            }
        }
    }
}
int main() {
    
    cin >> n;
    m = n;

    cin >> x1 >> y1;
    cin >> x2 >> y2;

    BFS(x1, y1);
    cout << shortest_path;
    
}