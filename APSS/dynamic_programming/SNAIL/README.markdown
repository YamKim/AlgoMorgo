## dynamic-programming
[upper dir](../)

## 예제: 장마가 찾아왔다 (문제 ID: SNAIL, 난이도: 하)
[문제링크](https://algospot.com/judge/problem/read/SNAIL)  

**아이디어**  
1. 확률을 계산하기 위해서는, 동시에 일어날 수 있는 사건에 대해서 서로 곱하며, 한 사례에 대한 확률 계산이 끝나면 다른 사례들의 확률 더하기.
2. 완전탐색법과 메모이제이션을 사용하는 전형적인 문제.

**함수 구현**

1. climb: days번째날 달팽이가 climbed만큼 오를 확률
	```cpp
	const int MAX_SIZE = 1001;
	double cache[MAX_SIZE][MAX_SIZE * 2 + 1];

	double climb(int days, int climbed) {
		if (climbed >= n) return (1.0);
		if (days >= m) return (0.0);

		double &ret = cache[days][climbed];
		if (ret != -1.0) {
			cout << "repeated case!\n";
			return (ret);
		}

		ret = 0.0;
		ret += 0.25 * climb(days + 1, climbed + 1);
		ret += 0.75 * climb(days + 1, climbed + 2);

		return (ret);
	}
	```

**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>