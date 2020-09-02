#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;
const int SWITCHES = 10;
const int CLOCKS = 16;
const string linked[SWITCHES] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};

bool areAligned(const vector<int> &clocks) {
	for (int i = 0; i < CLOCKS; ++i)
		if (clocks[i] != 12) return (false);	
	return (true);
}

void push(vector<int> &clocks, int swtch) {
	for (int i = 0; i < CLOCKS; ++i) {
		if (linked[swtch][i] == 'x')
			clocks[i] += 3;	
		if (clocks[i] == 15) 
			clocks[i] = 3;	
	}
}

int solve(vector<int> &clocks, int swtch) {
	if (swtch == SWITCHES - 1) return (areAligned(clocks) ? 0 : INF);
	
	int ret = INF;
	// nth swtch
	for (int cnt = 0; cnt < 4; ++cnt) {
		int cand = solve(clocks, swtch + 1);
		ret = min(ret, cnt + cand);	
		push(clocks, swtch);
	}	
	return (ret);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	vector<int> clockStatus(CLOCKS);
	for (int i = 0; i < CLOCKS; ++i)
		cin >> clockStatus[i];

	cout << solve(clockStatus, 0) << "\n";
	
	return (0);
}
