#include <iostream>
#include <vector>

using namespace std;

const int dx[8] = {-1,  0,  1, 1, 1, 0, -1, -1};
const int dy[8] = {-1, -1, -1, 0, 1, 1,  1,  0};
const int H = 5;
const int W = 5;

vector<string> board(H);

bool inRange(int y, int x) {
	if (y >= 0 && y <= H && x >= 0 && x <= W)
		return (true);
	return (false);
}

bool hasWord(int y, int x, const string &word) {
	if (!inRange(y, x))			return (false);
	if (board[y][x] != word[0]) return (false);
	if (word.size() == 1)		return (true);

	for (int dir = 0; dir < 8; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		if (hasWord(ny, nx, word.substr(1)))
			return (true); 
	}	
	return (false);
}

bool search(int y, int x, const string &word)
{
	for (int y = 0; y < H; ++y) {
		for (int x = 0; x < W; ++x) {
			if (hasWord(y, x, word))
				return (true);
		}
	}
	return (false);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int c;
	cin >> c;
	while (c--) {
		for (int i = 0; i < 5; ++i) 
			cin >> board[i];

		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			string str;
			cin >> str;
			if (search(0, 0, str))
				cout << str << " YES\n";
			else
				cout << str << " NO\n";
		}
	}

	return (0);
}
