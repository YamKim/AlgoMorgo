#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cout << (1 << i) << " ";
	}
	cout << (1 << N) << "\n";

	return (0);
}
