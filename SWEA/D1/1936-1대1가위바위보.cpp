#include <iostream>

using namespace std;

const char scoreMap[3][3] = {
	{'X', 'B', 'A'},
	{'A', 'X', 'B'},
	{'B', 'A', 'X'}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int A, B;
	cin >> A >> B;
	
	cout << scoreMap[A - 1][B - 1] << "\n";

	return (0);
}
