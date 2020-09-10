#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 987654321;
int n, m;
int A[100], B[100];
int cache[101][101];

int jlis(int indexA, int indexB) {
	int &ret = cache[indexA + 1][indexB + 1];
	if (ret != -1) {
		//cout << "repeated case!\n";
		return (ret);
	}

	int a = indexA == -1 ? -INF : A[indexA];
	int b = indexB == -1 ? -INF : B[indexB];
	int maxElement = max(a, b);

	ret = 1;
	for (int nextA = indexA + 1; nextA < n; ++nextA)
		if (maxElement < A[nextA])
			ret = max(ret, 1 + jlis(nextA, indexB));
	for (int nextB = indexB + 1; nextB < n; ++nextB)
		if (maxElement < B[nextB])
			ret = max(ret, 1 + jlis(indexA, nextB));

	return (ret);
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int C;
	cin >> C;
	while (C--) {
		cin >> n >> m;
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < n; ++i) 
			cin >> A[i];
		for (int j = 0; j < m; ++j)
			cin >> B[j];			

		cout << jlis(-1, -1) - 1 << "\n";
	}
	return (0);
}
