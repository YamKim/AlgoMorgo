#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		const int N = 10;
		vector<int> seq(N);
		for (int i = 0; i < N; ++i)
			cin >> seq[i];
		sort(seq.begin(), seq.end());
		int avg = 0;
		for (int i = 1; i < N - 1; ++i)
			avg += seq[i];
		avg = (0.5 + (double)avg / (N - 2));
		printf("#%d %d\n", t, avg);
	}
	return (0);
}
