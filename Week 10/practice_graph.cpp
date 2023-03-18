// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> g[200005];
// int n,m;

// int main() {
//     cin >> n >> m;
//     for (int i = 0; i < m; i ++){
//         int k , v;
//         cin >> k >> v;
//         g[k].push_back(v);
//     }

//     for (int i =0;i<n;i++){
//         cout << i+1 << " " ;
//         for (int j=0;j<g[i].size();j++){
//             cout  << g[i][j] << " ";
//         }
//         cout << "\n";
//     }
// } 

#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
vector<int> ajacency_lists[N];
int visited[N];

int dfs(int from) {
  // todo: complete dfs code here
}

int main() {
  int n, m, ans = 0, x, y;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    // todo: read edges and build adjacency lists
  }

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      dfs(i);
      ans++;
    }
  }

  printf("%d\n", ans);
  return 0;
}