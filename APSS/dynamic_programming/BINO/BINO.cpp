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
int binoDp(int n, int r) {
	cout << "n: " << n << ", ";
	cout << "r: " << r << "\n";	
	if (r == 0 || r == n) return (1);
	int &ret = cache[n][r];
	if (ret != -1) {
		cout << "repeated value!\n";
		return (ret);
	}

	return (ret = binoDp(n - 1, r - 1) + binoDp(n - 1, r));
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
