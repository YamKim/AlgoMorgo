## dynamic-programming
[upper dir](../)

## 예제: 삼각형 위의 최대 경로 (문제 ID: TRIANGLEPATH, 난이도: 하)
[문제링크](https://algospot.com/judge/problem/read/TRIANGLEPATH)

**아이디어**  
1. brute force 방식으로 먼저 푼 후, 겹치는 부분이 있음을 확인하고 dynamic programming으로 코딩.
2. 특히, 맵/보드 기반의 문제는 푸는 방식이 매우 유사함. 탈출 조건으로 범위를 먼저 설정해야 하며, 도달한 점을 세는 것인지 도달할 때까지 거리/시간의 최댓/최솟값을 구하는지 잘 파악해야함.

**함수 구현**

1. path: 현재 위치의 값, triangle[y][x]에 아래 두 수중 큰 수를 누적시켜 cache에 넣는 함수. 따라서, 반환 값은 cache의 최댓값이 됨.
	```cpp
	int path(int y, int x) {
		if (y >= n) return (0);
		int &ret = cache[y][x];
		if (ret != -1) {
			//cout << "repeated value!\n";
			return (ret);
		}
		
		int maxVal = max(path(y + 1, x), path(y + 1, x + 1));
		return (ret = triangle[y][x] + maxVal);
	}
	```

**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>
