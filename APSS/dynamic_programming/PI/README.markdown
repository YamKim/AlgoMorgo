## dynamic-programming
[upper dir](../)

## 문제: 원주율 외우기 (문제 ID: PI, 난이도: 하)
[문제링크](https://algospot.com/judge/problem/read/PI)  

**아이디어**  
1. 모든 숫자가 같을 때, 1/-1 차이 날 때, 등차수열일 때는 '다음 인덱스와 현재 인덱스의 간격을 구한다'는 공통점이 있으므로 한 루프에서 처리.
2. 만약, 12341234에서 123을 봤으면 41234를 보는 것은 초기 세팅이므로 재귀함수를 사용 가능.
3. 특정 인덱스 뒷 부분의 최소 점수를 계산하는 부분이 중복되므로, memoization 사용.

**함수 구현**

1. classify: S[a]와 S[b]의 규칙에 따라 점수 반환
	```cpp
	int classify(int a, int b) {
		string M = N.substr(a, b - a + 1);
		int upStep = 0;
		int loStep = 0;
		int eqStep = 0, prevInt = M[1] - M[0];
		for (int i = 0; i < M.size() - 1; ++i) {
			int curInt = M[i + 1] - M[i];
			if (curInt == 1)	++upStep;
			if (curInt == -1)	++loStep;
			if (curInt == prevInt) {
				++eqStep;
				prevInt = curInt;
			}
		}
		if (upStep == b - a || loStep == b - a)
			return (2);
		if (prevInt == 0 && eqStep == b - a)
			return (1);
		else if (prevInt != 0 && eqStep == b - a)
			return (5);

		bool alternating = true;
		for (int i = 0; i < M.size(); ++i)
			if (M[i] != M[i % 2]) // %를 사용해서 짝수 고르기!
				alternating = false;
		if (alternating)
			return (4);

		return (10);
	}
	```

2. memorize: S[begin]부터 마지막 인덱스까지 최소점수 반환. (탈출조건: 성공시 0, 실패시 INF)
	```cpp
	int cache[10002];
	const int INF = 987654321;
	int memorize(int begin) {
		if (begin == N.size()) return (0);		

		int &ret = cache[begin];
		if (ret != -1) {
			cout << "repeated value!\n";
			return (ret);
		}
		ret = INF;
		for (int L = 3; L <= 5; ++L) {
			int next = begin + L;
			if (begin + L <= N.size())
				ret = min(ret, classify(begin, next - 1) + memorize(next));			
		}

		return (ret);
	}
	```


**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>
