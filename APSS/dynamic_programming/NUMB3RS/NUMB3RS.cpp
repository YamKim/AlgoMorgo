#include <iostream>

using namespace std;

const int MAX_VIL = 51;
const int MAX_DAY = 101;

int n, d, p, q;
int connected[MAX_VIL][MAX_VIL];
int deg[MAX_VIL];

void preCalc() {
	for (int here = 0; here < n; ++here) {
		deg[here] = 0;
		for (int next = 0; next < n; ++next)
			deg[here] += connected[here][next];
	}
}

double cache[MAX_VIL][MAX_DAY];
void initializeCache() {
	for (int i = 0; i < MAX_VIL; ++i)
		for (int j = 0; j < MAX_DAY; ++j)
			cache[i][j] = -1.0;
}

double search(int here, int days) {
	if (days == 0) return (here == q ? 1.0 : 0.0);

	double &ret = cache[here][days];
	if (ret > -0.5) {
		//cout << "repeated case!\n";
		return (ret);
	}

	ret = 0.0;
	for (int next = 0; next < n; ++next) {
		if (connected[here][next]) {
			ret += search(next, days - 1) / deg[here];
		}
	}
	
	return (ret);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int C;
	cin >> C;
	while (C--) {
		cin >> n >> d >> p;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> connected[i][j]; 
		preCalc();

		int t;
		cin >> t;
		for (int i = 0; i < t; ++i) {
			cin >> q;
			initializeCache();
			cout << search(p, d) << " ";
		}
		cout << "\n";
	}

	return (0);
}
