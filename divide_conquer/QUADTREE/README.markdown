## divide-conquer
[upper dir](../)

## 문제: 쿼드 트리 뒤집기 (문제 ID: QUADTREE, 난이도: 하)
[문제링크](https://algospot.com/judge/problem/read/QUADTREE)

**아이디어**
1. iterator는 계속 증가시켜가며, reverse를 재귀해야함.
2. 만약 *it가 x가 아니면, 쿼드 중에 한 부분을 차지함을 의미하므로, return
3. x를 만나면, 새로운 쿼드를 만들기 때문에, 각 쿼드를 구해야함.

**함수 구현**
1. reverse: 네개의 구간을 나누어 각 구간의 순서를 변경하여 string 합을 반환하는 함수. (x를 만나면 그 안에서 다시 구간을 나눔)
    ```cpp
	string reverse(string::iterator &it) {
		char head = *it;
		++it;
		// 만약, 시작이 'b' 혹은 'w'이면 바로 리턴.
		if (head == 'w' || head == 'b')
			return (string(1, head));
		// x부터 시작이면 part를 나누어 리턴
		string upperLeft	= reverse(it); 
		string upperRight	= reverse(it); 
		string lowerLeft	= reverse(it);  
		string lowerRight	= reverse(it);

		return ("x" + lowerLeft + lowerRight + upperLeft + upperRight);
	}
    ```
    - x를 만나면 각 부분을 나누는데, 각 부분을 나누다 x를 만나면 새로운 부분을 나누고..   
	it를 증가시키며 이 과정을 반복하면 가장 깊은 쿼드부터 reverse 되며 반환된다.

**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>
