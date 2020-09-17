#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 10000000;

int cache[101][101];
int poly(int n, int first) {
	// n개 남고, 현재 첫 줄이 n개라면 탈출
	if (n == first) return (1);
	int &ret = cache[n][first];
	if (ret != -1) {
		//cout << "repetead case!\n";
		return (ret);
	}
	ret = 0;
	for (int second = 1; second <= n - first; ++second) {
		// 현재층을 빼주고 남은 만큼이 다음 줄로 사용 가능.
		ret += (poly(n - first, second) * (first + second - 1)) % MOD; 
		ret %= MOD;
	}
	return (ret);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	memset(cache, -1, sizeof(cache));
	int res = 0;
	for (int first = 1; first <= n; ++first) {
		res += poly(n, first);	
		res %= MOD;
	}
	cout << res << "\n";	

	return (0);
}
