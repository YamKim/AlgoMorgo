#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string strIn;
	cin >> strIn;
	int len = strIn.size();
	for (int i = 0; i < len; ++i) {
		if (strIn[i] >= 'a' && strIn[i] <= 'z')
			strIn[i] += 'A' - 'a';
	}
	cout << strIn << "\n";

	return (0);
}
