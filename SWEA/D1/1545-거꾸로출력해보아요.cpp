#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = N; i > 0; --i)
		cout << i << " ";
	cout << 0 << "\n";

	return (0);
}
