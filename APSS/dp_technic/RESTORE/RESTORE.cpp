#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 15;
string words[MAX_N];
int k;

void generate(string word, int taken) {
	if (taken == (1 << k) - 1) {
		cout << word << "\n";
		return ;
	}

	for (int next = 0; next < k; ++next)  {
		if (taken & (1 << next)) continue;
		generate(word + words[next], taken | (1 << next));
	}
}

int overlap[MAX_N][MAX_N];
int calcOverlap(string &word1, string &word2) {
	int ret = 0;
	int n = word1.size();
	int m = word2.size();
	for (int l = 0; l < m; ++l) {
		int cnt = 0;
		int i = n - 1 - l;
		int j = 0;
		while (i < n && j < m) {
			if (word1[i] == word2[j]) ++cnt;
			else {
				cnt = 0;
				break ;	
			}
			++i;
			++j;
		}
		ret = max(ret, cnt);
	}
	return (ret);
}

void preCalc() {
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < k; ++j) {
			if (i == j) continue ;
			overlap[i][j] = calcOverlap(words[i], words[j]);	
		}
	}
}

// 마지막에 출현한 조각 last와 지금까지 출현한 조각이 주어질 때, 
// 나머지를 추가해서 얻을 수 있는 overlap의 최대 합.
// cache는 현재 선택된 단어와 그때까지 어떤 word를 사용했는가
int cache[MAX_N][1<<MAX_N];
int restore(int last, int used) {
	if (used == (1 << k) - 1) return (0);

	int &ret = cache[last][used];
	if (ret != -1) {
		cout << "repeated case!\n";
		return (ret);
	}	

	ret = 0;
	for (int next = 0; next < k; ++next)  {
		if (used & (1 << next)) continue;
		int cand = overlap[last][next] + restore(next, used | (1 << next));
		// 겹치는 최대 길이를 반환
		ret = max(ret, cand);
	}
	return (ret);
}

string reconstruct(int last, int used) {
	if (used == (1 << k) - 1) return ("");

	for (int next = 0; next < k; ++next) {
		if (used & (1 << next)) continue;
		int cand = overlap[last][next] + restore(next, used | (1 << next));
		// 만약, next를 이 뒤에 추가했을 때의 overlap과 
		// 추가하지 않았을 때의 overlap이 같으면, 얘를 추가해야 최대.
		if (restore(last, used) == cand)
			// 시작시 last가 k부터이므로 words[next]부터 출력
			return (words[next].substr(overlap[last][next])
					 + reconstruct(next, used | (1 << next)));
	}
	return "***oops***"; 
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int C;
	cin >> C;
	while (C--) {
		cin >> k;
		
		for (int i = 0; i < k; ++i)
			cin >> words[i];
		preCalc();
		memset(cache, -1, sizeof(cache));
		// 넣는 값 주의!!!!!!!!!!
		// 0을 넣으면 0은 무조건 포함하게 됨.
		//cout << restore(k, 0) << "\n";
		cout << reconstruct(k, 0) << "\n";
	}
	 
	return (0);
}
