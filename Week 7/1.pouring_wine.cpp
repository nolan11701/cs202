#include <iostream>
#include <map>
#include <queue>
#include <utility>

using namespace std;
int capacity[3];
int half;
queue<vector<int> > q;
map<vector<int>, int> visited;

// int dx[6][3] = {{1, 2, 0}, {1, 0, 2}, {0, 1, 2},
//                 {2, 1, 0}, {2, 0, 1}, {0, 2, 1}};
int from[6] = {0, 0, 1, 1, 2, 2};
int to[6] = {1, 2, 0, 2, 0, 1};

// bool is_possible(string s) { return false; }

// ANode find_neighbour(ANode p, int changes[]) {
//     if (changes[0] == 1 && changes[1] == 2) {  // a->b

//         if (p.a - (B - p.b) > 0) {
//             return {p.a - (B - p.b), B, p.c};
//         } else {
//             return {0, p.a + p.b, p.c};
//         }

//     } else if (changes[0] == 1 && changes[2] == 2) {  // a->c

//         if (p.a - (C - p.c) > 0) {
//             return {p.a - (C - p.c), p.b, C};
//         } else {
//             return {0, p.b, p.a + p.c};
//         }

//     } else if (changes[1] == 1 && changes[2] == 2) {  // b->a

//         if (p.b - (A - p.a) > 0) {
//             return {A, p.b - (A - p.a), p.c};
//         } else {
//             return {p.a + p.b, 0, p.c};
//         }

//     } else if (changes[0] == 2 && changes[1] == 1) {  // b->c

//         if (p.b - (C - p.c) > 0) {
//             return {p.a, p.b - (C - p.c), C};
//         } else {
//             return {p.a, 0, p.b + p.c};
//         }

//     } else if (changes[0] == 2 && changes[2] == 1) {  // c->a
//         if (p.c - (A - p.a) > 0) {
//             return {A, p.b, p.c - (A - p.a)};
//         } else {
//             return {p.a + p.c, p.b, 0};
//         }
//     } else if (changes[1] == 2 && changes[2] == 1) {  // c->b
//         if (p.c - (B - p.b) > 0) {
//             return {p.a, B, p.c - (B - p.b)};
//         } else {
//             return {p.a, p.a + p.b, 0};
//         }
//     }
//     return {-1, -1, -1};
// }
// bool is_neighbour(ANode p, int changes[]) {
//     if (changes[0] == 1 && changes[1] == 2) {  // a->b
//         return (p.b != B && p.a != 0);
//     } else if (changes[0] == 1 && changes[2] == 2) {  // a->c
//         return (p.a != 0 && p.c != C);
//     } else if (changes[1] == 1 && changes[2] == 2) {  // b->a
//         return (p.b != 0 && p.a != A);
//     } else if (changes[0] == 2 && changes[1] == 1) {  // b->c
//         return (p.b != 0 && p.c != C);
//     } else if (changes[0] == 2 && changes[2] == 1) {  // c->a
//         return (p.c != 0 && p.a != A);
//     } else if (changes[1] == 2 && changes[2] == 1) {  // c->b
//         return (p.c != 0 && p.b != B);
//     }

//     return false;
// }

void pour_wine(vector<int> node) {
    for (int i = 0; i < 6; i++) {
        int amount = min(node[from[i]], capacity[to[i]] - node[to[i]]);

        vector<int> next = node;
        next[from[i]] -= amount;
        next[to[i]] += amount;

        if (amount > 0 && visited[next] == 0) {
            visited[next] = visited[node] + 1;
            q.push(next);
        }
    }
}

bool at_end(vector<int> s) {
    int sum = 0;
    for (int i = 0; i<3; i++){
        if (s[i] == half) sum++;
    }
    return sum == 2;
}
int bfs(int a, int b, int c) {
    vector<int> root = {a, b, c};
    q.push(root);
    // visit root

    // cout << root.a << root.b << root.c;

    while (q.size()) {
        vector<int> p = q.front();  // parent node
        q.pop();

        // termininating condition - write last - return distance
        if (at_end(p)) {  // 4 4 0
            return visited[p];
        }
        pour_wine(p);
        // for each neighbour that is possible (not visited)
        // visit it
        // calc distacnce = parent distance + 1
        // push to queue
    }
    return -1;
}

int main() {
    cin >> capacity[0] >> capacity[1] >> capacity[2];
    half = capacity[0] / 2;
    int a = bfs(capacity[0], 0, 0);
    if (a == -1)
        cout << "NO";
    else
        cout << a;
}