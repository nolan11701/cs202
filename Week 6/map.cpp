#include <iostream>
#include <map>
using namespace std;


int main() {

    map<int, int> m;

    m[0] = 1;
    m[100] = 2;

    //cout << m[100];


    for (map<int, int>::iterator it = m.begin(); it != m.end();
         it++) {
        cout << it->first << ' ' << it->second << '\n';
    }
}