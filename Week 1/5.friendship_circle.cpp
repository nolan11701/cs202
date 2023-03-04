#include <iostream>
#include <vector>
using namespace std;

// define glabal variables
int grid[1001][1001];
int ans = 0;
int visited[1001];

int n, m;
int bet = 0;

bool possible(int student_from, int student_to){
    return !visited[student_to] && grid[student_from][student_to] == 1;
}
void floodfill(int student){
    if (visited[student]) return;
    visited[student] = 1;
    for (int i = 0; i < n; i++){
        if (possible(student, i )){
            floodfill(i);
        }
    }
}

int main(){
    cin >> n;
    m = n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        if (!visited[i]) {
            bet++;
            floodfill(i);
        }
    }
    cout << bet;
}