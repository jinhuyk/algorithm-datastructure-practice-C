# Union-Find

## ⌚ 학습 기간

2022.12.25

## Union-Find

union Find는 그룹 분할을 관리하는 자료구조이다. Union Find의 qurry처리는 다음과 같다.

- issame(x,y) : x,y가 같은 그룹인가인지를 판정
- unite(x,y) : 요소 x를 포함한 그룹과 요소 y를 포함한 그룹끼리 합침

Union Find의 핵심은 root를 만드는 것으로, root를 이용하여 판별 또는 합치기 등 다양한 작업을 수행할 수 있다.

Root를 찾는 함수는 다음과 같이 구현할 수 있다. 

- root(x) : 요소 x를포함하는 그룹의 루트를 반환 (O(h))

root(x)를 이용하여 위에서 정의한 issame과 unite를 보다 구체적으로 정의 할 수 있다.

```cpp
bool issame(x,y) {
	if(root(x)==root(y)) return true;
	else false;
}

void unite(x,y){
	r_x = root(x);
	r_y = root(y);
	r_x -> r_y 
// r_x가 r_y의 자식으로 들어가게 끔 구현
}
```

다음 두 함수는 모두 root를 기반으로 구현하였기 떄문에 시간 복잡도 또한 O(h)이다. 

이는 자료를 처리할 때 비효율 적일 수 있다. 이를 해결하기 위해 

union by size와 경로 압축을 사용하여 시간 복잡도를 줄여나간다.

### union-by-size

unite를 할 때 시간복잡도는 O(h) 이기 때문에 비효율 적이다. 이는 무조건 root(x)가 root(y)의 원소로 지정해야하기 때문인데 이를 해결하기 위해서는, 더 노드의 개수가 적은 x,y중 하나를 택하여 나머지 트리에 넣어준다면 시간복잡도를 O(logN) 으로 줄여나갈 수 있다.

### 경로 압축

union by size에서 경로압축을 도입하면 , O(a(N)) 만큼으로 시간복잡도를 개선할 수 있다. 이때 a(N)은 아커만 함수의 역함수에 해당한다고 한다 ( 이것은 기울기가 매우 매우 작다고 한다.)

경로 압축은 root(x)를 구하는 방법에 대한 개선이다. 

## 구조체를 이용한 UnionFind 구현

```cpp
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
```