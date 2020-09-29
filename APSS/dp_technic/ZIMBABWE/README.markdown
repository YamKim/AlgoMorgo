## dp-technic
[upper dir](../)

## 문제: 웨브바짐 (문제 ID: ZIMBABWE, 난이도: 상)
[문제링크](https://algospot.com/judge/problem/read/ZIMBABWE)    
[참고-TSP2(bit mask)](../TSP2)  

**아이디어**  
1. bit mask를 사용하여 선택한 숫자를 기억해두기.(TSP2 참고)
2. 경우의 수가 순열(줄세우기)인 경우 해결하는 방법에 중복된 경우는 제거하는 기법 사용.
3. 나누어 떨어지는지 확인하기 위해서 각 단계별로 나머지를 넘기기만 하면, 모든 숫자를 구할 필요 없음.

**함수 구현**

1. generate: n글자를 n!의 경우로 출력하되, 문제 조건에 따라 e보다 작고 중복이 제거된 수만 출력.
	```cpp
	void generate(string price, int taken) {
		if (taken == (1 << n) - 1) {
			if (e > price)
				cout << price << "\n";
			return ;
		}

		for (int next = 0; next < n; ++next) {
			if (visitCheck(taken, next)) continue; 
			if (next == 0 || digits[next - 1] != digits[next] || visitCheck(taken, next - 1)) {
				// string의 자릿수를 추가해서 재귀
				generate(price + digits[next], taken | (1 << next));
			}
		}
	}
	```

2. price: taken이 모두 찼을 때, 경우에 부합하는 수인지 아닌지 판단하는 함수. cache를 사용하여 중복경우 재사용.
	```cpp
	int price(int index, int taken, int mod, int less) {
		if (index == n)
			return ((mod == 0 && less == 1) ? 1 : 0);
		int &ret = cache[taken][mod][less];
		if (ret != -1) {
			//cout << "repeated case!\n";
			return (ret);
		}

		ret = 0;
		for (int next = 0; next < n; ++next) {
			// less가 false이면(만들 수가 더 크면) 무조건 패스
			// less가 true여서 만들 숫자가 작아와도 지금 만들 수가 크면 패스
			if (!less && e[index] < digits[next]) continue;
			if (visitCheck(taken, next)) continue;
			// generate에서 줬던 옵션의 여집합
			if (next > 0 && digits[next - 1] == digits[next] && !visitCheck(taken, next - 1))
				continue;
			int nextTaken = taken | (1 << next);
			int nextMod = (mod * 10 + (digits[next] - '0')) % m;
			int nextLess = less || e[index] > digits[next];
			ret += price(index + 1, nextTaken, nextMod, nextLess);
			ret %= MOD;
		}
		return (ret);
	}
	```
	
**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>
