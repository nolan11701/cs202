#include <iostream>
#include <queue>

using namespace std;

struct node {
    long long data;  // must be long long
    int cnt_5;
    int cnt_8;
    node(long long a, int b, int c) : data(a), cnt_5(b), cnt_8(c) {}
};

int n;

int main() {
    cin >> n;  // 55

    queue<node> q;
    q.push(node(0, 0, 0));

    while (!q.empty()) {
        node num = q.front();
        q.pop();

        long long tmp = num.data * 10 + 5;

        if (tmp >= n && num.cnt_5 + 1 == num.cnt_8) {
            cout << tmp;
            return 1;
        } else {
            q.push(node(tmp, num.cnt_5 + 1, num.cnt_8));
        }

        tmp = num.data * 10 + 8;

        if (tmp >= n && num.cnt_8 + 1 == num.cnt_5) {
            cout << tmp;
            return 1;
        } else {
            q.push(node(tmp, num.cnt_5, num.cnt_8 + 1));
        }
    }
}