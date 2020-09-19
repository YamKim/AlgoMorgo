## dynamic-programming
[upper dir](../)

## 문제: 두니발 박사의 탈옥 (문제 ID: NUMB3RS, 난이도: 중)
[문제링크](https://algospot.com/judge/problem/read/NUMB3RS)  

**아이디어**  
1. 확률에서 전체 확률은 각 확률의 합이며 각 확률은 그 확률을 만들 때까지의 누적 곱.
2. 한 번 들른 곳의 확률 값은 다시 사용될 수 있으므로, memoization 사용하기

**함수 구현**

1. search: days만큼 남았을 때, here에 있을 확률
	```cpp
	double search(int here, int days) {
		if (days == 0) return (here == q ? 1.0 : 0.0);

		double &ret = cache[here][days];
		if (ret > -0.5) {
			//cout << "repeated case!\n";
			return (ret);
		}

		ret = 0.0;
		for (int next = 0; next < n; ++next) {
			if (connected[here][next]) {
				ret += search(next, days - 1) / deg[here];
			}
		}

		return (ret);
	}
	```

**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>
