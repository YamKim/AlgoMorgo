#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int cache[11][11];
int bino(int n, int r) {
	int &ret = cache[n][r];
	if (ret != -1) return (ret);
	if (r == 0 || r == n) return (ret = 1);
	return (ret = bino(n - 1, r - 1) + bino(n - 1, r));
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		int n;
		cin >> n;
		memset(cache, -1, sizeof(cache));
		printf("#%d\n", t);
		cache[0][0] = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= i; ++j) {
				printf("%d ", bino(i, j));
			}
			printf("\n");
		}
	}

	return (0);
}
