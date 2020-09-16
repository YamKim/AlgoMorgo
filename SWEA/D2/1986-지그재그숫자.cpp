#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N;
		cin >> N;

		int res = 0;
		for (int i = 1; i <= N; ++i) {
			if (i % 2 == 0) res -= i;
			else res += i;
		}
		printf("#%d %d\n", t, res);
	}
	return (0);
}
