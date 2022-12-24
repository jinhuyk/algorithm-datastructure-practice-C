
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){

    int N;
    cin >> N;
    vector<int> A(N);
    for(int i =0;i<N;i++){
        cin >> A[i];
    }

    int M = 0;
    for(int i=0;i<N;i++) M = max(M, A[i]);
    
    int left = 0, right = M;
    while(right - left > 1 ){
        int mid = (left + right) /2;

        int count = 0;
        for(int i = 0;i<N;i++){
            if(mid > A[i]) count++;
        }
        if(count >= (N-1)/2) right = mid;
        else left = mid;
    }
    cout << right <<endl;
}
