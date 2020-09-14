## dynamic-programming
[upper dir](../)

## 문제: Quantization (문제 ID: QUANTIZE, 난이도: 중)
[문제링크](https://algospot.com/judge/problem/read/QUANTIZE)  
[참고-PI](../PI)

**아이디어**  
1. 각 파트의 평균일 때, 오차의 제곱합이 가장 작다는 수식 이용.
2. 부분합을 수시로 사용하게 되므로 먼저 구해둠. 반복적 dynamic programming 사용.
3. PI 문제와 마찬가지로 깊이 n에서 n번째 파트의 minError를 구하고 다음 파트로 재귀.
4. from이 N이 되기 전에 그룹화 마치면 실패경우이므로 INF 반환,  
   from이 N이 되면 그룹화가 마무리 된 것이므로 0 반환.

**함수 구현**

1. preCalc: A의 인덱스 i까지 누적(제곱)합 pSum[i](psqSum[i]) 미리 연산.
	```cpp
	int pSum[101], psqSum[101];

	void preCalc(void) {
		sort(A, A + N);	

		pSum[0] = A[0];	
		psqSum[0] = A[0] * A[0];
		for (int i = 1; i < N; ++i) {
			pSum[i] = pSum[i - 1] + A[i]; 
			psqSum[i] = psqSum[i - 1] + A[i] * A[i]; 
		}
		cout << "pSum\n";
		for (int i = 0; i < N; ++i)
			cout << pSum[i] << " ";
		cout << "psqSum\n";
		for (int i = 0; i < N; ++i)
			cout << psqSum[i] << " ";
	}
	```

2. minError: lo부터 hi까지의 최소인 오차제곱합  
	```cpp
	int minError(int lo, int hi) {
		// lo가 0이 아닌 경우에 lo - 1까지를 빼야 부분합이 나옴. 
		int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
		int sqSum = psqSum[hi] - (lo == 0 ? 0 : psqSum[lo - 1]);
		int m = (0.5 + (double)sum / (hi - lo + 1)); 
		return (sqSum - 2 * m * sum + m * m * (hi - lo + 1));
	}
	```

2. quantize: from부터 끝까지의 parts의 최소 오차를 반환.  
	```cpp
	int cache[101][11];
	const int INF = 987654321;
	int quantize(int from, int parts) {
		if (from == N) return (0);
		if (parts == 0) return (INF);
		
		// 최솟값/최댓값을 구하는 경우, 이 후부터의 최솟값을 구하려면 
		// 많은 연산이 필요하므로, 한 번 구했으면 저장된 값 사용.
		int &ret = cache[from][parts];
		if (ret != -1) {
			//cout << "repeated value!\n";
			return (ret);
		}
		ret = INF;
		for (int partSize = 1; from + partSize <= N; ++partSize) {
			int next = from + partSize;
			ret = min(ret, minError(from, next - 1) + quantize(next, parts - 1));
		}
		return (ret);
	}
	```

**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>
