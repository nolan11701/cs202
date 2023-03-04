#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>

using namespace std;

string swap_string(string s, int idx, int nidx) {
    char c = s[idx];
    char d = s[nidx];
    string t(1,c);
    string p(1,d);
    s.erase(idx, 1);
    s.insert(idx, p);
    s.erase(nidx, 1);
    s.insert(nidx, t);
    return s;
}

// swap: 283104765 4 3 283014765
// new point1 283014765 3 1 
// swap: 283104765 4 1 208314765
// new point1 208314765 1 1 

int main() {
    string s = "283104765";
    int idx = 4;
    int nidx = 1;
   
    string p = swap_string(s,idx, nidx);
    cout << p;
}

