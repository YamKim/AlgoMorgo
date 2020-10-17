#include <string>
#include <vector>

using namespace std;

bool isPrime(int nbr) {
    if (nbr == 1 || nbr == 0) return (false);
    int n = 2;
    for (int n = 2; n < nbr; ++n)
        if (nbr % n == 0) return (false);
    return (true);
}

string numbers;
int n;
void genNum(int nbr, int visited, vector<int> &numArr) {
    if (visited == ((1 << n) - 1)) return ;
    
    int nbr_tmp;
    for (int next = 0; next < n; ++next) {
        nbr_tmp = nbr;
        if (visited & (1 << next)) continue ;
        nbr_tmp = nbr * 10 + (numbers[next] - '0');
        bool isUniq = true;
        for (int i = 0; i < numArr.size(); ++i) {
            if (numArr[i] == nbr_tmp)
                isUniq = false;
        }
        if (isUniq) numArr.push_back(nbr_tmp);
        genNum(nbr_tmp, visited | (1 << next), numArr);
    }
}

int solution(string _numbers) {
    numbers = _numbers;
    n = numbers.size();
    vector<int> numArr;
    genNum(0, 0, numArr);
    int answer = 0;
    for (int i = 0; i < numArr.size(); ++i)
        if (isPrime(numArr[i])) ++answer;
    return (answer);
}
