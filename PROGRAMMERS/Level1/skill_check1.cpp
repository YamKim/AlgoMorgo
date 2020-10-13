#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	int startIdx = s.size() / 2;
	if (s.size() % 2 == 0)
		return (s.substr(startIdx - 1, 2));
    return (s.substr(startIdx, 1));
}

#include <iostream>
int main(void) {
	string s;
	cin >> s;

	cout << solution(s) << "\n";
}

