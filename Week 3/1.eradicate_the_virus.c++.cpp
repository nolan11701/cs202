#include <iostream>
#include <queue>
using namespace std;

int n;
int k;
queue<int> q;

int main() {
    cin >> n >> k;
    int queue_sum = 0;
    int max_queue = 0;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;

        while (queue_sum + v > k) {
            queue_sum -= q.front();
            q.pop();
        }
        q.push(v);
        queue_sum += v;

        if (queue_sum <= k) {
            max_queue = (max_queue >= q.size()) ? max_queue : q.size();
        }
    }

    cout << max_queue;
}