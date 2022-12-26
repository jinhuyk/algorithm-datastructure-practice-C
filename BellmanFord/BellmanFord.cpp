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