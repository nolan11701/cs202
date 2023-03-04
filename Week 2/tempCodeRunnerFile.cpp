#include <iostream>
#include <map>
using namespace std;

map<string, string> m;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string city;
        string state;
        cin >> city >> state;
        m[city.substr(0,2)] = state;
    }
    int cnt = 0;
    for  (auto c : m){
        string key = c.first;
        string val = c.second;
        
        if (key == m[val]) {
            cnt ++;
        }
    }
    cout << cnt-1;
}