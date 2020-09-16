#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int date[13] = {
	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		int month[2], day[2];
		cin >> month[0] >> day[0];
		cin >> month[1] >> day[1];

		int addition = 0;
		if (month[0] != month[1]) {
			for (int i = month[0] + 1; i < month[1]; ++i)
				addition += date[i];
			addition += date[month[0]];
		}
		int res = day[1] - day[0] + 1 + addition;
		printf("#%d %d\n", t, res);
	}
	return (0);
}
