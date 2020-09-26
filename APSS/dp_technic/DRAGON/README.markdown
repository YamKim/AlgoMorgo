## dp-technic
[upper dir](../)

## 문제: 드래곤 커브 (문제 ID: DRAGON, 난이도: 중)
[문제링크](https://algospot.com/judge/problem/read/DRAGON)  
[참고-MORSE(skip 하기)](../../dp_tecchnic/MORSE)  

**아이디어**  
1. 일단 순서에 관계없이 dragon curve를 만드는 함수 구현.
2. 조건에 따라서 skip을 줄여가며 보고 싶은 부분을 찾아서 확장시키기.

**함수 구현**

1. curve: 현재 generations에서 X, Y는 확장, 그 외에는 그냥 출력. 
	```cpp
	void curve(const string &seed, int generations) {
		if (generations == 0) {
			cout << seed;
			return ;
		}
		for (int i = 0; i < seed.size(); ++i) {
			if (seed[i] == 'X')
				curve(EXPAND_X, generations - 1);
			else if (seed[i] == 'Y')
				curve(EXPAND_Y, generations - 1);
			else
				cout << seed[i];
		}	
	}
	```

2. expand: 현재 generations에서 X, Y는 확장하되 skip보다 확장된 길이가 작으면 확장 시키지 않고 건너뜀. 그 외에는 skip 감소.
	```cpp
	char expand(const string &seed, int generations, int skip) {
		if (generations == 0) {
			//assert(skip < seed.size());
			// 확장할 수 없지만, 문자열 크기보다 skip이 크면 오류
			if (skip > seed.size())
				exit(-1);
			return (seed[skip]);
		}

		// 현재 세대가 만들 수 있는 길이는 length[generations]
		for (int i = 0; i < seed.size(); ++i) {
			if (seed[i] == 'X' || seed[i] == 'Y') {
				if (skip >= length[generations])
					skip -= length[generations];
				else if (seed[i] == 'X')
					return (expand(EXPAND_X, generations - 1, skip));
				else
					return (expand(EXPAND_Y, generations - 1, skip));
			}
			// 확장되지 않고, 건너 뛰는 경우
			else if (skip > 0)
				--skip;
			else
				return (seed[i]);
		}
		return ('#');
	}
	```
	
**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>
