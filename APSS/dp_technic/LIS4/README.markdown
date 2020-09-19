## dp-technic
[upper dir](../)

## 예제: lis4  
[참고](../dynamic_programming/LIS)  
문제: LIS를 만족시키는 요소들을 출력하는 알고리듬 구성하기.  

**아이디어**  
1. LIS와 방식은 동일하지만, max(ret, 1 + lis(next)) 부분을 수정하여 조건을 만족시키는 경우를 bestNext에 기록.  
2. choice라는 array를 사용하여 bestNext들을 기억하여 두기.
3. reconstruction 함수에서 S의 choices[bestNext]번째 요소에 접근하면서 seq 완성 시키기.

**함수 구현**

1. lis4: start부터 마지막까지의 LIS 개수를 cache[start]에 기록하며 반환. 
	```cpp
	int cache[101], choices[101];
	int lis4(int start) {
		if (start == n) return (0);	

		int &ret = cache[start + 1];
		if (ret != -1) {
			//cout << "repeated case!\n";
			return (ret);
		}

		ret = 1;
		int bestNext = -1;
		for (int next = start + 1; next < n; ++next) {
			if (start == -1 || S[next] > S[start]) {
				if (ret < 1 + lis4(next)) {
					ret = max(ret, 1 + lis4(next));
					bestNext = next;
				}
			}
		}
		choices[start + 1] = bestNext;
		
		return (ret);
	}
	```

2. reconstruct: S의 start번째 요소를 seq에 push_back하여 seq 완성. (종료조건: choices[start+1]이 -1인 경우)
	```cpp
	void reconstruct(int start, vector<int> &seq) {
		if (start != -1) seq.push_back(S[start]);
		int next = choices[start + 1];
		if (next != -1) reconstruct(next, seq);
	}
	```
	
**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>
