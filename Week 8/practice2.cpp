#include <iostream>

#include <stack>

using namespace std;

 

struct Point {

	int x, y;

	int dir;

};

 

int w, h;

char maze[20][20];

// another way for dx, dy

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

 

int dfs(int sx, int sy)

{

	bool vis[20][20] = {false};

	vis[sx][sy] = true;

	stack<Point> s;

	s.push((Point){sx, sy, -1});  // when pushing, always -1

	int cnt = 1;  // start from 1

	

	while (!s.empty()) {

		s.top().dir += 1;  // mark to next neighbor

		Point p = s.top();

 

    // if we finish seaching 4 neighbors, pop it

    // and go to next one in stack

 

    // if not, go to next neighbor using p.dir

    // if it is valid, increment count

    // push to stack

    }

	

	return cnt;

}

 

int main()

{

	int sx, sy;

	

	while ((cin >> w >> h) && w + h) {

		for (int i = 0; i < h; i++)  {

			for (int j = 0; j < w; j++) {

				cin >> maze[i][j];

				if (maze[i][j] == '@') {

					sx = i;

					sy = j;

				}

			}

		}

		cout << dfs(sx, sy) << endl;

	}

 

	return 0;

}

while (!s.empty()) {

		s.top().dir += 1;

		Point p = s.top();

		

		if (p.dir == 4) {

			s.pop();

			continue;

		}

		

		int row = p.x + dir[p.dir][0];

		int col = p.y + dir[p.dir][1];

		

		if (0 <= row && row < h && 0 <= col && col < w

			&& !vis[row][col] && maze[row][col] != '#') {

			cnt += 1;

			vis[row][col] = true;

			s.push((Point){row, col, -1});

		}

	}