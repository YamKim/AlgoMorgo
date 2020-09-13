## brute-force Problems
[upper dir](../)

## 예제: 여행하는 외판원 (Traveling Salesman Problem, 외판원 문제)
[문제링크](https://www.algospot.com/judge/problem/read/TSP1)

**아이디어**
1. 모든 노드를 방문해보며 거리를 누적시킨 후 가장 짧은 거리 선택.
2. 모든 노드를 방문하기 위해서는 n!의 경우의 수가 가능하므로, 재귀함수 사용.
3. 최소 거리를 구하는 함수만 필요.
    ```cpp
    - 방문 순서 필요. vector<int> path
    - 방문 여부 필요. vector<bool> visited
    - 누적 거리 필요. double currentLength
    ```
4. main에서 출발점을 미리 정하고 함수에 대입하기.

**함수 구현**
1. main 함수
    ```cpp
    int main(void) {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    
    	cin >> N;
    	for (int i = 0; i < N; ++i) {
    		for (int j = 0; j < N; ++j) {
    			cin >> dist[i][j];
    		}
    	}

    	double ret = INF;
    	for (int beg = 0; beg < N; ++beg) {
    		vector<int> path;
    		vector<bool> visited(N, false);
    		path.push_back(beg);
    		visited[beg] = true;
    		ret = min(ret, shortestPath(path, visited, 0.00));
    	}

    	cout << ret;

    	return (0);
    }
    ```
    - 주어지는 입력은 A to B와 B to A의 값이 같은 행렬(대칭행렬)이다.
    - 출발점을 어디로 하느냐에 따라서 최단거리가 달라질 수 있기 때문에, 모든 경우를 생각해야한다.  

2. shortestPath 함수
    ```cpp
    double	shortestPath(vector<int> &path, vector<bool> &  visited, double currentLength) {
    	if (path.size() == N) 
    		return (currentLength);

    	double ret = INF;
    	for (int next = 0; next < N; ++next) {
    		if (visited[next]) continue;
    		int here = path.back();
    		path.push_back(next);
    		visited[next] = true;
    		double cand = shortestPath(path, visited, dist[here]    [next] + currentLength);
    		ret = min(ret, cand);	
    		path.pop_back();
    		visited[next] = false;
    	}
    	return ret;
    }
    ```
    - 핵심 아이디어는 a노드에서 b노드를 갔다가 조건을 만족하지 않아서, a노드에서 c노드로 간다고 하면, a노드에서 다음 노드로 갈 때는 세팅을 완전히 초기화 해줘야 한다는 것이다.
    - 따라서, 재귀함수에서 나온 후 조건을 비교한 다음에는 초기화를 위해, next는 방문 순서에서 빼고 방문여부는 false로 reset 해주어야 한다.
    - 루프를 돌며, ret은 cand와 계속 비교/수정되며 최솟값을 갖게될 것이다.

**모든 코딩은 그려질 수 있다**  
<p align="center">
    <img src="./Algorithm.png" alt="Algorithm">
</p>

- 6개의 case 중에 최소 거리는 두개인 것처럼 보이지만, 해당 문제는 두 지역 간에 올 때와 갈 때의 거리가 같다.
- 만일, 갈 때는 택시를 타고, 올 때는 버스를 타는 것과 같이 걸리는 시간 문제로 바뀌게 되면, 최솟값은 하나의 결과만 나올 것이다.