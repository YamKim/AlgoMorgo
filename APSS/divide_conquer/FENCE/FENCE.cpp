#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 987654321;

vector<int> h;
int brute_force() {
	int ret = -1;
	for (int beg = 0; beg < h.size(); ++beg) {
		int minHeight = INF;
		for (int end = beg; end < h.size(); ++end) {
			if (minHeight > h[end]) minHeight = h[end];
			ret = max(ret, minHeight * (end - beg + 1));
		}
	}
	return (ret);
}

int solve(int left, int right) {
	if (left == right) return (h[right]);
	
	int mid = (left + right) / 2;
	int lo = mid, hi = mid + 1;
	int ret = max(solve(left, lo), solve(hi, right));
	// 기준 넓이를 잡기(초기값을 잡고 비교)
	// 가장 가운데 두 블록 중 낮은 높이 블록 x 2(너비)
	int minHeight = min(h[lo], h[hi]);
	ret = max(ret, minHeight * 2);

	while (left < lo || hi < right) {
		// right expansion 조건
		// left < lo인 경우로 while이 동작하는 것일수도 있으므로
		if (hi < right && (lo == left || h[hi + 1] > h[lo - 1])) {
			++hi;
			minHeight = min(minHeight, h[hi]);
		}
		else if (left < lo && (hi = right || h[lo - 1] > h[hi + 1])) {
			--lo;
			minHeight = min(minHeight, h[lo]);
		}
		ret = max(ret, ((hi - lo + 1) * minHeight));
	}
	return (ret);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	h.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> h[i];
	
	cout << solve(0, N - 1) << "\n";
	return (0);
}
