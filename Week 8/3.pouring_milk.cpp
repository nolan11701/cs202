#include <iostream>
#include <stack>
#include <queue>
using namespace std;
struct Milk {
    int b[3];
    int src, dst;
};

int a[3];
bool vis[21][21][21] = {false};
bool mark[21] ={false};

void dfs(){
    stack<Milk> s;
    s.push({{0, 0, a[2]}, 0, 0});
    
    while (s.size()){
        s.top().dst += 1;
        if (s.top().dst == 3) {
            s.top().dst = 0;
            s.top().src += 1;
            if (s.top().src == 3) {
                s.pop();
                continue;
            }

        }
        Milk x = s.top();
        if (x.b[x.src] && x.src != x.dst && x.b[x.dst] < a[x.dst]){
            int v = min(a[x.dst] - x.b[x.dst], x.b[x.src]);
            x.b[x.src] -= v;
            x.b[x.dst] += v;
            if (vis[x.b[0]][x.b[1]][x.b[2]] == false) {
                vis[x.b[0]][x.b[1]][x.b[2]] = true;
                if (x.b[0] == 0) {
                    mark[x.b[2]] = true;
                }
                x.src = x.dst = 0;
                s.push(x);
            }
        }
    }
}

int main(){
    cin >> a[0] >> a[1] >> a[2];
    vis[0][0][a[2]] = true;
    mark[a[2]] = true;
    dfs();

    for(int i = 0; i <= a[2]; i++){
        if (mark[i]) {
            cout << i << " ";

        }
    }
    return 0;
}