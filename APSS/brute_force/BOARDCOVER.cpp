#include <iostream>
#include <vector>

using namespace std;

int H, W;

#if 1
const int coverType[4][3][2] = 
	{ 
		{ {0, 0}, {1, -1}, {1, 0} },
		{ {0, 0}, {1,  0}, {1, 1} },
		{ {0, 0}, {0,  1}, {1, 1} },
		{ {0, 0}, {0,  1}, {1, 0} }
	};

bool inRange(int y, int x) {
	if (y >= 0 && y <= H && x >= 0 && x <= W)
		return (true);
	return (false);
}

bool set(vector<vector<int> > &board, int y, int x, int type, int delta) {
	bool ok = true;

	for (int i = 0; i < 3; ++i) {
		int ny = y + coverType[type][i][0]; 
		int nx = x + coverType[type][i][1]; 

		if (!inRange(ny, nx))
			ok = false;
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}
	return (ok);
}

int	cover(vector<vector<int> > &board) {
	int y = -1, x = -1;
	for (int j = 0; j < H; ++j) {
		for (int i = 0; i < W; ++i) {
			if (!board[j][i]) {
				y = j;
				x = i;	 
				break ;
			}
		}
		if (y != -1) break ;
	}
	// board is full
	if (y == -1) return (1);

	int ret = 0;
	for (int type = 0; type < 4; ++type) {
		if (set(board, y, x, type, 1))
			ret += cover(board);
		set(board, y, x, type, -1);
	}
	return (ret);
}
#endif

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W;
	vector<string> boardStr(H);
	vector<vector<int> > board(H, vector<int> (W));

	for (int y = 0; y < H; ++y) {
		cin >> boardStr[y];
		for (int x = 0; x < W; ++x) {
			if (boardStr[y][x] == '#')
				board[y][x] = 1;
			else if (boardStr[y][x] == '.')
				board[y][x] = 0;
		}
	}

	cout << cover(board) << "\n"; 
	
	return (0);
}
