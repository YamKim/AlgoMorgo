#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		int pad = 0;	
        cout << "#" << t << "\n";
		for (int i = 0; i < N; ++i) {
			char alpha;
			int r;
			cin >> alpha >> r;
			for (int k = 0; k < r; ++k) {
				cout << alpha;
				++pad;	
				if (pad % 10 == 0)
					cout << "\n";
			}
		}
		cout << "\n";
	}
	return (0);
}