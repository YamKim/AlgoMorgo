#include<iostream>

using namespace std;

#define PRINT_OUT(X)  (cout << "#" << test_case << " " << X << "\n")

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int maxNum = -1;
		for (int i = 0; i < 10; ++i) {
			int tmp;
			cin >> tmp;
			if (maxNum < tmp)
				maxNum = tmp;
		}
		PRINT_OUT(maxNum);	
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
