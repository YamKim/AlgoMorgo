#include <iostream>

using namespace std;

int sum(int n) {
	int ret = 0;
	for (int i = 1; i <= n; ++i)
		ret += i;	
	return (ret);
}

int recursiveSum(int n) {
	// 탈출 조건
	// 쪼개지지 않는 가장 작은 작업: 기저 사례(base case)
	if (n == 1) return (1);
	return (n + recursiveSum(n - 1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	cout << "loop:      " << sum(n);
	cout << "\n";
	cout << "recursive: " << recursiveSum(n);
	cout << "\n";
	return (0);
}


