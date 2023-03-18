#include <iostream>
#include <set>
#include <queue>

using namespace std;
int n, m, lookup_time = 0;
set <int> cache;
queue<int> q;

void check(){
    int cur;
    cin >> cur;
    if (!cache.count(cur)) {
        lookup_time++;
        if (cache.size() == m) {
            int top = q.front();
            q.pop();
            cache.erase(top);
            q.push(cur);
            cache.insert(cur);
        } else {
            q.push(cur);
            cache.insert(cur);
        }
    }
}

int main() {
    cin >> m >> n;
    while (n--){
        check();
    }
    cout << lookup_time << "\n";
}