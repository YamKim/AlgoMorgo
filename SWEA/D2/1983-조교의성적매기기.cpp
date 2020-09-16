#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const string grade[10] = {
	"A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"
	};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		int N, K;
		cin >> N >> K;
		double ref;
		vector<double> seq(N);
		for (int i = 0; i < N; ++i) {
			double midTest, finTest, assignment;
			cin >> midTest >> finTest >> assignment;
			double totScore = midTest * 0.35 + finTest * 0.45 + assignment * 0.2; 
			if (i == K - 1) ref = totScore;
			seq[i] = totScore;
		}

		int rank = 0;
		for (int k = 0; k < N; ++k) {
			if (seq[k] > ref)
				++rank;
		}
		cout << "#" << t << " ";
		cout << grade[(int)((rank) / (N / 10))] << "\n";
	}
	return (0);
}
