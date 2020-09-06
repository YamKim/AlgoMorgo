#include <iostream>
#include <vector>

using namespace std;

vector<int> str2intVec(const string &num) {
	int n = num.size();
	vector<int> ret(n);

	for (int i = 0; i < n; ++i) 
		ret[i] = num[n - 1 - i] - '0';
	return (ret);
}

void normalize(vector<int> &num) {
	int n = num.size();
	for (int i = 0; i < n - 1; ++i) {
		num[i + 1] += num[i] / 10;
		num[i] %= 10;
	}
	// 답이 0인 경우를 위해 ret.size() > 1
	while (num.size() > 1 && num.back() == 0) num.pop_back();
}

vector<int> multiply(	const vector<int> &a, 
						const vector<int> &b) {
	// 99 * 99를 하면 4자리 숫자.
	vector<int> ret(a.size() + b.size() + 1, 0);
	for (int i = 0; i < b.size(); ++i) {
		for (int j = 0; j < a.size(); ++j) {
			ret[i + j] += b[i] * a[j];
		}
	}
	normalize(ret);
	return (ret);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string num1, num2;
	cin >> num1 >> num2;

	vector<int> numVec1 = str2intVec(num1);
	vector<int> numVec2 = str2intVec(num2);

	vector<int> res = multiply(numVec1, numVec2);
	for (int i = res.size() - 1; i >= 0; --i)
		cout << res[i];
	cout << "\n";
	return (0);
}
