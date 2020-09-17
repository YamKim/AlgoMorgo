## dynamic-programming
[upper dir](../)

## 문제: 폴리오미노 (문제 ID: POLY, 난이도: 중)
[문제링크](https://algospot.com/judge/problem/read/POLY)  

**아이디어**  
1. 다음 층을 선정할 때 남은 블록 수는 (현재 블록수 - 현재 층을 만드는데 사용된 블록 수)이므로, 완전탐색 가능.
2. 현재 층과 다음 층의 개수에 따라 만들 수 있는 블록의 경우의 수가 정해짐을 이용.
3. overflow를 주의해야 하므로, 계산 전 후 % MOD 처리하기.  
	> MOD 연산은 분배법칙이 성립하지 않으므로, 연산마다 나누고 더하는게 맞음. 
	> 1. (15%5 + 6%5 + 27%5) = 3 + 1 + 2 = 6 -> 6%5 = 1
	> 2. (15 + 6 + 27)%5 = 48%5 = 3 -> 3%5 = 3

**함수 구현**

1. poly: 현재 가지고 있는 블록 n개 중, 현재 층에 first만큼을 사용하여 만들 수 있는 경우의 수
	```cpp
	int cache[101][101];
	int poly(int n, int first) {
		// n개 남고, 현재 첫 줄이 n개라면 탈출
		if (n == first) return (1);
		int &ret = cache[n][first];
		if (ret != -1) {
			//cout << "repetead case!\n";
			return (ret);
		}
		ret = 0;
		for (int second = 1; second <= n - first; ++second) {
			// 현재층을 빼주고 남은 만큼이 다음 줄로 사용 가능.
			ret += (poly(n - first, second) * (first + second - 1)) % MOD; 
			ret %= MOD;
		}
		return (ret);
	}
	```

2. main: poly 함수의 depth 0에서 first에 사용될 블록이 필요하므로, 1개~N개까지 초기에 넣기.
```cpp
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	memset(cache, -1, sizeof(cache));
	int res = 0;
	for (int first = 1; first <= n; ++first) {
		res += poly(n, first);	
		res %= MOD;
	}
	cout << res << "\n";	

	return (0);
}
```

**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>
