# Bellman-Ford Algorithm

# 벨만-포드 알고리즘 (그래프 탐색)

## ⌚ 학습 기간

2022.12.27

## 벨만-포드 알고리즘

벨만포드 알고리즘은 시작점에서 도달 가능한 음의 닫힌 경로가 존재하면 그 사실을 보고하고, 음의 닫힌 경로가 존재하지 않을 경우 각 꼭짓점을 향한 최단 경로를 구하는 알고리즘이다.

벨만-포드 알고리즘 수행 

- 각 변들에 대해 완화하는 작업을 |V|번 반복한다.  (이때 |V|번째의 작업은 음의 닫힌 경로가 있을때 발생)
- |V\번째 작업으로 갱신이 된다면 시작점에서 도달 가능한 음의 닫힌 경로가 존재한다.

이를 통해 해당 알고리즘은 완화작업을 통한 시간복잡도는 O(|E|) 이고, 이 작업을 |V|번 반복해야 하므로, 전체 시간 복잡도는 O(|E||V|)에 해당한다.

결국 벨만 포드알고리즘에서는 같은 꼭짓점을 두번 이상 통과하지 않게 , 닫힌 경로를 제거할 수 있는 최소거리를 만들어 낼 수 있다.

## 구현

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
    int N,M,s;
    cin >> N>> M>> s;
    Graph G(N);
    for(int i = 0;i<M;i++){
        int a,b,w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b,w));
    }

    bool exist_negative_cycle = false;

    vector<long long> dist(N, INF);
    dist[s] = 0;
    for(int i = 0 ;i<N;++i){
        bool update = false;
        for(int v = 0; v<N;++v){
            if(dist[v] == INF) continue;
            for(auto e : G[v]){
                if(relax(dist[e.to],dist[v]+e.w)){
                    update = true;
                }
            }
        }
        if(!update)break;

        if( i == N-1 && update) exist_negative_cycle=true;
    }
    if(exist_negative_cycle) cout << "NEGATIVE CYCLE" << endl;
}
```