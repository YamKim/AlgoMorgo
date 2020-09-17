## dynamic-programming
[upper dir](../)

## 문제: 비대칭 타일링 (문제 ID: ASYMTILING, 난이도: 하)
[문제링크](https://algospot.com/judge/problem/read/ASYMTILING)  
[참고-TILING2]

**아이디어**  
1. 대칭이 되기 위해서는 가운데 기준으로 한 편이 다른 한편과 동일해야 한다는 의미이므로, 한편에 대한 경우의 수만 생각하면 됨.
2. TILING2에서 구한 경우의 수를 사용하되, overflow가 발생할 수 있으므로, 이에 유의하여 되도록 L value 사용하지 않기.

**함수 구현**

1. asymmetric: 2 x width의 공간을 채우기 위한 비대칭 타일 경우의 수
	```cpp
	int asymmetric(int width) {
		int ret = tiling(width);
		if (width % 2 == 1)
			return (ret - tiling((width - 1) / 2) + MOD) % MOD;
		ret = (ret - tiling(width / 2) + MOD) % MOD;
		ret = (ret - tiling((width - 2) / 2) + MOD) % MOD;
		return (ret);
	}
	```

**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>
