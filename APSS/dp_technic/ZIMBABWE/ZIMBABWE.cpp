#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdlib.h>

using namespace std;

string e, digits;
int n, m;

bool visitCheck(int taken, int n) {
	if (taken & (1 << n)) return (true);
	return (false);
}

void generate(string price, int taken) {
	if (taken == (1 << n) - 1) {
		if (e > price)
			cout << price << "\n";
		return ;
	}

	for (int next = 0; next < n; ++next) {
		if (visitCheck(taken, next)) continue; 
		if (next == 0 || digits[next - 1] != digits[next] || visitCheck(taken, next - 1)) {
			// string의 자릿수를 추가해서 재귀
			generate(price + digits[next], taken | (1 << next));
		}
	}
}

const int MOD = 1000000007;
int cache[1<<14][20][2];
// 1. cache 구성 이유
// 2. 중복값 방지하기 위해 사용한 기법 설명
// 3. 나머지값 넘길 때 요약해서 넘기는 방법 설명
// 4. less 원리.

int price(int index, int taken, int mod, int less) {
	if (index == n)
		return ((mod == 0 && less == 1) ? 1 : 0);
	int &ret = cache[taken][mod][less];
	if (ret != -1) {
		//cout << "repeated case!\n";
		return (ret);
	}

	ret = 0;
	for (int next = 0; next < n; ++next) {
		// less가 false이면(만들 수가 더 크면) 무조건 패스
		// less가 true여서 만들 숫자가 작아와도 지금 만들 수가 크면 패스
		if (!less && e[index] < digits[next]) continue;
		if (visitCheck(taken, next)) continue;
		// generate에서 줬던 옵션의 여집합
		if (next > 0 && digits[next - 1] == digits[next] && !visitCheck(taken, next - 1))
			continue;
		int nextTaken = taken | (1 << next);
		int nextMod = (mod * 10 + (digits[next] - '0')) % m;
		int nextLess = less || e[index] > digits[next];
		ret += price(index + 1, nextTaken, nextMod, nextLess);
		ret %= MOD;
	}
	return (ret);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int C;
	cin >> C;
	while (C--) {
		cin >> e >> m;
		digits = e;
		sort(digits.begin(), digits.end());
		memset(cache, -1, sizeof(cache));
		n = e.size();
		cout << price(0, 0, 0, 0) << "\n";
	}

	return (0);
}
