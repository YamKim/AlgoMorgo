#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	string N;
	cin >> N;

	int ret = 0;
	for (int i = 0; i < N.size(); ++i) {
		ret += N[i] - '0';
	}

	cout << ret << "\n";
	
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
