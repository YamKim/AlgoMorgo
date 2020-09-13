## dynamic-programming
[upper dir](../)

## 예제: 삼각형 위의 최대 경로 개수 세기 (문제 ID: TRIPATHCNT, 난이도: 중)
[문제링크](https://algospot.com/judge/problem/read/TRIPATHCNT)
[참고](../TRIANGLEPATH)

**아이디어**  
1. path 함수(TRIANGLEPATH 문제)로 얻는 cache를 토대로 판단해야함.
2. 다음 깊이에서의 cache값이 countCache의 값을 형성하는데 판단기준이 됨.

**함수 구현**

1. count: 현재 위치부터 끝까지 최댓값을 구하는 경로의 개수
	```cpp
	int countCache[100][100];
	// (y, x)부터 끝까지 들어갈 때의 최대경로의 개수를 세는 함수
	int count(int y, int x) {
		if (y == n - 1) return (1);
		int &ret = countCache[y][x];
		if (ret != -1) {
			cout << "repeated case!\n";
			return (ret);
		}
		ret = 0;
		if (path(y + 1, x) >= path(y + 1, x + 1)) ret += count(y + 1, x);
		if (path(y + 1, x) <= path(y + 1, x + 1)) ret += count(y + 1, x + 1);
		
		return (ret);
	}
	```

**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>
