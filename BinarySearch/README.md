# 이진탐색법

## ⌚ 학습 기간

2022.12.24-

## 배열 이진 탐색

배열 이진 탐색의 기본적인 조건은 정렬된 배열이다.

> *이조건을 까먹고, JAVA programming 기말시험을 보다가 BinarySort 문제에서 계속 오류를 발생시켜 엄청난 점수를 잃었다.
> 

 

배열 이진 탐색은 정렬된 배열을 기본으로 한다.

N을 배열의 크기라 하였을 때, left, mid, right라는 변수를 생성해논다. 

초기값은 left = 0, right = N-1 mid = (left+right)/2 이다.

이후 구하고자 하는 key 값을 mid 와 비교하여 

mid 보다 key가 크다면 left = mid+1 로 바꾸어주는 작업을

mid 보다 key가 작다면 right = mid-1로 바꾸어주는 작업을

mid = key 라면 탐색 종료를 한다.

배열 이진탐색의 시간 복잡도를 생각해본다면 다음과 같다.

$$
O(log N)
$$

### 정수범위에서의 이진탐색

> 각 정수 x에 대해 true / false로 판정하는 조건 P가 주어졌다면 어떤 정수 l, r이 졶재하고 다음이 성립한다.
P(l) = false, P(r) = true
어떤 정수 M이 존재하고 x<M 인 x에 대해 P(x) = false, x≥ M인 x에 대해 P(x) = true이다.
> 

다음 조건을 직접 정수 배열에서 찾는 코드를 제작해보았다.

```c
int arr[]={1,3,5,7,9,11,13,15};
int N = 8;

int binary_search_n(int key){
    int left, right;
    left = 0;
    right = N-1;

    while(right - left > 1){
        int mid = left +( right - left )/2;
        if(arr[mid]>= key) right = mid;
        else left = mid;
    }

    if(arr[right]!= key){
        return -1;
    }

    return right;
}
```

### 이진 탐색을 이용한 중앙값 구하기

- **기본적인 중앙값 구하기**
    
    정렬을 하여 직접 중앙값을 찾는 경우을 알수 있다. a[(n/2)]
    
- **이진탐색 판정**
