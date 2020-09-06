#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_SIZE (100)
int n;
int board[MAX_SIZE][MAX_SIZE];
int cache[MAX_SIZE][MAX_SIZE];

int solve(int y, int x) {
	if (y >= n || x >= n)			return (0);
	if (y == n - 1 && x == n - 1)	return (1); 

	int &ret = cache[y][x];
	if (ret != -1) {
		//cout << "repeated value!\n";
		return (ret);
	}
	int jumpSize = board[y][x];
	return (ret = solve(y + jumpSize, x) || solve(y, x + jumpSize));
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];
	memset(cache, -1, sizeof(cache));
	if (solve(0, 0))
		cout << "YES\n";
	else
		cout << "NO\n";
	return (0);
}
