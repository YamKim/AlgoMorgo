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
		int N;
		cin >> N;
		vector<int> seq(N);
		for (int i = 0; i < N; ++i)
			cin >> seq[i];
		sort(seq.begin(), seq.end());
		printf("#%d ", t);
		for (int i = 0; i < N; ++i)
			printf("%d ", seq[i]);
		printf("\n");
	}
	return (0);
}
