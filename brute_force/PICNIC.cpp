#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// n: 학생 수
// m: 친구 쌍 수
int n, m;

int countPairings(int idx, vector<pair<int, int> > &groups, bool taken[10]) {
	bool finished = true;
	for (int i = 0; i < n; ++i) if (!taken[i]) finished = false;
	if (finished) return (1);

	int ret = 0;
	for (int cur = idx; cur < m; ++cur) {
		if (!taken[groups[cur].first] && !taken[groups[cur].second]) {
			taken[groups[cur].first] = taken[groups[cur].second] = true;
			ret += countPairings(cur + 1, groups, taken);
			taken[groups[cur].first] = taken[groups[cur].second] = false;
		}
	}
	return (ret);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int c;
	cin >> c;
	while (c--) {
		cin >> n >> m;
		vector<pair<int, int> > list(m);
		for (int team = 0; team < m; ++team) 
			cin >> list[team].first >> list[team].second;
		bool taken[10] = { false, };
		cout << countPairings(0, list, taken) << "\n";
	}
	return (0);
}
