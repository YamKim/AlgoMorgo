#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > rotation(vector<vector<int> > &mat, int N) {
	vector<vector<int> > ret(N, vector<int>(N));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			ret[i][j] = mat[N - 1 - j][i];
	return (ret);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		vector<vector<int> > mat(N, vector<int>(N));
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				cin >> mat[i][j];
		vector<vector<int> > ans1 = rotation(mat, N); 
		vector<vector<int> > ans2 = rotation(ans1, N); 
		vector<vector<int> > ans3 = rotation(ans2, N); 
		
		printf("#%d\n", t);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j)
				printf("%d", ans1[i][j]);
			printf(" ");
			for (int j = 0; j < N; ++j)
				printf("%d", ans2[i][j]);
			printf(" ");
			for (int j = 0; j < N; ++j)
				printf("%d", ans3[i][j]);
			printf("\n");
		}
	}
	return (0);
}
