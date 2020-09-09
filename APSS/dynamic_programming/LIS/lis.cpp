#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n;
int S[100], cache[101];

int lis(int start) {
	// start가 -1부터 시작. 인덱스는 0부터로 맞춰주기
	int &ret = cache[start + 1];
	if (ret != -1) {
		//cout << "repetead value!\n";
		return (ret);
	}
	ret = 1; // S[start]뒤에 보다 큰 수가 없으면 return 1
	for (int next = start + 1; next < n; ++next)
		if (start == -1 || S[start] < S[next])
			// lis를 호출할 때마다 1씩 증가.
			ret = max(ret, 1 + lis(next));
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
		for (int i = 0; i < n; ++i)
			cin >> S[i];

		cout << lis(-1) - 1 << "\n";	
	}

	return (0);
}
