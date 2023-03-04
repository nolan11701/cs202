// #include <iostream>
// using namespace std;

// int n;
// int maze[100][100];
// int visited[100][100];
// int step_count;

// bool IsTrue(int x, int y){
//     return (x >= 0 && y >= 0 && x < n && 
//     y < n && visited[x][y] == 0 && !visited[x][y]);
// }
// void floodfill(int x, int y){
//     if (!IsTrue(x, y)){
//         return;
//     }
//     visited[x][y]=0;
//     step_count+=1;
//     floodfill(x - 1, y - 1);
//     floodfill(x + 1, y + 1);
//     floodfill(x - 1, y);
//     floodfill(x + 1, y);
// }

// int main(){
//     cin >> n;
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < n; j++ ){
//             cin >> maze[i][j];
//         }
//     }
//     floodfill(0, 0);
// }
// Floodfill
// https://xjoi.net/problem/7421
#include <iostream>
using namespace std;

const int mx_n = 500;
int grid[mx_n][mx_n];
bool visited[mx_n][mx_n];
int n, ans = 0;
int sx, sy;
int step_count;

bool valid(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && 
    y < n && grid[x][y] == 0 && !visited[x][y]);
}

int dfs(int x, int y) {
    if (!valid(x, y)) return INT_FAST16_MAX;
    if (x == sx && y == sy){
        step_count = min(step_count, ans);
    }
    visited[x][y] = true;

    int one = dfs(x - 1, y - 1);
    int two = (x + 1, y + 1);
    int three =(x - 1, y);
    int four = (x + 1, y); 
    visited[x][y] = false;

    return min(one, two, three, four) + 1;

}
int main() {
    cin >> n >> sx >> sy;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    dfs(sx, sy);
    cout << ans;
}