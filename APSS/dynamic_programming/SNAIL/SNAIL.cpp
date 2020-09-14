#include <iostream>

using namespace std;

int n, m;
const int MAX_SIZE = 1001;
double cache[MAX_SIZE][MAX_SIZE * 2 + 1];

double climb(int days, int climbed) {
	if (climbed >= n) return (1.0);
	if (days >= m) return (0.0);

	double &ret = cache[days][climbed];
	if (ret != -1.0) {
		cout << "repeated case!\n";
		return (ret);
	}

	ret = 0.0;	
	ret += 0.25 * climb(days + 1, climbed + 1);
	ret += 0.75 * climb(days + 1, climbed + 2);

	return (ret);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < MAX_SIZE; ++i)
		for (int j = 0; j < MAX_SIZE * 2 + 1; ++j)
			cache[i][j] = -1.0;

	cout.precision(11);
	cout << climb(0, 0) << "\n";

	return (0);
}
