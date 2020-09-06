## dynamic-programming
[upper dir](../)

## 문제: 외발 뛰기(문제 ID: JUMPGAME, 난이도: 하)
[문제링크](https://algospot.com/judge/problem/read/JUMPGAME)

**아이디어**  
1. brute force 방식으로 먼저 푼 후, 겹치는 부분이 있음을 확인하고 dynamic programming으로 코딩.

**함수 구현**

1. solve: 도착점에 다르는 경우 1을 return하고, 값을 누적시키며 도달하는 경우의 수를 세기.
	```cpp
	int solve(int y, int x) {
		if (y >= n || x >= n)			return (0);
		if (y == n - 1 && x == n - 1)	return (1); 

		int &ret = cache[y][x];
		if (ret != -1) {
			//cout << "repeated value!\n";
			return (ret);
		}
		int jumpSize = board[y][x];
		return (ret = solve(y + jumpSize, x) || solve(y, x + jumpSize));
	}
	```

**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>
