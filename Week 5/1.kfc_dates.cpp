#include <iostream>
#include <queue>
#include <vector>
using namespace std;
char grid[200][200];
int visited[200][200];
int inf = 40001;  // can't use INT_MAX
int n, m;

queue<pair<int, int> > q;
const int NUM_DIRS = 4;

int dx[NUM_DIRS] = {0, 0, 1, -1};
int dy[NUM_DIRS] = {1, -1, 0, 0};

bool is_possible(int x, int y, vector<vector<int> > &dist) {
    return x >= 0 && y >= 0 && x < n && y < m && dist[x][y] == inf &&
           grid[x][y] != '#';
}


void bfs(int sx, int sy, vector<vector<int> > &dist) {
    // '&' is necessary, otherwise it makes a copy of dist
    // put your bfs code here
    // sx, sy is start point and store results in dist

    // push start position to the queue
    q.push(make_pair(sx, sy));
    dist[sx][sy] = 0; 
    // while queue is not empty:
    while (q.size()) {
        // collect the point at the front + pop front
        pair<int, int> e = q.front();
        q.pop();
        int x = e.first;
        int y = e.second;
        visited[x][y] = 1;

        // cout << x << ", " << y << "\n";
        
        // for all neighbors of current point:
        for (int i = 0; i < NUM_DIRS; i++) {
            pair<int, int> point = make_pair(x + dx[i], y + dy[i]);

            // if the point is possible to visit:
            if (is_possible(point.first, point.second, dist)) {
                // mark the cell as visited
                visited[point.first][point.second] = 1;
                
                // set neighbours steps to +1
                if (dist[point.first][point.second] == inf) 
                    dist[point.first][point.second] = dist[x][y] +1;
      
                // push the cell to the queue
                q.push(point);

            }
        }
    }

}
int main() {
    int me_x, me_y, friend_x, friend_y;
    cin >> n >> m;
    vector<vector<int> > dist_me(n, vector<int>(m, inf));
    vector<vector<int> > dist_friend(n, vector<int>(m, inf));
    vector<pair<int, int> > kfc_locations;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'F') {
                kfc_locations.push_back(make_pair(i, j));
            } else if (grid[i][j] == '@') {
                me_x = i;
                me_y = j;
            } else if (grid[i][j] == '&') {
                friend_x = i;
                friend_y = j;
            }
        }
    }
    // calc your dist

    bfs(me_x,me_y, dist_me);
    // calc firend's dist
    bfs(friend_x,friend_y, dist_friend);

    // go through all kfc location, find shortest one

    int short_path = inf;
    for (int i = 0; i< kfc_locations.size();i++) {
        pair<int, int> p = kfc_locations[i];
        int path = dist_me[p.first][p.second] + dist_friend[p.first][p.second];
        short_path = (path < short_path)? path : short_path;
    }

    // output result or cancel message
    if (short_path < inf) {
        cout << short_path;
    } else {
        cout << "Meeting cancelled";
    }
}