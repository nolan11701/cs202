#include <iostream>
#include <vector>
using namespace std;

// define glabal variables
char grid[1001][1001];
int ans = 0;
int visited[1001][1001];

int n, m;

void floodfill(int x, int y){
    //for (int i = 0; i < )
    if (x < 0 || y < 0 || x >= n || y >=m || visited[x][y] || grid[x][y] != '.'){
        return;
    }
    visited[x][y] = 1;
    floodfill(x+1, y);
    floodfill(x-1, y);
    floodfill(x, y+1);
    floodfill(x, y-1);
    
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == '.'&& !visited[i][j]) {
                floodfill(i, j);
                ans++;
            }
        }
    }
    cout << ans;
}