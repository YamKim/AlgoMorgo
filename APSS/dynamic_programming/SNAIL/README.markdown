## dynamic-programming
[upper dir](../)

## 예제: 타일링 방법의 수 세기 (문제 ID: TILING2, 난이도: 하)
[문제링크](https://algospot.com/judge/problem/read/TILING2)  
[참곡](../PI)

**아이디어**  
1. 기본적인 완전탐색 + 동적계획법. (피보나치수열)
2. 세로로 하나 놓거나 가로로 두개를 놓을 때, 나머지 width들은 이미 구한 바가 있는 값이므로 이를 이용.

**함수 구현**

1. tiling: 너비가 width일 때 놓을 수 있는 타일 수
	```cpp
	int tiling(int width) {
		if (width <= 1) return (1);

		int &ret = cache[width];
		if (ret != -1) {
			cout << "repeated case!\n";
			return (ret);
		}

		return (ret = (tiling(width - 1) + tiling(width - 2)) % MOD);
	}
	```

**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>