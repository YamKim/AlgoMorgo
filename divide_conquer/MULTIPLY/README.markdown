## divide-conquer
[upper dir](../)

## 예제: 두 수 곱하기

**아이디어**  

1. 흔히 사용하는 곱셈식을 이용하기 위해, 각 수를 string으로 받아 vector<int>에 각 자리수의 숫자를 넣어줌.
2. 곱셈 결과, 인덱스는 자릿수에 대응되며, 요소는 연산 후 동일한 자릿수의 값을 합산한 결과를 갖는다.
	> 단점: multiply 함수를 보면, O(n^2)의 시간 소요(n 자릿수 x m 자릿수를 하는 경우 nm번 연산)

**함수 구현**

1. normalize: 연산이 마친 벡터의 값에 따라서, 10의 자리 수를 윗 자리수에 carry.
	```cpp
	void normalize(vector<int> &num) {
	    int n = num.size();
	    for (int i = 0; i < n - 1; ++i) {
			// 뺄셈 후의 결과를 normalize 하는 경우
	        if (num[i] < 0) {
	            int borrow = (abs(num[i]) + 9) / 10;
	            num[i + 1] -= borrow;
	            num[i] += borrow * 10;
	        }
			// 덧셈 후의 결과를 normalize 하는 경우
	        else {
	            um[i + 1] += num[i] / 10;
	            um[i] %= 10;
	        }
	    }
	    // 답이 0인 경우를 위해 ret.size() > 1
	    while (num.size() > 1 && num.back() == 0) num.pop_back();
	}
	```
3. multiply: 손으로 곱셈을 하는 것과 같이, 곱하고 같은 자리수에 누적.
	```cpp
	vector<int> multiply(	const vector<int> &a, 
							const vector<int> &b) {
		// 99 * 99를 하면 4자리 숫자.
		vector<int> ret(a.size() + b.size() + 1, 0);
		for (int i = 0; i < b.size(); ++i) {
			for (int j = 0; j < a.size(); ++j) {
				ret[i + j] += b[i] * a[j];
			}
		}
		normalize(ret);
		return (ret);
	}
	```

**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>
