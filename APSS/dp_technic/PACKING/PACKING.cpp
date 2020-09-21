#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, W;
string name[100];
int volume[100], need[100];
int cache[1001][100];
// capacity만큼 남았을 때, item을 넣든지 넣지 않든지 최대 절박도를 구함.
int pack(int capacity, int item) {
	if (item == N) return (0); 

	int &ret = cache[capacity][item];
	if (ret != -1) {
		cout << "repeated case!\n";
		return (ret);
	}

	// 1. 지금 아이템을 안 넣어보고 생각.
	ret = pack(capacity, item + 1);
	if (capacity - volume[item] >= 0) {
		// 2. 지금 아이템을 넣어보고 생각.
		// 지금 아이템을 넣기 때문에 절박도를 더하고,
		// 다른 아이템의 누적 절박도를 모두 더함.
		int cand = need[item] + pack(capacity - volume[item], item + 1);
		ret = max(ret, cand); 
	}
	return (ret);
}

void reconstruct(int capacity, int item, vector<string> &picked) {
	if (item == N) return ;
	// 현재 아이템을 선택했을 때와 하지 않았을 때 최대 절박도가 같다면,
	// 현재 아이템은 선택하지 않은 것. 
	if (pack(capacity, item) == pack(capacity, item + 1)) {
		reconstruct(capacity, item + 1, picked);
	}
	else { 
		picked.push_back(name[item]);
		reconstruct(capacity - volume[item], item + 1, picked);
	}
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> W;

	for (int i = 0; i < N; ++i) {
		cin >> name[i];
		cin >> volume[i];
		cin >> need[i];
	}
	
	memset(cache, -1, sizeof(cache));
	int res = pack(W, 0);
	vector<string> picked;
	reconstruct(W, 0, picked);
	cout << res << " " << picked.size() << "\n";
	for (size_t i = 0; i < picked.size(); ++i)
		cout << picked[i] << "\n";

	return (0);
}
