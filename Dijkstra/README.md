# 다익스트라 알고리즘(Dijkstra)

## ⌚ 학습 기간

2022.12.29

## Dijkstra Algorithm

모든 변의 가중치가 음수가 아니라면 사용할 수 있는 최단 경로 문제의 해결법으로 다익스트라 알고리즘의 있다.  (만약 음의 가중치를 가진다면 벨만포드 알고리즘을 사용한다)

### $O(|V|^2)$ 의 복잡도를 가진 다익스트라 알고리즘

다음 복잡도를 가지는 다익스트라 알고리즘은 탐욕법을 기반으로 한 알고리즘으로 벨만포드 알고리즘처럼 완화를 사용하여 문제를 해결한다. 시작점부터 각 정점마다의 거리를 비교하면서 알고리즘을 수행한다. 

다익스트라 알고리즘은 다음과 같은 절차를 거친다.

- 미사용 꼭짓점 중 d[v]가 최소인 정점 v를 탐색하기
- 정점 v를 시점으로 각변을 완화하기

다음을 코드로 구현하면 다음과 같다.

```cpp

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const long long INF = 1LL << 60;
//2^60

struct Edge{

    int to;
    long long w;
    Edge(int to, long long w) : to(to), w(w){}

};
using Graph = vector<vector<Edge>>;

template<class T> bool relax(T&a, T b){
    if(a>b){
        a = b;
        return true;
    }
    else return false;
}

int main(void){
		// 각 정점과 가중치들을 vector에 저장
    int N,M,s;
    cin >> N >> M >> s;
    Graph G(N);
    for(int i = 0;i<M;++i){
        int a,b,w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b,w));

    }
		// 알고리즘 수행
    vector<bool> used(N,false);
    vector<long long> dist(N,INF);
    dist[s] = 0;
    for(int i = 0;i<N;++i){
        long long min_dist = INF;
        int min_v = -1;
        for(int v= 0; v< N;++v){
            if(!used[v] && dist[v] < min_dist ){
                min_dist = dist[v];
                min_v = v;
            }
        }
        if(min_v == -1) break;
        for(auto e : G[min_v]){
            relax(dist[e.to], dist[min_v] + e.w);

        }
        used[min_v] = true;

    }
		// dist 값 출력 (최소 비용)
    for(int v = 0; v<N; ++v){
        if(dist[v] < INF) cout << dist[v] << endl;
        else cout << "INF" << endl;
    }

}
```