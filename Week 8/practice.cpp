#include<bits/stdc++.h>

using namespace std;

 

// output the order of visit

// it should be 1 2 4 5 3 

 

// 1D array, skip index 0

vector<int> vis{6, 0};

// 2D array, skip index 0

// define neighbors, node1 has neighbors 2 and 3

// 2 has neighbors 4 and 5

vector<vector<int>> v{{}, {2,3}, {4,5},{},{},{}};

void dfs(int x){

    stack<int> s;

    s.push(x);  // init 

    while(!s.empty()){

        x=s.top();

        if(vis[x]==0){

            cout<<x<<" ";

            vis[x]=1;

        }

        int flag=0; // 

        for(int i=0;i<v[x].size();i++)

            if(vis[v[x][i]]==0){

                s.push(v[x][i]);

                flag=1;

                break;

            }

        if(flag==0) s.pop();

    }

}
 

int main() {

    dfs(1); // start node is 1

}