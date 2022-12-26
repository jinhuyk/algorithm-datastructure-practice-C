/******************************************/
//********Written by JinHuyk. Mun*********//
/******************************************/

//BOJ 1253

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<long long> A(N);
    int cnt = 0;
    for(int i =0;i<N;i++) cin >> A[i];
    sort(A.begin(),A.end());
    for(int i =0;i<N;i++){
        long long P = A[i];
        int left = 0, right = N-1;
        while(right - left >0){
            int sum = A[right]+A[left];
            if(sum == P){
                if(left!=i && right!=i){
                    cnt++;
                    break;
                }
                else if(left == i) left++;
                else if(right==i)right--;
            }
            else if (sum < P )left++;
            else right--;
        }
    }
    cout << cnt<<endl;
}

