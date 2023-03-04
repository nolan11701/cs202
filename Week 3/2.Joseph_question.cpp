#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int n, m;
int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    int cnt = 0;
    while (q.size()) {
        int v = q.front();
        q.pop();
        cnt++;
        if (cnt == m) {
            cout << v << " ";
            cnt = 0;
        } else {
            q.push(v);
        }
    }
}
