#include <iostream>
#include <queue>
using namespace std;

struct Floor {
    int floor, steps;  // pos->floor; moves->steps
};

int k[201];
bool visited[201];
int n, a, b;  // a->start; b->end
int shortest_path = -1;
queue<Floor> q;

bool is_possible(int floor) {
    return (floor > 0 && floor <= n && !visited[floor]);
}

void bfs(int a) {   
    Floor d = {a, 0};
    q.push(d);
    // while queue is not empty:
    while (q.size()) {
        // collect the point at the front + pop front
        Floor e = q.front();
        q.pop();

        // for all neighbors of current point:
        int floor = e.floor;
        int step = e.steps;

        visited[floor] = 1;

        // cout << x << ", " << y << "\n";
        // terminating condition
        if (floor == b) {
            shortest_path = step;
            break;
        }

        Floor up = {floor + k[floor], step + 1};
        Floor down = {floor - k[floor], step + 1};

        // if the point is possible to visit:
        if (is_possible(up.floor)) {
            // mark the cell as visited
            visited[up.floor] = 1;
            // push the cell to the queue
            q.push(up);
        }

        if (is_possible(down.floor)) {
            // mark the cell as visited
            visited[down.floor] = 1;
            // push the cell to the queue
            q.push(down);
        }
    }
}
int main() {
    cin >> n >> a >> b;

    for (int i = 1; i <= n; i++) cin >> k[i];
    int p;
    cin >> p;

    bfs(a);

    cout << shortest_path;
}