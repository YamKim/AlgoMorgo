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
		int num1, num2;
		cin >> num1 >> num2;
		if (num1 < num2) 
			PRINT_OUT("<");
		else if (num1 == num2)
			PRINT_OUT("=");
		else
			PRINT_OUT(">");
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
