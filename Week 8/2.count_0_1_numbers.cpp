#include <iostream>
#include <queue>
#include <map>
using namespace std;

int n;
map<int, int> visited;
queue<int> q; 


int bfs (int start) {
    // queue
    // push start in queue
    q.push(start);
    // visited (start)
    visited[start] = 1;
    int cnt = 1;
    // dis[node] = 1
    
    // while queue not empty
    while (q.size()){
        /// termination 
        // if front > n { return dis[front] }
    
        // pop queue front 
        int e = q.front();
        q.pop();
        // find all neighbours of front 
        if (e > n) {
            return visited[e];
        }

        int n1 = e*10;
        int n2 = e*10+1;

        // *10 or *10+1
        // for each neighbour 
        visited[n1] = cnt++;
        visited[n2] = cnt++;
        // vistied (neighbour)
        // dis[neighbour] = dis[node] +1
        q.push(n1);
        q.push(n2);

    }

    return -1;

}

int main(){
    cin >> n;
    cout << bfs(1);
}