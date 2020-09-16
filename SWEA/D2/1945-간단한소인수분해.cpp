#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int cnt[5] = { 0, };
const int nums[5] = {2, 3, 5, 7, 11};

void solve(int N) {
	if (N == 1) return ;
	for (int i = 0; i < 5; ++i) {
		if (N % nums[i] == 0) {
			++cnt[i];
			solve(N / nums[i]);	
			break ;
		}
	}	
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		memset(cnt, 0, sizeof(cnt));
		solve(N);
		printf("#%d ", t);
		for (int i = 0; i < 5; ++i)
			printf("%d ", cnt[i]);
		printf("\n");
	}
	return (0);
}
