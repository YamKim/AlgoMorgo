#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
	int idx;
	for (int i = 0; i < seoul.size(); ++i) {
		if (seoul[i] == "Kim")
			idx = i;
	}
    return ("김서방은 " + to_string(idx) + "에 있다");
}

#include <iostream>
int main(void) {
	vector<string> seoul{"Jane", "Kim"};
	
	cout << solution(seoul) << "\n";
	return (0);
}
