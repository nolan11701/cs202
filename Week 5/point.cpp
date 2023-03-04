#include <iostream>

using namespace std;
struct point {
    int x, y, z = 0;
    point(int a, int b) : x(a), y(b) {}
    point(int a, int b, int c) : x(a), y(b), z(c) {}
};

int main() {
    point p(1, 2);

    cout << p.x << " " << p.y << " " << p.z;
    
    point p2(1, 2, 3);
    cout << p2.x << " " << p2.y << " " << p2.z;
}