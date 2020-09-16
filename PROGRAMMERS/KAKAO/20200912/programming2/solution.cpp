#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int cntPopular(vector<string> &orders, string pick) {
	int ret = 0;
	int len = pick.length();

	for (int i = 0; i < orders.size(); ++i) {
		int cnt = 0;
		for (int j = 0; j < pick.length(); ++j) {
			if(orders[i].find(pick[j]) != -1)
				++cnt;
		}
		if (cnt == pick.length())
			++ret;
	}

	return (ret);
}

bool repeated(string pick) {
	for (int i = 0; i < pick.length(); ++i) {
		for (int j = i + 1; j < pick.length(); ++j) {
			if (pick[i] == pick[j])
				return (true);
		}
	}
	return (false);
}

int select(vector<string> &orders, string totOrder, vector<bool> visited, int idx, string pick, int orderNum) {
	if (repeated(pick)) return (-1);
	if (pick.length() == orderNum)
		return (cntPopular(orders, pick));

	int ret = -1;
	for (int i = idx; i < totOrder.length(); ++i) {
		if (visited[i]) continue;
		visited[i] = true;
		pick.push_back(totOrder[i]);
		ret = max(ret, select(orders, totOrder, visited, i + 1, pick, orderNum));
		visited[i] = false;
		pick.pop_back();
	}
	return (ret);
}

int genMenu(vector<string> &orders, string totOrder, vector<bool> visited, int idx, string pick, int orderNum, int bestPick, vector<string> &menu) {
	if (repeated(pick)) return (-1);
	if (pick.length() == orderNum)
		return (cntPopular(orders, pick));

	int ret = -1;
	for (int i = idx; i < totOrder.length(); ++i) {
		if (visited[i]) continue;
		visited[i] = true;
		pick.push_back(totOrder[i]);
		ret = genMenu(orders, totOrder, visited, i + 1, pick, orderNum, bestPick, menu);
		if (ret == bestPick && bestPick > 1 && pick.size() == orderNum)
			menu.push_back(pick);
		pick.pop_back();
		visited[i] = false;
	}
	return (ret);
}

vector<string> solution(vector<string> orders, vector<int> course) {
	string totOrder = "";
	for (int i = 0; i < orders.size(); ++i) {
		for (int j = 0; j < orders[i].size(); ++j) {
			bool ok = true;
			for (int k = 0; k < totOrder.size(); ++k) {
				if (totOrder[k] == orders[i][j])
					ok = false;	
			}
			if (ok) totOrder += orders[i][j];
		}
	}
	sort(totOrder.begin(), totOrder.end());
	
	vector<string> menu;
	for (int i = 0; i < course.size(); ++i) {
		vector<bool> visited(totOrder.length(), false);
		int bestNum = select(orders, totOrder, visited, 0, "", course[i]);
		genMenu(orders, totOrder, visited, 0, "", course[i], bestNum, menu);
	}
	sort(menu.begin(), menu.end());
	for (int i = 0; i < menu.size(); ++i)
		cout << menu[i] << "\n";
	return (menu);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<string> orders{"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"};
	vector<int> course{2, 3, 5};
	solution(orders, course);
	
	return(0);
}
