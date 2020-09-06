## divide-conquer
[upper dir](../)

## 문제: 팬미팅(문제 ID: FANMEETING, 난이도: 상)
[문제링크](https://algospot.com/judge/problem/read/FANMEETING)

**아이디어**  
[참고](../KARATSUBA)

1. 맴버들 각각과 팬들 각각이 만나는 경우의 수는 곱셈에서의 경우와 매우 유사함을 이용.
	> 가장 먼저 비트 연산자를 사용하려 하였으나, 비트 연산자는 32자리의 제한이 있으므로 불가능.
2. 주어진 문제의 멤버, 팬의 수는 20000이하이므로, 매우 큰 수의 곱 형태와 같음.(비트 연산자도 결국 2 digit에서의 곱&이므로) M=1, F=0으로 치환 후 서로 곱. 
	> 남자끼리 하면 1이 되고, 한 쌍이라도 1이 된다면 그 자릿수의 최종 합은 0이 될 수 없음을 이용.
3. 계산을 위해 ,karasutsba 사용.

**함수 구현**

1. hugs: 조건을 만족하는 수를 count 하여 반환.
	```cpp
	int hugs(const string &members, const string &fans) {
		int N = members.size(), M = fans.size();
		vector<int> A(N, 0), B(M,0);
	
		for (int i = 0; i < N; ++i)
			if (members[i] == 'M') A[i] = 1;
		//	 뒤집어서 넣어줘야한다.
		for (int i = 0; i < M; ++i)
			if (fans[M - 1 - i] == 'M') B[i] = 1;
		
		vector<int> res = karatsuba(A, B);
		int ret = 0;
		for (int i = N - 1; i < M; ++i)
			if (res[i] == 0) ++ret;	
	
		return (ret);	
	}
	```

**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>
