## divide-conquer
[upper dir](../)

## 문제: 울타리 잘라내기(문제 ID: FENCE, 난이도: 중)
[문제링크](https://algospot.com/judge/problem/read/FENCE)

**아이디어**  

완전탐색법(brute-force)로 풀기  
1. 2개 이상의 울타리 n개를 선택하여 넓이를 구하기 위해서는, 울타리 n개 중 가장 낮은 높이의 울타리 기준의 minHeight와 너비인 beg - end + 1을 곱해야 한다.
2. 너비의 시작점과 끝점을 변경하며 모든 구간에 대해 계산해야함.
	> 주의: h.size()가 4라면, 인덱스는 3까지 계산. 가장 마지막 계산은, (3 - 3 + 1) * minHeight.

분할정복(divide-conquer)로 풀기  
1. 탈출조건 설정: 가장 작은 단위인 너비가 1일 때(left==right)까지 쪼개고, 그때의 넓이(=h[right])를 반환.
2. 가장 왼쪽부터 중간까지, 중간부터 가장 오른쪽까지 범위를 나누어(분할하여) solve함수를 진행하며 더 큰 넓이를 기준으로 ret을 갱신.
3. 분할을 마쳤으면 기준 넓이(가장 중간 두개 울타리에 대한)를 계산하고, 오른쪽/왼쪽으로 확장하며 최대 넓이를 찾기.

**함수 구현**

1. brute_force: 모든 울타리 중 판자의 최대 넓이를 구하는 함수.
	```cpp
	int brute_force() {
		int ret = -1;
		for (int beg = 0; beg < h.size(); ++beg) {
			int minHeight = INF;
			for (int end = beg; end < h.size(); ++end) {
				if (minHeight > h[end]) minHeight = h[end];
				ret = max(ret, minHeight * (end - beg + 1));
			}
		}
		return (ret);
	}
	```
2. solve: left부터 right까지 울타리를 선택하여 만든 판자의 최대 넓이를 구하는 함수
	```cpp
	int solve(int left, int right) {
		if (left == right) return (h[right]);

		int mid = (left + right) / 2;
		int lo = mid, hi = mid + 1;
		int ret = max(solve(left, lo), solve(hi, right));
		// 기준 넓이를 잡기(초기값을 잡고 비교)
		// 가장 가운데 두 블록 중 낮은 높이 블록 x 2(너비)
		int minHeight = min(h[lo], h[hi]);
		ret = max(ret, minHeight * 2);

		while (left < lo || hi < right) {
			// right expansion 조건
			// left < lo인 경우로 while이 동작하는 것일수도 있으므로
			if (hi < right && (lo == left || h[hi + 1] > h[lo - 	1])) {
				++hi;
				minHeight = min(minHeight, h[hi]);
			}
			else if (left < lo && (hi = right || h[lo - 1] > h	[hi + 1])) {
				--lo;
				minHeight = min(minHeight, h[lo]);
			}
			ret = max(ret, ((hi - lo + 1) * minHeight));
		}
		return (ret);
	}
	```

**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>
