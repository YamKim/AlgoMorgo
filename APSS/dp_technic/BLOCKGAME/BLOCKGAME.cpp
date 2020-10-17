#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int BOARD_SIZE = 5;

int cell(int y, int x) {
	return (1 << (y * BOARD_SIZE + x));
}

vector<int> moves;
//게임판에 놓을 수 있는 블록들의 위치를 미리 계산한다

void preCalc() {
	for (int y = 0; y < BOARD_SIZE - 1; ++y) {
		for (int x = 0; x < BOARD_SIZE - 1; ++x) {
			vector<int> cells;
			for (int dy = 0; dy < 2; ++dy)
				for (int dx = 0; dx < 2; ++dx)
					cells.push_back(cell(y + dy, x + dx));
			int square = cells[0] + cells[1] + cells[2] + cells[3];
			for (int i = 0; i < 4; ++i)
				moves.push_back(square - cells[i]);
		}
	}

	for (int j = 0; j < BOARD_SIZE; ++j) {
		for (int i = 0; i < BOARD_SIZE - 1; ++i) {
			moves.push_back(cell(j, i) + cell(j, i + 1));
			moves.push_back(cell(i, j) + cell(i + 1, j));
		}
	}
}

char cache[1 << BOARD_SIZE * BOARD_SIZE];
char play(int board) {
	char &ret = cache[board];
	if (ret != -1) {
		//cout << "repeat case!\n";
		return (ret);
	}

	ret = 0;
	for (int i = 0; i < moves.size(); ++i) {
		// 놓을 수 없으면 패스
		if ((moves[i] & board) != 0) continue ;
		// 다음 블록을 놓지 못하면 탈출
		if (play(board | moves[i]) == 0) {
			ret = 1;
			break ;
		}
	}
	// ret이 0이면 모든 moves를 고려하였음에도 놓을 자리를 찾지 못한 것.
	return (ret);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	int C;
	cin >> C;
	while (C--) {
		int board = 0;
		for (int y = 0; y < BOARD_SIZE; ++y) {
			string tmp;
			cin >> tmp;
			for (int x = 0; x < BOARD_SIZE; ++x) {
				if (tmp[x] == '#')
					board |= cell(y, x);
			}
		}
		memset(cache, -1, sizeof(cache));
		preCalc();
		if (play(board) == 1)	cout << "WINNING\n";
		else					cout << "LOSING\n";
	}

	return (0);
}
