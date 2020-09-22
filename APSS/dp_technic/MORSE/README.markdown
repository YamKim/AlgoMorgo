## dp-technic
[upper dir](../)

## 예제: 모스 부호 사전 (문제 ID: MORSE, 난이도: 중)
[문제링크](https://algospot.com/judge/problem/read/MORSE)    

**아이디어**  

1. '-'를 선택 했을 때 혹은 'o'를 선택 했을 때, 다음 순서에서는  
   몇가지 경우가 있는지 이항 계수를 통해 알 수 있음을 이용.

**함수 구현**

1. generate2: 사용하지 않은 '-'이 n개, 'o'가 m개 남았을 때, s를 누적하여 skip번째 s를 출력하는 함수.  
			  (남은 애들 끼리의 조합보다 skip이 크면 이 조합에서는 skip번째 애가 나오지 않을 것.)
	```cpp
	void generate2(int n, int m, string s) {
		if (skip < 0) return;
		if (n == 0 && m == 0) {
			if (skip == 0)
				cout << s << "\n";
			--skip;
		}

		if (bino[n + m][n] <= skip) {
			skip -= bino[n + m][n];
			//cout << "skip: " << skip << "\n";
			return ;
		}

		if (n > 0) generate2(n - 1, m, s + "-");
		if (m > 0) generate2(n, m - 1, s + "o");
	}
	```

2. generate3: 사용하지 않은 '-'이 n개, 'o'가 m개 남았을 때, '-' 혹은 'o' 뒤에 문자열을 붙이는 함수.
			  (남은 문자열들의 조합을 예측하여 건너뛰는 개수를 조정)
	```cpp
	string generate3(int n, int m, int skip) {
		// n이 0이면 나머지는 모두 'o가 될 것.
		if (n == 0) return string(m, 'o');

		// 모양을 보면, 이항계수 크기보다 skip을 적게 한다면 "-"를 붙이고 다음 부분을 본다.
		if (skip < bino[n - 1 + m][n - 1])
			return ("-" + generate3(n - 1, m, skip));
		return ("o" + generate3(n, m - 1, skip - bino[n - 1 + m][n - 1]));
	}
	```
	
**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>
