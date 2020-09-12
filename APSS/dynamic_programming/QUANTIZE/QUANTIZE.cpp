#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int A[101];
int N;
int pSum[101], psqSum[101];

void preCalc(void) {
	sort(A, A + N);	

	pSum[0] = A[0];	
	psqSum[0] = A[0] * A[0];
	for (int i = 1; i < N; ++i) {
		pSum[i] = pSum[i - 1] + A[i]; 
		psqSum[i] = psqSum[i - 1] + A[i] * A[i]; 
	}
	cout << "pSum\n";
	for (int i = 0; i < N; ++i)
		cout << pSum[i] << " ";
	cout << "psqSum\n";
	for (int i = 0; i < N; ++i)
		cout << psqSum[i] << " ";
}

int minError(int lo, int hi) {
	// lo가 0이 아닌 경우에 lo - 1까지를 빼야 부분합이 나옴. 
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
	int sqSum = psqSum[hi] - (lo == 0 ? 0 : psqSum[lo - 1]);
	int m = (0.5 + (double)sum / (hi - lo + 1)); 
	return (sqSum - 2 * m * sum + m * m * (hi - lo + 1));
}

int cache[101][11];
const int INF = 987654321;
int quantize(int from, int parts) {
	if (from == N) return (0);
	if (parts == 0) return (INF);
	
	// 최솟값/최댓값을 구하는 경우, 이 후부터의 최솟값을 구하려면 
	// 많은 연산이 필요하므로, 한 번 구했으면 저장된 값 사용.
	int &ret = cache[from][parts];
	if (ret != -1) {
		//cout << "repeated value!\n";
		return (ret);
	}
	ret = INF;
	for (int partSize = 1; from + partSize <= N; ++partSize) {
		int next = from + partSize;
		ret = min(ret, minError(from, next - 1) + quantize(next, parts - 1));
	}
	return (ret);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int S;
	memset(cache, -1, sizeof(cache));
	cin >> N >> S;
	for (int i = 0; i < N; ++i) 
		cin >> A[i];
	preCalc();
	cout << quantize(0, S) << "\n";

	return (0);
}
