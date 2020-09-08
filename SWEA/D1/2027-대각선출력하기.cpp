#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (i == j) {
				cout << "#";
				continue ;
			}
			cout << "+";
		}
		cout << "\n";
	}
	return (0);
}
