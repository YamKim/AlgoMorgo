#include <iostream>
#include <assert.h>

using namespace std;

const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";

void curve(const string &seed, int generations) {
	if (generations == 0) {
		cout << seed;
		return ;
	}
	for (int i = 0; i < seed.size(); ++i) {
		if (seed[i] == 'X')
			curve(EXPAND_X, generations - 1);
		else if (seed[i] == 'Y')
			curve(EXPAND_Y, generations - 1);
		else
			cout << seed[i];
	}	
}

const int MAX = 1000000000 + 1;
int length[51];
void preCalc() {
	length[0] = 1;
	for (int i = 1; i <= 50; ++i) {
		length[i] = min(MAX, length[i - 1] * 2 + 2);
	} 
}

char expand(const string &seed, int generations, int skip) {
	if (generations == 0) {
		//assert(skip < seed.size());
		// 확장할 수 없지만, 문자열 크기보다 skip이 크면 오류
		if (skip > seed.size())
			exit(-1);
		return (seed[skip]);
	}

	// 현재 세대가 만들 수 있는 길이는 length[generations]
	for (int i = 0; i < seed.size(); ++i) {
		if (seed[i] == 'X' || seed[i] == 'Y') {
			if (skip >= length[generations])
				skip -= length[generations];
			else if (seed[i] == 'X')
				return (expand(EXPAND_X, generations - 1, skip));
			else
				return (expand(EXPAND_Y, generations - 1, skip));
		}
		// 확장되지 않고, 건너 뛰는 경우
		else if (skip > 0)
			--skip;
		else
			return (seed[i]);
	}
	return ('#');
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int C;
	cin >> C;
	while (C--) {
		int n, p, l;
		cin >> n >> p >> l;
		preCalc();
		for (int i = 0; i < l; ++i)
			cout << expand("FX", n, p + i - 1);
		cout << "\n";
	}

	return (0);
}	
