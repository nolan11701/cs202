#include <iostream>
#include <vector>
using namespace std;

int main() {
    // int c[10];
    // c[0] = 1;

    // vector<int> v;

    // v.push_back(1);
    // v.push_back(2);

    // cout << v[0];
    // v[0] = 3;
    // cout << v[0];

    // vector<vector<int> > b;

    // // loop vector

    // for (int i = 0; i < v.size(); i++) {
    //     cout << v[i];
    // }

    int n = 5;
    int m = 6;
    int inf = 40001;
    vector<vector<int> > dist(n, vector<int>(m, inf));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}