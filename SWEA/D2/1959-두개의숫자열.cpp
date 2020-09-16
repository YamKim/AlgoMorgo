#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
const int INF = 987654321;

int solve(vector<int> &A, vector<int> &B) {
	int ret = -INF;
	int minIdx = M >= N ? N : M;
	int maxIdx = M + N - minIdx;
	for (int i = 0; i + minIdx - 1 < maxIdx; ++i) {
		int tmp = 0;
		for (int j = 0; j < minIdx; ++j) {
			if (M >= N)
				tmp += B[i + j] * A[j];	
			else
				tmp += A[i + j] * B[j];
		}
		ret = max(ret, tmp);
	}
	
	return (ret);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		cin >> N >> M;
		vector<int> A(N), B(M);
		for (int i = 0; i < N; ++i) 
			cin >> A[i];
		for (int i = 0; i < M; ++i)
			cin >> B[i];
		printf("#%d %d\n", t, solve(A, B));
			
	}
	return (0);
}
