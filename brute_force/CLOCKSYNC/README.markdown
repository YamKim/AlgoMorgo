## brute-force Problems
[upper dir](../)

## 문제: 시계 맞추기 (문제 ID: CLOCKSYNC, 난이도: 중) - 168p
[문제링크](https://algospot.com/judge/problem/read/CLOCKSYNC)

**아이디어**
1. 연결된 시계들은 인접행렬방식으로 처리.
2. 같은 스위치를 4번 누르면 시계가 자신의 위치로 돌아오기 때문에 9번째 스위치까지 4번씩 누를 수 있으므로, 경우의 수는 4^10.
   > 0번째 4번, 1번째 4번, ... 9번째 4번.
3. 누르면 cnt를 세는 것이 아닌, n번째 스위치를 몇번 누르고 다음 스위치를 눌렸을 때 만족하는지를 확인.
4. 따라서 탈출조건은, n번 스위치를 m(0~3)번 누르다 마지막 스위치인 9번 스위치를 누를 때 탈출.

**함수구현**
1. areAligned: 모든 시계가 12시를 가리키는지 확인
    ```cpp
    bool areAligned(const vector<int> &clocks) {
    	for (int i = 0; i < CLOCKS; ++i)
    		if (clocks[i] != 12) return (false);	
    	return (true);
    }
    ```
2. push: switch에 해당하는 시계를 3시간씩 조정 후, 15시 시간을 가리키는 시계는 3을 가리키도록 수정.
    ```cpp
    void push(vector<int> &clocks, int swtch) {
    	for (int i = 0; i < CLOCKS; ++i) {
    		if (linked[swtch][i] == 'x')
    			clocks[i] += 3;	
    		if (clocks[i] == 15) 
                // clock[i] %= 12;
    			clocks[i] = 3;	
    	}
    }
    ```
3. solve: 각 스위치를 몇번 누르고 재귀함수에 넣을지 결정
    ```cpp
    int solve(vector<int> &clocks, int swtch) {
    	if (swtch == SWITCHES - 1) return (areAligned   (clocks) ? 0 : INF);
    
    	int ret = INF;
    	// nth swtch
    	for (int cnt = 0; cnt < 4; ++cnt) {
    		ret = min(ret, cnt + solve(clocks, swtch    + 1));
    		push(clocks, swtch);
    	}	
    	return (ret);
    }
    ```
**모든 코드는 그릴 수 있다**
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm" width="600">
</p>