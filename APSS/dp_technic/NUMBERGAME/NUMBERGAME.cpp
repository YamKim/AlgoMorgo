#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 50;
const int EMPTY = -987654321;
int n;
int board[MAX_SIZE];
int cache[MAX_SIZE][MAX_SIZE];

int play(int left, int right) {
	if (left > right) return (0);
	
	int &ret = cache[left][right];
	if (ret != EMPTY) {
		//cout << "repeated case!\n";
		return (ret);
	}

	ret = max(ret, board[left] - play(left + 1, right)); // pick left
	ret = max(ret, board[right] - play(left, right - 1)); // pick right
	if (right - left + 1 >= 2) {
		ret = max(ret, 0 - play(left + 2, right)); // delete left
		ret = max(ret, 0 - play(left, right - 2)); // delete right
	}
	return (ret);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int C;
	cin >> C;
	while (C--) {
		for (int i = 0; i < MAX_SIZE; ++i)
			for (int j = 0; j < MAX_SIZE; ++j)
				cache[i][j] = EMPTY;

		cin >> n;	
		for (int i = 0; i < n; ++i)
			cin >> board[i];
		cout << play(0, n - 1) << "\n";	
	}
	return (0);
}
