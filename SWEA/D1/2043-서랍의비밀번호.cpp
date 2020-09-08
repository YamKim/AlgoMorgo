#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int P, K;
	cin >> P >> K;
	cout << P - K + 1 << "\n";
	return (0);
}
