#include <string>
#include <vector>

using namespace std;

#include <iostream>
void makeCapet(int brown, int yellow, vector<int> &grid) {
    int width;
    int height;
    for (int i = 1; i <= yellow; ++i) {
        // 약수가 아니라면 넘기기
        if (yellow % i != 0) continue;
        width = i;
        height = yellow / width;
        if (brown == 2 * width + 2 * height + 4) {
            grid[0] = height + 2;
            grid[1] = width + 2;
            break ;
        }
    }
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    makeCapet(brown, yellow, answer);
    return answer;
}
