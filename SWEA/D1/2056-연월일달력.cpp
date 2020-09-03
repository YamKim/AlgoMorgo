#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int test_case;
#define PRINT_OUT(X)  (cout << "#" << test_case << " " << X << "\n")
#define PRINT_DATE	  (strYear + "/" + strMonth + "/" + strDay)

bool	isRange(string &date) {
	string strYear = date.substr(0, 4);
	string strMonth = date.substr(4, 2);
	string strDay = date.substr(6, 2);

	if (strMonth == "02") {
		if (stoi(strDay) >= 1 && stoi(strDay) <= 28)
		{
			PRINT_OUT(PRINT_DATE);
			return (true);
		}
	}
	else if (strMonth == "01" || strMonth == "03" || strMonth == "05" 
			|| strMonth == "07" || strMonth == "08" || strMonth == "10"
			|| strMonth == "12") {
		if (stoi(strDay) >= 1 && stoi(strDay) <= 31)
		{
			PRINT_OUT(PRINT_DATE);
			return (true);
		}
	}
	else if (strMonth == "04" || strMonth == "06" || strMonth == "09" 
			|| strMonth == "11") {
		if (stoi(strDay) >= 1 && stoi(strDay) <= 30)
		{
			PRINT_OUT(PRINT_DATE);
			return (true);
		}
	}
	return (false);
}
 
int main(int argc, char** argv)
{
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		string date;
		cin >> date;

		if (!isRange(date)) 
			PRINT_OUT(-1);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
