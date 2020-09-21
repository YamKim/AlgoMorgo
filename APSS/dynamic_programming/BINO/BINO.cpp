#include <iostream>
#include <cstring>

using namespace std;

int bino(int n, int r) {
	cout << "n: " << n << ", ";
	cout << "r: " << r << "\n";	
	if (r == 0 || r == n) return (1);
	return (bino(n - 1, r - 1) + bino(n - 1, r));
}

#define MAX_SIZE (30)
int cache[MAX_SIZE][MAX_SIZE];
// 특정 nCr을 위한 binoDp
int binoDp(int n, int r) {
	cout << "n: " << n << ", ";
	cout << "r: " << r << "\n";	
	int &ret = cache[n][r];
	if (r == 0 || r == n) return (ret = 1);
	if (ret != -1) {
		cout << "repeated value!\n";
		return (ret);
	}

	return (ret = binoDp(n - 1, r - 1) + binoDp(n - 1, r));
}

int binoArr[MAX_SIZE][MAX_SIZE];
void binoArrCalc() {
	memset(binoArr, 0, sizeof(binoArr));
	for (int n = 0; n <= 200; ++n) {
		binoArr[n][0] = binoArr[n][n] = 1;
		for (int r = 1; r < n; ++r) {
			binoArr[n][r] = binoArr[n - 1][r - 1] + binoArr[n][r];
		}
	}
}



int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, r;
	cin >> n >> r;
	memset(cache, -1, sizeof(cache));
	cout << binoDp(n, r) << "\n";
	return (0);
}
