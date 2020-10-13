#include <string>
#include <vector>

using namespace std;

int n;
int targetCheck;

int solve(vector<int> &numbers, int cur, int sum) {
	if (cur == n)
		return (sum == targetCheck ? 1 : 0);

	int ret = 0;
	ret += solve(numbers, cur + 1, sum + numbers[cur]);
	ret += solve(numbers, cur + 1, sum - numbers[cur]);
	return (ret);
}

int solution(vector<int> numbers, int target) {
	n = numbers.size();
	targetCheck = target;
	int answer = solve(numbers, 0, 0);
    return answer;
}

#include <iostream>
int main(void) {
	vector<int> numbers{1, 1, 1, 1, 1};
	int target = 3;
	cout << solution(numbers, target) << "\n";

	return (0);
}
