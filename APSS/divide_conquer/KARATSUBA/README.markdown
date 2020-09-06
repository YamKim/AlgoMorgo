## divide-conquer
[upper dir](../)

## Karatsuba Algorithm
[참고](../MULTIPLY/)

**아이디어**  

1. 큰 수의 경우, multiply()함수만 사용하면 소모 시간이 매우 크기 때문에, 분할 정복을 활용해야함.
	> multiply를 활용하되, 최소한의 연산만으로 큰 수를 계산하기.
2. 자릿수를 쪼갠 후, 공식(모든 코딩은 그려질 수 있다)을 통해 곱셈 횟수를 최소화(세 번)한다.
	> 시간복잡도: 
	> - 자릿수가 8인 두 수를 연산하고, karatsuba의 탈출조건이 multiply을 3자리보다 작을 때 수행한다면, 
	> - 8-4-2 자릿수로 분할되면서 깊이가 증가하고, 깊이는 2일 때 multiply가 한번 호출된다. 
	> - karatsuba 함수가 한 번 호출될 때, 3번의 karatsuba 함수가 사용되므로, 3^2만큼의 multiply 함수를 수행하는 꼴이 된다. 
	> - multiply 함수는 nxn인, 2x2만큼 수행되므로 총 36번의 연산(multiply만 사용하는 경우 8x8번)을 한다.

**함수 구현**

1. addTo: 각자리수의 요소를 서로 합하는 연산 (normalize 함수에서 carry까지 마친 결과 반환)
	```cpp
	void addTo(vector<int> &a, const vector<int> &b, int k) {
		// a가 비어있는 vector일 경우를 고려
		// push하면 기존 원소 있는채로 늘어남.
		int maxDigits = b.size() + k + 1;
		for (int i = 0; i < maxDigits; ++i) 
			a.push_back(0);
		for (int j = 0; j < b.size(); ++j) 
			a[j + k] += b[j];
		normalize(a);
	}
	```

2. subFrom: 각 자리의 요소를 서로 빼는 연산 (normalize 함수에서 borrow까지 마친 결과 반환)
	```cpp
	void subFrom(vector<int> &a, const vector<int> &b) {
		for (int i = 0; i < b.size(); ++i) 
			a[i] -= b[i];
		normalize(a);
	}
	```

3. karatsuba: 분할정복을 이용하여 큰 수의 자릿수를 쪼개어 곱셈 후, 결과를 반환
	```cpp
	vector<int> karatsuba(	const vector<int> &a, 
							const vector<int> &b) {
		int an = a.size(), bn = b.size(); 
		if (bn > an)			return (karatsuba(b, a));
		if (an == 0 || bn == 0) return (vector<int>());
		if (an <= 50)			return (multiply(a, b));
	
		int halfA = an / 2;
		int halfB = min<int>(halfA, b.size());
		vector<int> a0(a.begin(), a.begin() + halfA);
		vector<int> a1(a.begin() + halfA, a.end());
		vector<int> b0(b.begin(), b.begin() + halfB);
		vector<int> b1(b.begin() + halfB, b.end());
		
		vector<int> z0 = karatsuba(a0, b0);
		vector<int> z2 = karatsuba(a1, b1);
	
		addTo(a0, a1, 0);
		addTo(b0, b1, 0);
		vector<int> z1 = karatsuba(a0, b0);
		subFrom(z1, z0);
		subFrom(z1, z2);
	
		vector<int> ret;
		addTo(ret, z0, 0);
		addTo(ret, z1, halfA);
		addTo(ret, z2, halfA + halfA);
	
		return (ret);
	}
	```

**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>
