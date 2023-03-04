#include <iostream>
#include <map>
using namespace std;

map<string, int> m;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string city;
        string state;
        cin >> city >> state;
        city = city.substr(0, 2);

        if (city != state) {
            m[city + state]+=1;
            cnt += m[state + city];
        }
    }
    cout << cnt;
}