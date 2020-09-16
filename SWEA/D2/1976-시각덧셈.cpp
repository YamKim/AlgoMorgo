#include <iostream>

using namespace std;

int t;

void solve(int h, int m) {
	if (m > 59) {
		h += 1;
		m -= 60;
	}
	if (h > 12) h -= 12;
	cout << "#" << t << " " << h << " " << m << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	t = 0;
	for (t = 1; t <= T; ++t) {
		int h = 0, m = 0;
		for (int i = 0; i < 2; ++i) {
			int clock[2];
			cin >> clock[0] >> clock[1];
			h += clock[0];
			m += clock[1];
		}
		solve(h, m);
	}
	return (0);
}
