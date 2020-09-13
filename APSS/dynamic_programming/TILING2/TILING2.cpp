#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000007;

int cache[101];

int tiling(int width) {
	if (width <= 1) return (1);

	int &ret = cache[width];
	if (ret != -1) {
		cout << "repeated case!\n";
		return (ret);
	}

	return (ret = (tiling(width - 1) + tiling(width - 2)) % MOD);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	memset(cache, -1, sizeof(cache));
	cout << tiling(n) << "\n"; 

	return (0);
}
