#include <iostream>
#include <cstring>

using namespace std;

bool match(const string &W, const string &S) {
	int pos = 0;

	while (pos < W.size() && pos < S.size()) {
		if (W[pos] == '?' || W[pos] == S[pos])	
			++pos;
		else break;
	}

	if (pos == W.size())
		return (pos == S.size());
	
	if (W[pos] == '*') {
		for (int skip = 0; pos + skip < S.size(); ++skip) {
			// if (w[pos + 1] == s[pos + skip])
			if (match(W.substr(pos + 1), S.substr(pos + skip))) {
				return (true);
			}
		}
	}

	return (false);
}


#define CACHE_SIZE (101)
string W, S;
int cache[CACHE_SIZE][CACHE_SIZE];

int matchMemoized(int w, int s) {
	int &ret = cache[w][s];
	if (ret != -1) return ret;
	
	while (w < W.size() && s < S.size()) {
		if (W[w] == '?'|| W[w] == S[s]) {
			++w;
			++s;
		}
		else break;
	}
	
	if (w == W.size())
		return (ret = (s == S.size()));

	if (W[w] == '*') {
		for (int skip = 0; s + skip <= S.size(); ++skip) {
			// 탈출조건이 size이므로, s.size()가 matchMemoized에 대입될 때,
			// 탈출조건이 성립하게 됨.
			if (matchMemoized(w + 1, s + skip))
				return (ret = 1);
		}
	}
	// *a와 ab를 비교시, *a 재귀 후 a가 ab랑 같지 않으므로
	return (ret = 0);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> W;
	int N;
	cin >> N;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < N; ++i) {
		cin >> S;
		if (matchMemoized(0, 0)) 
			cout << S << "\n";
	}

	return (0);
}
