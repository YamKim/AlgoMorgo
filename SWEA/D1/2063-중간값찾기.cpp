#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int N;
	cin >> N;

	vector<int> numList;
	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		
		numList.push_back(tmp);
	}
	sort(numList.begin(), numList.end(), greater<int>());
	cout << numList[N / 2] << "\n";
	
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
