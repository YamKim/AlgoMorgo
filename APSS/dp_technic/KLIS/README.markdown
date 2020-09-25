## dp-technic
[upper dir](../)

## 문제: k번째 최대 증가 부분 수열 (문제 ID: KLIS, 난이도: 상)
[문제링크](https://algospot.com/judge/problem/read/KLIS)  
[참고-LIS](../../dynamic_programming/KLIS)  
[참고-LIS4(LIS 요소 구하기)](../LIS4)  

**아이디어**  
1. 선행되어야 할 것: LIS, LIS를 만드는 경우의 수, K번째 수 선정.
2. lis(start) = 1 + lis(next)를 만족하는 next는 lis를 만들기 위해 필요한 요소라고 생각할 수 있음!
3. sort를 위한 followers 벡터를 사용할 때, index를 기억하기 위해 pair를 이용하여 기억하기.

**함수 구현**

1. contLis: start부터 마지막까지의 LIS를 만드는 경우가 몇개인지 cacheCnt[start]에 기록. 
	```cpp
	int cacheCnt[501];
	const int MAX = 2000000000 + 1;
	int countLis(int start) {
		if (lis(start) == 1) return (1);
		
		int &ret = cacheCnt[start + 1];
		if (ret != -1) {
			cout << "repeated case!\n";
			return (ret);
		}

		ret = 0;
		for (int next = start + 1; next < N; ++next) {
			if (start == -1 || S[next] > S[start]) {
				// 조건을 만족시키면 count를 증가시키는 템플릿.
				if (lis(start) == 1 + lis(next))
					ret = min<long long>(MAX, (long long)ret + countLis(next)); 
			}
		}
		return (ret);
	}
	```

2. reconstruct: start번째 요소를 lisList에 추가하여 요소 구성. countLis와 skip을 비교하며 요소를 추가할지, skip할지 결정.
	```cpp
	void reconstruct(int start, int skip, vector<int> &lisList) {
		if (start != -1) lisList.push_back(S[start]);

		vector<pair<int, int> > followers;
		for (int next = start + 1; next < N; ++next) {
			if (start == -1 || S[next] > S[start]) {
				if (lis(start) == 1 + lis(next))
					followers.push_back(make_pair(S[next], next));
			}
		} 
		sort(followers.begin(), followers.end());
		
		for (int i = 0; i < followers.size(); ++i) {
			// 지금 next를 lisList에 넣을 것인가 다음 next를 넣을 것인가 선택
			int next = followers[i].second;
			int cnt = countLis(next);
			// 지금 next를 만드는 경우의 수가, skip보다 많으므로 더 건너 뛰어야함.
			if (skip >= cnt) 
				skip -= cnt;
			// 지금 next를 넣는 경우
			else {
				reconstruct(next, skip, lisList);
				break;
			}
		}
	}
	```
	
**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>
