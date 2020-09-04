#include <iostream>
#include <vector>

using namespace std;

void printPicked(vector<int> list) {
	for (int i = 0; i < ((int)list.size()); ++i)
		cout << list[i] << " ";
	cout << "\n";
}

void pick(int n, vector<int> &picked, int toPick) {
	if (!toPick) printPicked(picked);

	// 가장 뒤의 수보다 큰 값에서부터 새로 고르기.
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	for (int next = smallest; next < n; ++next) {
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// n개의 원소중 m개의 원소를 골라서 출력
	int n, m;
	cin >> n >> m;
	vector<int> list;
	pick(n, list, m);
	return (0);
}
