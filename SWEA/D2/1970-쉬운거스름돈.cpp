#include <iostream>

using namespace std;

const int changes[8] = {50000, 10000, 5000, 1000, 500, 100, 50, 10};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		printf("#%d\n", t);
		for (int i = 0; i < 8; ++i) {
			int div = N / changes[i];
			if (N >= changes[i]) {
				N %= changes[i];
			}
			printf("%d ", div);
		}
		printf("\n");
	}
	return (0);
}
