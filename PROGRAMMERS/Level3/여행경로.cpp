#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<string>> tickets;
bool solve(vector<string> &path, int visited) {
	if (visited == ((1 << n) - 1)) return (true);
	
	string tmp = "ZZZ";
	for (int nextStart = 0; nextStart < n; ++nextStart) {
		if (visited & (1 << nextStart)) continue ;
		if (tickets[nextStart][0] != path.back()) continue;
		path.push_back(tickets[nextStart][1]);
		// 해당 경로로 들어가서 실패하는 경우가 생기면, segment fault가 생겨버림
		bool ok = solve(path, visited | (1 << nextStart));
		if (ok) return (true);
		// 현재 경로를 가지 않았던 것으로 생각하고 새로운 경로 선택
		path.pop_back();
	}
	return (false);
}

vector<string> solution(vector<vector<string>> _tickets) {
	n = _tickets.size();	
	tickets = _tickets;
	sort(tickets.begin(), tickets.end());

	vector<string> path;
	// 출발점 미리 입력
	path.push_back("ICN");
	solve(path, 0);
    return (path);
}


#include <iostream>
int main(void) {
	vector<vector<string> > tickets{{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};
	vector<string> result = solution(tickets);
#if 1
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << "\n";
	}
#endif
	return (0);	
}
