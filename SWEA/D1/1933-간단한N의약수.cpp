#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i < N; ++i) {
		if (N % i == 0) cout << i << " ";
	}
	cout << N << "\n";

	return (0);
}
