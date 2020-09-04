#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10
#define INF (double)987654321.0

int 	N;
double	dist[MAX][MAX];

double	shortestPath(vector<int> &path, vector<bool> &visited, double currentLength) {
	if (path.size() == N) 
		return (currentLength);

	double ret = INF;
	for (int next = 0; next < N; ++next) {
		if (visited[next]) continue;
		int here = path.back();
		path.push_back(next);
		visited[next] = true;
		double cand = shortestPath(path, visited, dist[here][next] + currentLength);
		ret = min(ret, cand);	
		path.pop_back();
		visited[next] = false;
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> dist[i][j];
		}
	}

	double ret = INF;
	for (int beg = 0; beg < N; ++beg) {
		vector<int> path;
		vector<bool> visited(N, false);
		path.push_back(beg);
		visited[beg] = true;
		ret = min(ret, shortestPath(path, visited, 0.00));
	}

	cout << ret;

	return (0);
}
