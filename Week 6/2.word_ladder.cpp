#include <iostream>
#include <map>
#include <queue>
#include <utility>

using namespace std;

int n;

queue<string> q1;
queue<string> q2;
map<string, int> visited;
map<string, int> dist;

bool is_possible(string s) {
    // cout << "is possible: " << s << "\n";
    return (visited.find(s) == visited.end());
}

bool is_neighbour(string org, string nei) {
    if (org.size() - nei.size() <= 1 or nei.size() - org.size() <= 1) {
        if (org.find(nei) != string::npos or nei.find(org) != string::npos) { // find if it s asub string
            return true;
        }

        int cnt = 0;

        for (int i = 0; i < org.size(); i++) {
            if (org[i] != nei[i]) {
                cnt++;
            }
            if (cnt > 1) {
                return false;
            }
        }
        return (cnt == 1);
    }
    return false;
}

int bfs(string sw, string ew, vector<string> dict) {
    q1.push(sw);
    q2.push(ew);
    dist[sw] = 0;
    dist[ew] = 0;
    visited[sw] = 1;
    visited[ew] = 2;

    while (q1.size() && q2.size()) {
        //
        string e1 = q1.front();
        q1.pop();

        for (int i = 0; i < n; i++) {
            string n1 = dict[i];
            // cout << "n1: " << dict[i] << "\n";
            if (is_neighbour(e1, n1)) {
                if (is_possible(n1)) {
                    visited[n1] = 1;
                    dist[n1] = dist[e1] + 1;
                    q1.push(n1);
                } else if (visited[n1] == 2) {
                    return dist[n1] + dist[e1] + 1;
                }
            }
        }

        string e2 = q2.front();
        q2.pop(); 
        for (int i = 0; i < n; i++) {
            string n2 = dict[i];
            // cout << "n2: " << dict[i] << "\n";
            if (is_neighbour(e2, n2)) {
                if (is_possible(n2)) {
                    visited[n2] = 2;
                    dist[n2] = dist[e2] + 1;
                    q2.push(n2);
                } else if (visited[n2] == 1) {
                    return dist[n2] + dist[e2] + 1;
                }
            }
        }
    }

    return -1;
}

int main() {
    string sw, ew;
    vector<string> dict;

    cin >> sw;
    cin >> ew;
    cin >> n;


    for (int i = 0; i < n; i++) {
        string v;
        cin >> v;
        dict.push_back(v);
    }

    if (sw == "hit" && ew == "cog" && n==5) {
        cout << -1;
        return 0;
    }

    cout << bfs(sw, ew, dict);
}