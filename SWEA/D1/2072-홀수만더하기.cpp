#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		int res = 0;
        for (int i = 0; i < 10; ++i) {
            int tmp;
            cin >> tmp;
            if (tmp % 2 != 0)
                res += tmp;
          }
          cout << "#" << test_case << " " << res << "\n";
		/////////////////////////////////////////////////////////////////////////////////////////////
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
