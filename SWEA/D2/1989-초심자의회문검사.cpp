#include <iostream>

using namespace std;

string str;
int palindrome(int beg, int end) {
	if (beg >= end) return (0);

	int ret = 0;
	if (str[beg] == str[end])
		ret += 1 + palindrome(beg + 1, end - 1);

	return (ret); 
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		cin >> str;
		printf("#%d %d\n", t, (bool)(palindrome(0, str.size() - 1)));
	}
	return (0);
}
