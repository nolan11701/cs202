#include <iostream>
using namespace std;

const int mx_n = 20;
char grid[mx_n][mx_n];
bool visited[26];
int r, s, best_path = 0;

bool possible(int x, int y) {
    return x >= 0 && y >= 0 && x < r && y < s && !visited[grid[x][y]- 'A'];
}

void dfs(int x, int y, int steps){
    if (!possible(x,y)) return;
    visited[grid[x][y]-'A'] = true;
    best_path = max(best_path, steps);
    dfs(x+1, y, steps+1);
    dfs(x-1, y, steps+1);
    dfs(x, y+1, steps+1);
    dfs(x, y-1, steps+1);
    visited[grid[x][y]-'A'] = false;
}

int main(){
    cin >> r >> s;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < s; j++){
            cin >> grid[i][j];
        }
    }
    dfs(0, 0, 0);
    cout << best_path+1;
}