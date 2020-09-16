#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const char clap[3] = {'3', '6', '9'};

string check369(const string &N) {
	bool clapOk = false;
	string ret = "";
	for (int digit = 0; digit < N.size(); ++digit) {
		for (int i = 0; i < 3; ++i) {
			if (N[digit] == clap[i]) {
				ret += "-";
				clapOk = true;
			}
		}
	}

	return (clapOk ? ret : N);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i) {
		string tmp = to_string(i);
		cout << check369(tmp) << " ";
	}
	cout << "\n";

	return (0);
}
