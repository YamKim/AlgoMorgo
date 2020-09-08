#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string strIn;
	cin >> strIn;

	int len = strIn.size();
	for (int i = 0; i < len; ++i) {
		int tmp = strIn[i] - 'A' + 1;
		if (i == len - 1)
		{
			cout << tmp << "\n";
			break ;
		}
		cout << tmp << " ";
	}

	return (0);
}
