## dynamic-programming
[upper dir](../)

## 예제: 이항계수 구하기

**아이디어**  

1. brute force로 푸는 경우, 중복되는 계산이 생기므로, cache에 이를 저장해두고 다시 쓰는 dynamic programming을 사용한다.

**함수 구현**

1. bino: brute force를 사용하여 이항계수를 구하는 함수.
	```cpp
	int bino(int n, int r) {
		cout << "n: " << n << ", ";
		cout << "r: " << r << "\n";	
		if (r == 0 || r == n) return (1);
		return (bino(n - 1, r - 1) + bino(n - 1, r));
	}
	```

2. binoDp: dynamic programming을 추가하여 이항계수를 구하는 함수.
	```cpp
	#define MAX_SIZE (30)
	int cache[MAX_SIZE][MAX_SIZE];
	int binoDp(int n, int r) {
		cout << "n: " << n << ", ";
		cout << "r: " << r << "\n";	
		if (r == 0 || r == n) return (1);
		int &ret = cache[n][r];
		if (ret != -1) {
			cout << "repeated value!\n";
			return (ret);
		}
	
		return (ret = binoDp(n - 1, r - 1) + binoDp(n - 1, r));
	}
	```

3. binoCalc(): 파스칼의 삼각형을 만드는 함수.
	```cpp
	int binoArr[MAX_SIZE][MAX_SIZE];
	void binoArrCalc() {
		memset(binoArr, 0, sizeof(binoArr));
		for (int n = 0; n <= 200; ++n) {
			binoArr[n][0] = binoArr[n][n] = 1;
			for (int r = 1; r < n; ++r) {
				binoArr[n][r] = binoArr[n - 1][r - 1] + binoArr[n][r];
			}
		}
	}
	```

**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>
