#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int board[17][17];
int N, K;

bool rowCheck(int y, int x, int k) {
	if (x > N) return (false);
	if (k == K) return (board[y][x + 1] == 0 ? true : false);
	if (board[y][x + 1] == 1)
		return(rowCheck(y, x + 1, k + 1));
	return(false);
}

bool colCheck(int y, int x, int k) {
	if (y > N) return (false);
	if (k == K) return (board[y + 1][x] == 0 ? true : false);
	if (board[y + 1][x] == 1)
		return(colCheck(y + 1, x, k + 1));
	return(false);
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
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N + 1 - K; ++j) {
				if (board[i][j] == 0)
					if (rowCheck(i, j, 0))
						++res;
				if (board[j][i] == 0)
					if (colCheck(j, i, 0))
						++res;
			}
	
		}
		printf("#%d %d\n", t, res);
	}
	return (0);
}
