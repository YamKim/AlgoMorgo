#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
	string step1 = new_id;
	for (int i = 0; i < new_id.size(); ++i) {
		if (step1[i] >= 'A' && step1[i] <= 'Z')
			step1[i] += 'a' - 'A';
	}
	string step2 = ""; 
	for (int i = 0; i < step1.size(); ++i) {
		if (step1[i] >= 'a' && step1[i] <= 'z' 
			|| step1[i] >= '0' && step1[i] <= '9'
			|| step1[i] == '-' || step1[i] == '_'
			|| step1[i] == '.') {

			step2 += step1[i];
		}
	}

	string step3 = "";
	for (int i = 0; i < step2.size(); ++i) {
		bool rePoint = false;
		while (step2[i] == '.') {
			rePoint = true;
			++i;
		}	
		if (rePoint)
			step3 += ".";
		step3 += step2[i];
	}

	string step4 = step3;
	if (step4[0] == '.')
		step4 = step4.substr(1);
	if (step4[step4.size() - 2] == '.')
		step4 = step4.substr(0, step4.size() - 2);

	string step5 = step4;
	if (step5[0] == '\0') {
		step5 = "a";
	}
	
	string step6 = step5;
	if (step6.size() >= 16)
		step6 = step6.substr(0, 15);
	
	
	string step7 = step6;
	if (step7.length() <= 2) {
		char addition = step7[step7.size() - 1];
		while (step7.size() < 3)
			step7 += addition;
	}
	return (step7);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string ex1 = "...!@BaT#*..y.abcdefghijklm";  
	string ex2 = "z-+.^.";
	string ex3 = "=.=";

	cout << solution(ex3) << "\n";
	//cout << solution(ex3) << "\n";
	
	return(0);
}
