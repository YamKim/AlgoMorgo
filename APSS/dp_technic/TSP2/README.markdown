## dp-technic
[upper dir](../)

## 예제: 여행하는 외판원 (문제 ID: TSP1)
[문제링크](https://algospot.com/judge/problem/read/TSP1)    
[참고-TSP(example)](../../brute_force/TSP)  

**아이디어**  
1. bit mask를 사용하여 visit array를 대체하는 방법 사용

**함수 구현**

1. shortestPath: here 도시에서 앞으로 방문할 도시들의 거리합이 가장 짧은 길이를 반환.
	```cpp
	double dist[MAX][MAX];
	double cache[MAX][1<<MAX];
	double shortestPath(int here, int visited) {
		if (visited == (1 << N) - 1) return (0.0);
		double &ret = cache[here][visited];
		if (ret != -1.0) {
			//cout << "repeated case!\n";
			return (ret);
		} 
		
		ret = INF;
		for (int next = 0; next < N; ++next) {
			if (visited & (1 << next)) continue;
			double cand = dist[here][next] + shortestPath(next, visited | (1 << next));
			ret = min(ret, cand);
		}

		return (ret);
	}
	```
	
**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>
