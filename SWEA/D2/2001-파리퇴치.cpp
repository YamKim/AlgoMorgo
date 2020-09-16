#include <iostream>

using namespace std;

int N, M;
int board[16][16];

int totFlies(int y, int x) {
	int ret = 0;
	for (int j = 0; j < M; ++j) {
		for (int i = 0; i < M; ++i) {
			ret += board[y + j][x + i];
		}
	}
	return (ret);
}

int huntFly(void) {
	int ret = -1;
	for (int y = 0; y + M <= N; ++y) {
		for (int x = 0; x + M <= N; ++x) {
			ret = max(ret, totFlies(y, x));	
		}
	}
	return (ret);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N >> M;
		for (int i = 0; i < N; ++i) 
			for (int j = 0; j < N; ++j)
				cin >> board[i][j];
		printf("#%d %d\n", t, huntFly());
	}
	return (0);
}
