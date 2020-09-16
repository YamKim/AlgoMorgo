#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int board[11][11];
int dirSelect = 0;
const int dir[4][2] = {
	{0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

void fillValue(int y, int x, int num) {
	int dirSelect = 0;
	if (num == N * N + 1) return ;
	board[y][x] = num;
	int ny = y + dir[dirSelect][0];
	int nx = x + dir[dirSelect][1];
	// 끝점에 도달하면 방향 바꾸기
	if (ny < 0 || ny >= N || nx < 0 || nx >= N || board[ny][nx] != 0) {
		dirSelect += 1;
		dirSelect %= 4;	
		ny = y + dir[dirSelect][0];
		nx = x + dir[dirSelect][1];
		fillValue(ny, nx, num + 1);
	}
	// 가던 길로 직진
	else
		fillValue(ny, nx, num + 1);
} 

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		cin >> N;
		memset(board, 0, sizeof(board));
		dirSelect = 0;
		fillValue(0, 0, 1);
		printf("#%d\n", t);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j)
				printf("%d ", board[i][j]);
			printf("\n");
		}
	}
	return (0);
}
