#include <iostream>
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

int countCache[100][100];
// (y, x)부터 끝까지 들어갈 때의 최대경로의 개수를 세는 함수
int count(int y, int x) {
	if (y == n - 1) return (1);
	int &ret = countCache[y][x];
	if (ret != -1) {
		cout << "repeated case!\n";
		return (ret);
	}
	ret = 0;
	if (path(y + 1, x) >= path(y + 1, x + 1)) ret += count(y + 1, x);
	if (path(y + 1, x) <= path(y + 1, x + 1)) ret += count(y + 1, x + 1);
	
	return (ret);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int C;
	cin >> C;
	while (C--) {
		cin >> n;
		memset(cache, -1, sizeof(cache));
		memset(countCache, -1, sizeof(countCache));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j <= i; ++j)
				cin >> triangle[i][j]; 	

		cout << count(0, 0) << "\n";
	}
	return (0);
}
