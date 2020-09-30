## dp-technic
[upper dir](../)

## 문제: 실험 데이터 복구하기 (문제 ID: RESTORE, 난이도: 중)
[문제링크](https://algospot.com/judge/problem/read/RESTORE)    
[참고-PACKING(reconstruct)](../PACKING)  

**아이디어**  
1. PACKING에서와 같이 최대 경우의 수를 먼저 찾고, 그 경우를 만족시키는 next가 뒤따르는 경우 reconstruct에서 재구성.

**함수 구현**

1. restore: 현재 단어(words[last]) 뒤에 붙일 단어(words[next]) 와의 겹치는 수가 가장 클 때의 값 반환
	```cpp
	int cache[MAX_N][1<<MAX_N];
	int restore(int last, int used) {
		if (used == (1 << k) - 1) return (0);

		int &ret = cache[last][used];
		if (ret != -1) {
			cout << "repeated case!\n";
			return (ret);
		}	

		ret = 0;
		for (int next = 0; next < k; ++next)  {
			if (used & (1 << next)) continue;
			int cand = overlap[last][next] + restore(next, used | (1 << next));
			// 겹치는 최대 길이를 반환
			ret = max(ret, cand);
		}
		return (ret);
	}
	```

2. reconstruct: words[last] 뒤로 단어를 붙이되, overlap이 최대인 경우로 누적하여 붙이기
	```cpp
	string reconstruct(int last, int used) {
		if (used == (1 << k) - 1) return ("");

		for (int next = 0; next < k; ++next) {
			if (used & (1 << next)) continue;
			int cand = overlap[last][next] + restore(next, used | (1 << next));
			// 만약, next를 이 뒤에 추가했을 때의 overlap과 
			// 추가하지 않았을 때의 overlap이 같으면, 얘를 추가해야 최대.
			if (restore(last, used) == cand)
				// 시작시 last가 k부터이므로 words[next]부터 출력
				return (words[next].substr(overlap[last][next])
						+ reconstruct(next, used | (1 << next)));
		}
		return "***oops***"; 
	}
	```
	
**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>
