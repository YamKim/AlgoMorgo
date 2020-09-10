## dynamic-programming
[upper dir](../)

## 문제: 합친 LIS (문제 ID: JLIS, 난이도: 하)
[문제링크](https://algospot.com/judge/problem/read/JLIS)  
[참고-LIS](../LIS)

**아이디어**  
1. LIS와 같이 초기세팅을 가정하기 위해 index를 매개변수로 사용하여 substr(인덱스 뒷부분을 잘라넣는 것)과 같은 역할
2. 두 sequence에서 한 기준 값을 뽑아 그보다 큰 값을 A혹은 B에서 선택하는 방식으로 진행.
3. cache를 2중배열로 사용하여 [indexA, indexB]부터 최대길이를 계산.  
   (만약 값으로 인덱스를 매기면, A와 B가 같은 값을 가질 때 의도했던 것과 다른 값이 누적될 수 있음..)
4. 위 방식이 고유성을 갖는 이유는, 값이 고정되어 있기 때문에 indexA, indexB에 따른 maxElement는 항상 같은 값을 갖는다.

**함수 구현**

1. jlis: 두 sequence에서 A, B를 indexA, indexB부터 끝까지 잘랐을 때 둘을 합쳐서 만들 수 있는 최대 증가 부분 수열의 개수를 반환.
	```cpp
	const int INF = 987654321;
	int n, m;
	int A[100], B[100];
	int cache[101][101];

	int jlis(int indexA, int indexB) {
		int &ret = cache[indexA + 1][indexB + 1];
		if (ret != -1) {
			//cout << "repeated case!\n";
			return (ret);
		}

		int a = indexA == -1 ? -INF : A[indexA];
		int b = indexB == -1 ? -INF : B[indexB];
		int maxElement = max(a, b);

		ret = 1;
		for (int nextA = indexA + 1; nextA < n; ++nextA)
			if (maxElement < A[nextA])
				ret = max(ret, 1 + jlis(nextA, indexB));
		for (int nextB = indexB + 1; nextB < n; ++nextB)
			if (maxElement < B[nextB])
				ret = max(ret, 1 + jlis(indexA, nextB));

		return (ret);
	}
	```

**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>
