/******************************************/
//********Written by JinHuyk. Mun*********//
/******************************************/

#include <iostream>
#include <vector>

using namespace std;

struct UnionFind{
    vector<int> par, nodecnt;

    UnionFind(int n) : par(n,-1) , nodecnt(n,1) {}

    int root(int x){
        if(par[x]==-1) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y){
        return root(x) == root(y);
    }

    bool unite(int x, int y){
        x = root(x);
        y = root(y);

        if(x==y) return false;
        if( nodecnt[x] < nodecnt[y]) swap(x,y);

        par[y] = x;
        nodecnt[x] += nodecnt[y];
        return true;
    }
    int size(int x){
        return nodecnt[root(x)];
    }

s
};

int main(void){

    UnionFind uF(10);

    uF.unite(1,2);
    uF.unite(5,6);

    cout << uF.issame(1,2)<<endl;

}
