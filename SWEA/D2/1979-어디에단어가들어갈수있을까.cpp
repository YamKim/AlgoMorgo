#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int board[17][17];
int N, K;

bool rowCheck(int y, int x, int k) {
	if (!(board[y][x] == 0 && board[y][x + k] == 0))
		return (false);
	for (int i = 0; i < k; ++i) {
		if (x + 1 + i < N || !board[y][x + i + 1])
			return (false);
	}
	return (true);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		cin >> N >> K;
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				cin >> board[i][j];
		int res = 0;
		for (int i = 0; i < N + 2 - K; ++i) {
			for (int j = 0; j < N + 2 - K; ++j) {
				if(rowCheck(i, j, K))
					++res;
			}
		}
		printf("#%d %d\n", t, res);
	}
	return (0);
}
