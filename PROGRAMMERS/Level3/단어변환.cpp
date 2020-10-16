#include <string>
#include <vector>

using namespace std;

bool compareString(string str1, string str2) {
    int idx1 = 0;
    int idx2 = 0;
    int cnt = 0;
    while (str1[idx1] && str2[idx2]) {
       if (str1[idx1] != str2[idx2])
           ++cnt;
        ++idx1;
        ++idx2;
    }
    while (str1[idx1++])
        ++cnt;
    while (str2[idx2++])
        ++cnt;
    return (cnt == 1 ? true : false);
}

string target;
vector<string> words;
const int INF = 987654321;

int n;

int solve(string word, int visited[50]) {
    if (word == target) return (0);
    
    int ret = INF;
    for (int next = 0; next < n; ++next) {
        if (visited[next]) continue;
        if (!compareString(word, words[next])) continue;
        visited[next] = 1;
        ret = min(ret, 1 + solve(words[next], visited));
        visited[next] = 0;
    }
    return (ret);
}

int solution(string _begin, string _target, vector<string> _words) {
    target = _target;
    words = _words;
    n = words.size();
    
    int visited[50] = { 0, };
    int answer = solve(_begin, visited);
    return (answer == INF ? 0 : answer);
}
