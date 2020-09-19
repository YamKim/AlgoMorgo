## dynamic-programming
[upper dir](../)

## 문제: 와일드카드(문제 ID: WILDCARD, 난이도: 중)
[문제링크](https://algospot.com/judge/problem/read/WILDCARD)

**아이디어**  
1. brute force 방식으로 먼저 푼 후, 겹치는 부분이 있음을 확인하고 dynamic programming으로 코딩.
2. 조각이 recursive function 뒤에 있는 경우, 보다 깊이가 낮은 곳에서 할 일을 모두 마치고 나오므로, 깊이가 깊어질수록 일의 순서는 빨라짐. 이는, cache에 저장되는 값들은 가장 낮은 깊이에서이고, 깊이가 얕아지면서 그 값들을 재활용함.
3. ?가 있는 경우 / *가 있는 경우 둘로 나눠서 가장 먼저 코딩을 수행.
4. ?가 있는 경우에서는 두 문자열이 일치하는 경우는 넘기게 되므로 *보다 일반적인 경우. 따라서, loop에서 *가 대체하는 부분을 skip하면, **처음 세팅**과 같이 수행하기 위해 재귀함수 호출.

**함수 구현**

1. mtach: W와 S를 입력으로 받아서 brute force를 수행. *가 skip을 마치면, * 다음칸 W와 skip된 S부터 처음에서 한 것과 같이 비교를 수행.  
	```cpp
	bool match(const string &W, const string &S) {
		int pos = 0;

		while (pos < W.size() && pos < S.size()) {
			if (W[pos] == '?' || W[pos] == S[pos])	
				++pos;
			else break;
		}

		if (pos == W.size())
			return (pos == S.size());
		
		if (W[pos] == '*') {
			for (int skip = 0; pos + skip < S.size(); ++skip) {
				// if (w[pos + 1] == s[pos + skip])
				if (match(W.substr(pos + 1), S.substr(pos + skip))) {
					return (true);
				}
			}
		}

		return (false);
	}
	```

2. mtachMemoized: cache를 사용하여 repeated value를 재활용함. 이를 위해 return 자료형을 int로 변환, pos index를 나누어 w, s로 변환하여 cache의 인덱스로 사용. 

	```cpp
	#define CACHE_SIZE (101)
	string W, S;
	int cache[CACHE_SIZE][CACHE_SIZE];

	int matchMemoized(int w, int s) {
		int &ret = cache[w][s];
		if (ret != -1) return ret;
		
		while (w < W.size() && s < S.size()) {
			if (W[w] == '?'|| W[w] == S[s]) {
				++w;
				++s;
			}
			else break;
		}
		
		if (w == W.size())
			return (ret = (s == S.size()));

		if (W[w] == '*') {
			for (int skip = 0; s + skip <= S.size(); ++skip) {
				// 탈출조건이 size이므로, s.size()가 matchMemoized에 대입될 때,
				// 탈출조건이 성립하게 됨.
				if (matchMemoized(w + 1, s + skip))
					return (ret = 1);
			}
		}
		// *a와 ab를 비교시, *a 재귀 후 a가 ab랑 같지 않으므로
		return (ret = 0);
	}
	```

**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>
