#include <iostream>
#include <cstring>

using namespace std;

int t;
int board[9][9];

bool squareCheck(int r, int c) {
	bool visited[10] = { false, };
	int cnt = 0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j) {
			if (!visited[board[r + i][c + j]]) {
				++cnt;
				visited[board[r + i][c + j]] = true;
			}
		}
	}
	return (cnt == 9);
}

bool rowCheck(int r) {
	bool visited[10] = { false, };
	int cnt = 0;
	for (int i = 0; i < 9; ++i)
	{
		if (!visited[board[r][i]]) {
			++cnt;
			visited[board[r][i]] = true;
		}
	}
	return (cnt == 9);
}

bool colCheck(int c) {
	bool visited[10] = { false, };
	int cnt = 0;
	for (int i = 0; i < 9; ++i)
	{
		if (!visited[board[i][c]]) {
			++cnt;
			visited[board[i][c]] = true;
		}
	}
	return (cnt == 9);
}

bool solve(int r, int c) {
	bool ok = true;
	for (int i = 0; i < 9; ++i) {
		if (!rowCheck(i)) ok = false;
		if (!colCheck(i)) ok = false;
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (!squareCheck(r + i * 3, c + j * 3))
				ok = false;
		}
	}
	return (ok);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	t = 0;
	for (t = 1; t <= T; ++t) {
		memset(board, 0, sizeof(board));	
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
				cin >> board[i][j];	
		if (solve(0, 0))
			printf("#%d %d\n", t, 1);
		else
			printf("#%d %d\n", t, 0);
	}
	return (0);
}
