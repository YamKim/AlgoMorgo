#include <iostream>

using namespace std;

int t;
#define PRINT_OUT()  (cout << "#" << t << " ")

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int num, div;
		cin >> num >> div;
		PRINT_OUT();
		cout << num / div << " " << num % div << "\n";
	}
	return (0);
}
