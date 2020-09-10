#include <iostream>
#include <cstring>

using namespace std;

string N;

int classify(int a, int b) {
	string M = N.substr(a, b - a + 1);
	int upStep = 0;
	int loStep = 0;
	int eqStep = 0, prevInt = M[1] - M[0];
	for (int i = 0; i < M.size() - 1; ++i) {
		int curInt = M[i + 1] - M[i];
		if (curInt == 1)	++upStep;
		if (curInt == -1)	++loStep;
		if (curInt == prevInt) {
			++eqStep;
			prevInt = curInt;
		}
	}
	if (upStep == b - a || loStep == b - a)
		return (2);
	if (prevInt == 0 && eqStep == b - a)
		return (1);
	else if (prevInt != 0 && eqStep == b - a)
		return (5);

	bool alternating = true;
	for (int i = 0; i < M.size(); ++i)
		if (M[i] != M[i % 2]) // %를 사용해서 짝수 고르기!
			alternating = false;
	if (alternating)
		return (4);

	return (10);
}

#if 1
int cache[10002];
const int INF = 987654321;
int memorize(int begin) {
	if (begin == N.size()) return (0);		

	int &ret = cache[begin];
	if (ret != -1) {
		cout << "repeated value!\n";
		return (ret);
	}
	ret = INF;
	for (int L = 2; L <= 4; ++L) {
		if (begin + L <= N.size())
			ret = min(ret, classify(begin, begin + L) + memorize(begin + L + 1));
	}
	
	return (ret);
}
#endif

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int C;
	cin >> C;

	while (C--) {
		cin >> N;
		memset(cache, -1, sizeof(cache));
		cout << memorize(0) << "\n";	
	}

	return (0);
}
