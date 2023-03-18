#include <iostream>
using namespace std;

int cache[1000001];
int w, p, a, b;

int calculate(int cur_price) {
    if (cur_price < p){
        return 0;
    } else if (cur_price == p) {
        return 1;
    }
    if (cache[cur_price] != 0){
        return cache[cur_price];
    }
    cache[cur_price] = calculate(cur_price - a) + calculate(cur_price - b);
    return cache[cur_price];
    
}
int main() {
    cin >> w >> p >> a >> b;
    cout << calculate(w);
}