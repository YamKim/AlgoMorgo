
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	cout << (N * (N + 1)) / 2 << "\n";

	return (0);
}
