#include <iostream>
#include <vector>

using namespace std;

void normalize(vector<int> &num) {
	int n = num.size();
	for (int i = 0; i < n - 1; ++i) {
		if (num[i] < 0) {
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else {
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
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

void addTo(vector<int> &a, const vector<int> &b, int k) {
	// a가 비어있는 vector일 경우를 고려
	// push하면 기존 원소 있는채로 늘어남.
	int maxDigits = b.size() + k + 1;
	for (int i = 0; i < maxDigits; ++i) 
		a.push_back(0);
	for (int j = 0; j < b.size(); ++j) 
		a[j + k] += b[j];
	normalize(a);
}

void subFrom(vector<int> &a, const vector<int> &b) {
	for (int i = 0; i < b.size(); ++i) 
		a[i] -= b[i];
	normalize(a);
}

vector<int> karatsuba(	const vector<int> &a, 
						const vector<int> &b) {
	int an = a.size(), bn = b.size(); 
	if (bn > an)			return (karatsuba(b, a));
	if (an == 0 || bn == 0) return (vector<int>());
	if (an <= 50)			return (multiply(a, b));

	int halfA = an / 2;
	int halfB = min<int>(halfA, b.size());
	vector<int> a0(a.begin(), a.begin() + halfA);
	vector<int> a1(a.begin() + halfA, a.end());
	vector<int> b0(b.begin(), b.begin() + halfB);
	vector<int> b1(b.begin() + halfB, b.end());
	
	vector<int> z0 = karatsuba(a0, b0);
	vector<int> z2 = karatsuba(a1, b1);

	addTo(a0, a1, 0);
	addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, halfA);
	addTo(ret, z2, halfA + halfA);

	return (ret);
}

int hugs(const string &members, const string &fans) {
	int N = members.size(), M = fans.size();
	vector<int> A(N, 0), B(M,0);

	for (int i = 0; i < N; ++i)
		if (members[i] == 'M') A[i] = 1;
	//	 뒤집어서 넣어줘야한다.
	for (int i = 0; i < M; ++i)
		if (fans[M - 1 - i] == 'M') B[i] = 1;
	
	vector<int> res = karatsuba(A, B);
	int ret = 0;
	for (int i = N - 1; i < M; ++i)
		if (res[i] == 0) ++ret;	

	return (ret);	
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int C;
	cin >> C;
	while (C--) {
		string members, fans;
		cin >> members >> fans;

		cout << hugs(members, fans) << "\n";
	}

	return (0);
}
