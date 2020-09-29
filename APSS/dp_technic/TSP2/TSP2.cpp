#include <iostream>

using namespace std;

const int MAX = 8;
const double INF = 987654321.0;

int N;
double dist[MAX][MAX];
double cache[MAX][1<<MAX];
double shortestPath(int here, int visited) {
	if (visited == (1 << N) - 1) return (0.0);
	double &ret = cache[here][visited];
	if (ret != -1.0) {
		//cout << "repeated case!\n";
		return (ret);
	} 
	
	ret = INF;
	for (int next = 0; next < N; ++next) {
		if (visited & (1 << next)) continue;
		double cand = dist[here][next] + shortestPath(next, visited | (1 << next));
		ret = min(ret, cand);
	}

	return (ret);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int C;
	cin >> C;

	while (C--) {
		cin >> N;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				cin >> dist[i][j];

		for (int i = 0; i < MAX; ++i)
			for (int j = 0; j < (1 << MAX); ++j)
				cache[i][j] = -1.0;

		double minResult = INF;
		for (int i = 0; i < N; ++i)
			minResult = min(minResult, shortestPath(i, 0)); 
		cout << fixed;
		cout.precision(10);
		cout << minResult << "\n";
	}

	return (0);
}
