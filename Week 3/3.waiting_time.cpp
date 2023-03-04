#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for (int i = 0; i<n; i++){
        int l;
        cin >> l;
        q.push(l);
    }

    int p = k;
    int time_cnt = 0;

    while (q.size()){
        int v = q.front();
        q.pop();
        time_cnt++;
        if (v-1 > 0){
            q.push(v-1);
            if (p == 0){
                p = q.size()-1;
            } else {
                p -= 1;
            }
        } else if (v - 1 == 0) {
            if (p == 0){
                cout << time_cnt;
                break;
            } else {
                p -= 1;
            }
        }


    //if first -1 > 0; push to end   
        // if it is p == 0,  p = size()
        // else p -1
    // else first -1 == 0
        // drop 
        // if it is p == 0,
            // done - cout time count 
            // break 
        // else p -1
    }
}