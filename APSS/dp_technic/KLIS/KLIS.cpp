#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int S[500];
int cache[501];
// start 부터 만들 수 있는 lis 구하기
int lis(int start) {
	int &ret = cache[start + 1];
	if (ret != -1) {
		//cout << "repeated case!\n";
		return (ret);
	}

	ret = 1;
	for (int next = start + 1; next < N; ++next) {
		if (start == -1 || S[next] > S[start])
			ret = max(ret, 1 + lis(next));
	}
	return (ret);
}

int cacheCnt[501];
const int MAX = 2000000000 + 1;
int countLis(int start) {
	if (lis(start) == 1) return (1);
	
	int &ret = cacheCnt[start + 1];
	if (ret != -1) {
		cout << "repeated case!\n";
		return (ret);
	}

	ret = 0;
	for (int next = start + 1; next < N; ++next) {
		if (start == -1 || S[next] > S[start]) {
			// 조건을 만족시키면 count를 증가시키는 템플릿.
			if (lis(start) == 1 + lis(next))
				ret = min<long long>(MAX, (long long)ret + countLis(next)); 
		}
	}
	return (ret);
}

void reconstruct(int start, int skip, vector<int> &lisList) {
	if (start != -1) lisList.push_back(S[start]);

	vector<pair<int, int> > followers;
	for (int next = start + 1; next < N; ++next) {
		if (start == -1 || S[next] > S[start]) {
			if (lis(start) == 1 + lis(next))
				followers.push_back(make_pair(S[next], next));
		}
	} 
	sort(followers.begin(), followers.end());
	
	for (int i = 0; i < followers.size(); ++i) {
		// 지금 next를 lisList에 넣을 것인가 다음 next를 넣을 것인가 선택
		int next = followers[i].second;
		int cnt = countLis(next);
		// 지금 next를 만드는 경우의 수가, skip보다 많으므로 더 건너 뛰어야함.
		if (skip >= cnt) 
			skip -= cnt;
		// 지금 next를 넣는 경우
		else {
			reconstruct(next, skip, lisList);
			break;
		}
	}
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int K;
	cin >> N >> K;

	memset(cache, -1, sizeof(cache));
	memset(cacheCnt, -1, sizeof(cacheCnt));
	memset(S, 0, sizeof(S));
	for (int i = 0; i < N; ++i)
		cin >> S[i];

	vector<int> lisList;
	reconstruct(-1, K - 1, lisList); 
	for (int i = 0; i < lisList.size(); ++i) {
		cout << lisList[i] << " ";
	}

	return (0);
}
