#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int lengthPattern(int start, string pattern, string part) {
	int len = pattern.size();
	if (start != 0 && pattern == part.substr(0, len)) return (len);
	else if (start != 0) return (0);

	int ret = 0;
	for (int L = 0; L < part.size(); ++L) {
		ret += lengthPattern(start + L, part.substr(0, L), part.substr(L + 1, part.size()));	
	}
	return (ret);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		string tmp;
		cin >> tmp;
		lengthPattern(0, "", tmp);

	}

	return (0);
}


