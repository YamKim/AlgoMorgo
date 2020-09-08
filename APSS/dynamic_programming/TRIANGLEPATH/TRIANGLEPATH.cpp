#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int triangle[100][100];
int cache[100][100];

int path(int y, int x) {
	if (y >= n) return (0);
	int &ret = cache[y][x];
	if (ret != -1) {
		//cout << "repeated value!\n";
		return (ret);
	}
	
	int maxVal = max(path(y + 1, x), path(y + 1, x + 1));
	return (ret = triangle[y][x] + maxVal);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int C;
	cin >> C;
	while (C--) {
	cin >> n;
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < i + 1; ++j)
				cin >> triangle[i][j]; 
		cout << path(0, 0) << "\n";
	}
	return (0);
}
