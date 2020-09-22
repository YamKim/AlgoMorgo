#include <iostream>
#include <cstring>

using namespace std;

int N, M, K;
int skip;
void generate(int n, int m, string s) {
	if (n == 0 && m == 0) {
		--skip;
		if (skip == 0)	
			cout << s << "\n";
		return ;
	}
	
	if (n > 0) generate(n - 1, m, s + "-");
	if (m > 0) generate(n, m - 1, s + "o");
}

const int MAX = 1000000000 + 100;
int bino[201][201];
void binoCalc() {
	memset(bino, 0, sizeof(bino));
	for (int n = 0 ; n <= 200; ++n) {
		bino[n][0] = bino[n][n] = 1;
		for (int r = 1; r < n; ++r) {
			bino[n][r] = min(MAX, bino[n - 1][r - 1] + bino[n - 1][r]);
		}
	}
}

void generate2(int n, int m, string s) {
	if (skip < 0) return;
	if (n == 0 && m == 0) {
		if (skip == 0)
			cout << s << "\n";
		--skip;	
	} 

	if (bino[n + m][n] <= skip) {
		skip -= bino[n + m][n];
		// cout << "skip: " << skip << "\n";
		return ;
	}

	if (n > 0) generate2(n - 1, m, s + "-");
	if (m > 0) generate2(n, m - 1, s + "o");
}

string generate3(int n, int m, int skip) {
	// n이 0이면 나머지는 모두 'o가 될 것.
	if (n == 0) return string(m, 'o');

	// 모양을 보면, 이항계수 크기보다 skip을 적게 한다면 "-"를 붙이고 다음 부분을 본다.
	if (skip < bino[n - 1 + m][n - 1]) 
		return ("-" + generate3(n - 1, m, skip));
	return ("o" + generate3(n, m - 1, skip - bino[n - 1 + m][n - 1]));
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	skip = K;
	binoCalc();
	//generate2(N, M, "");
	cout << generate3(N, M, K) << "\n";

	return (0);
}
