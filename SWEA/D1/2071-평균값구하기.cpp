#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		double sum = 0.0;

		for (int i = 0; i < 10; ++i) {
			double tmp;
			cin >> tmp;

			sum += tmp;
		}
		cout << "#" << test_case << " " << round(sum / 10) << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
