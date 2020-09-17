#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000007;
int cache[101];

int tiling(int width) {
	if (width <= 1) return (1);

	int &ret = cache[width];
	if (ret != -1) {
		//cout << "repeated case!\n";
		return (ret);
	}
	return (ret = (tiling(width - 1) + tiling(width - 2)) % MOD);
}

int asymmetric(int width) {
	int ret = tiling(width);
	if (width % 2 == 1)
		return (ret - tiling((width - 1) / 2) + MOD) % MOD;
	ret = (ret - tiling(width / 2) + MOD) % MOD;
	ret = (ret - tiling((width - 2) / 2) + MOD) % MOD;
	return (ret);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int C;
	cin >> C;
	int n;
	while (C--) {
		cin >> n;
		memset(cache, -1, sizeof(cache));
		cout << asymmetric(n) << "\n";
	}

	return (0);
}