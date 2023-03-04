#include <iostream>
#include <map>
#include <queue>
#include <utility>

using namespace std;
map<string, int> visited;

map<string, int> steps;

int shortest_path = -1;

queue<pair<string, int> > q1, q2;

const int NUM_DIRS = 4;

int dx[NUM_DIRS][9] = {{0, 0, 1, 3, 3, 4, 6, 6, 7},
                       {0, 1, 2, 0, 1, 2, 3, 4, 5},
                       {1, 2, 2, 4, 5, 5, 7, 8, 8},
                       {3, 4, 5, 6, 7, 8, 6, 7, 8}};

bool is_possible(string str, int idx) {
    bool ret = (idx >= 0 && visited.find(str) == visited.end());
    // cout << "possible " << str << " " << idx << " " << ret << "\n";
    return ret;
}
string swap_string(string s, int idx, int nidx) {
    // cout << "swap: " << s << " " << idx << " " << nidx;
    char c = s[idx];
    char d = s[nidx];
    string t(1, c);
    string p(1, d);
    s.erase(idx, 1);
    s.insert(idx, p);
    s.erase(nidx, 1);
    s.insert(nidx, t);
    return s;
}
void BBFS(string str1, int idx1, string str2, int idx2) {
    q1.push(make_pair(str1, idx1));
    q2.push(make_pair(str2, idx2));
    visited[str1] = 1;
    visited[str2] = 2;
    steps[str1] = 0;
    steps[str2] = 0;

    while (!q1.empty() && !q2.empty()) {
        // BFS for start
        // - collect and pop the front from the start queue

        pair<string, int> e1 = q1.front();
        q1.pop();
        string str = e1.first;
        int idx = e1.second;

        // for all neighbors of current point:
        for (int i = 0; i < NUM_DIRS; i++) {
            int nidx = dx[i][idx];
            string new_str = swap_string(str, idx, nidx);
            pair<string, int> point = make_pair(new_str, nidx);

            // if the point is possible to visit:
            if (is_possible(point.first, point.second)) {
                // cout << "new point1 " << point.first << " " << point.second
                // << " 1 \n";

                // mark the cell as visited
                visited[point.first] = 1;

                // set neighbours steps to +1
                steps[point.first] = steps[str] + 1;

                // push the cell to the queue
                q1.push(point);
            } else if (visited[point.first] == 2) {
                // found the connection
                shortest_path = steps[str] + steps[point.first];

                cout << shortest_path + 1;
                exit(1);
            }
        }

        pair<string, int> e2 = q2.front();
        q2.pop();
        str = e2.first;
        idx = e2.second;

        // for all neighbors of current point:
        for (int i = 0; i < NUM_DIRS; i++) {
            int nidx = dx[i][idx];
            string new_str = swap_string(str, idx, nidx);
            pair<string, int> point = make_pair(new_str, nidx);

            // if the point is possible to visit:
            if (is_possible(point.first, point.second)) {
                // cout << "new point2 " << point.first << " " << point.second
                //      << " 2 \n";

                // mark the cell as visited
                visited[point.first] = 2;

                // set neighbours steps to +1

                steps[point.first] = steps[str] + 1;

                // push the cell to the queue
                q2.push(point);
            } else if (visited[point.first] == 1) {
                // found the connection

                shortest_path = steps[str] + steps[point.first];

                cout << shortest_path + 1;
                exit(1);
            }
        }
    }
}

int main() {
    string start;
    cin >> start;
    int start_idx = start.find('0');

    string end = "123804765";
    int end_idx = end.find('0');

    BBFS(start, start_idx, end, end_idx);
    cout << "-1";

    // for (map<string, int>::iterator it = visited.begin(); it != visited.end();
    //      it++) {
    //     cout << it->first << ' ' << it->second << '\n';
    // }
}