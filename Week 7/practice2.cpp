#include <iostream>

using namespace std;

int n;

// 1 2-3-4-5+

int eval(string st) {
    st += "+";  // make it easier
    int now = 0, res = 0, f = 1;
    for (int i = 1; i < 2 * n; i = i + 2) {
        int next = i / 2 + 1;  // 1, 2, 3, 4, 5...
        if (st[i] == ' ') {
            now = now * 10 + next;
        } else if (st[i] == '+') {
            now = now * 10 + next;
            res += f * now;
            now = 0;
            f = 1;
        } else {  // minus
            now = now * 10 + next;
            res += f * now;
            now = 0;
            f = -1;
        }
    }

    return res;
}

void dfs(string expr, int pos) {
    if (pos == n) {
        if (eval(expr) == 0) cout << expr << endl;
        return;
    }

    dfs(expr + " " + to_string(pos + 1), pos + 1);
    dfs(expr + "+" + to_string(pos + 1), pos + 1);
    dfs(expr + "-" + to_string(pos + 1), pos + 1);
}

int main() {
    scanf("%d", &n);
    dfs("1", 1);
}