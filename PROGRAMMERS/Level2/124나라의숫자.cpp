#include <string>
#include <vector>

using namespace std;

const string BASE124 = "124";

void convertNum(int n, string &answer, bool first_zero) {
    string ret;
    if (n == 0) 
    {
        if (first_zero)
            answer = "1";
    	return ;
    }
    convertNum((n - 1) / 3, answer, 0);
    answer += BASE124[((n - 1) % 3)];
}

string solution(int n) {
    string answer = "";
    convertNum(n, answer, 1);
    return answer;
}
