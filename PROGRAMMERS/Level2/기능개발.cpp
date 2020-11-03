#include <string>
#include <vector>

using namespace std;

const int INF = 987654321;
int n;
int ceilNbr(int nbr, int div) {
    int ret;
    for (ret = 0; ret < INF; ++ret) {
        if (ret * div >= nbr) return (ret);
    }
    return (-1);
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    n = progresses.size();
    vector<int> days(n);
    
    for (int i = 0; i < n; ++i)
        days[i] = ceilNbr(100 - progresses[i], speeds[i]);
    int maxDay = days[0];
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (days[i] > maxDay) {
           answer.push_back(cnt);
           // renew the cnt;
           cnt = 1;
           maxDay = days[i];
        }
        else ++cnt;
    }
    answer.push_back(cnt);
    return answer;
}
