#include <iostream>
#include <map>
using namespace std;

map<int, int> m;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;

        if (m.find(d) == m.end()) {
            m[d] = 1;
        } else {
            m[d]++;
        }
    }
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->first << ' ' << it->second << '\n';
    }
}
