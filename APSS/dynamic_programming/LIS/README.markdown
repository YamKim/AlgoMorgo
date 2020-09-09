## dynamic-programming
[upper dir](../)

## 예제: 최대 증가 부분 수열 (문제 ID: LIS, 난이도: 하)
[문제링크](https://algospot.com/judge/problem/read/LIS)

**아이디어**  
1. brute force 방식으로 먼저 푼 후, 겹치는 부분이 있음을 확인하고 dynamic programming으로 코딩.
2. LIS 원칙에 따라서, 기준 지점보다 큰 index는 깊이 우선 탐색으로 탐색을 마침.
	> - 만약 S[0]이 기준일 때, S[4]가 더 커서 탐색 함.
	> - S[1]이 기준이 될 때, 역시 S[1]보다 S[4]가 큰 경우.
	> - 이 때, brute force만 사용하면 다시 S[4]에서 깊이 우선 탐색을 수행해야함.. 
	> - 따라서 cache를 사용.

**함수 구현**

1. lis: 만들 수 있는 최대 증가 부분 수열의 개수를 반환. cache에는 각 인덱스에서부터 끝까지 봤을 때, 최대 증가 부분 수열의 개수를 저장.
	```cpp
	int n;
	int S[100], cache[101];

	int lis(int start) {
		// start가 -1부터 시작. 인덱스는 0부터로 맞춰주기
		int &ret = cache[start + 1];
		if (ret != -1) {
			//cout << "repetead value!\n";
			return (ret);
		}
		ret = 1; // S[start]뒤에 보다 큰 수가 없으면 return 1
		for (int next = start + 1; next < n; ++next)
			if (start == -1 || S[start] < S[next])
				// lis를 호출할 때마다 1씩 증가.
				ret = max(ret, 1 + lis(next));
		return (ret);
	}
	```

**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>
