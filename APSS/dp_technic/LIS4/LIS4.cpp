#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int S[101];

int cache[101], choices[101];
int lis4(int start) {
	if (start == n) return (0);	

	int &ret = cache[start + 1];
	if (ret != -1) {
		//cout << "repeated case!\n";
		return (ret);
	}

	ret = 1;
	int bestNext = -1;
	for (int next = start + 1; next < n; ++next) {
		if (start == -1 || S[next] > S[start]) {
			if (ret < 1 + lis4(next)) {
				ret = max(ret, 1 + lis4(next));
				bestNext = next;
			}
		}
	}
	choices[start + 1] = bestNext;
	
	return (ret);
}

void reconstruct(int start, vector<int> &seq) {
	if (start != -1) seq.push_back(S[start]);
	int next = choices[start + 1];
	if (next != -1) reconstruct(next, seq);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> S[i];
	memset(cache, -1, sizeof(cache));
	cout << lis4(-1) - 1 << "\n";
	vector<int> seq;
	reconstruct(-1, seq);
	for (int i = 0; i < seq.size(); ++i)
		cout << seq[i] << " ";
	cout << "\n";
	return (0);
}
