## dp-technic
[upper dir](../)

## 문제: 여행 짐 싸기 (문제 ID: PACKING, 난이도: 중)
[문제링크](https://algospot.com/judge/problem/read/PACKING)    
[참고-TRIPATHCNG](../../dynamic_programming/TRIPATHCNT)  

**아이디어**  
1. 최대 절박도를 구하는 함수를 먼저 작성하고, 목록을 구성하는 함수 작성하기.
2. 현재 깊이에서 아이템을 선정 했을 때 / 하지 않았을 때가 같으면,  
   이를 선정하지 않고도 최대 절박도를 가질 수 있다는 말이 됨을 이용하기.

**함수 구현**

1. pack: capacity만큼 남았을 때, (item을 넣든지 넣지 않든지) 최대 절박도를 구함. 
	```cpp
	int N, W;
	string name[100];
	int volume[100], need[100];
	int cache[1001][100];
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
	```

2. reconstruct: S의 start번째 요소를 seq에 push_back하여 seq 완성. (종료조건: choices[start+1]이 -1인 경우)
	```cpp
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
	```
	
**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>
