/******************************************/
//********Written by JinHuyk. Mun*********//
/******************************************/

//BOJ 1072

#include <iostream>
#define MAX 1000000000
using namespace std;
int main(void){

    long long X,Y;
    cin >> X >> Y;
    long long Z = (Y*100)/X;
    if(Z>=99){
        cout << "-1";
        return 0;
    }
    else{
        long long left = 0, right = MAX;
        while (right - left > 1){
            long long mid = (left+right)/2;
            long long z = ((Y+mid)*100)/(X+mid);
            if(Z<z) right = mid;
            else left = mid;

        }
        cout << right<< endl;

    }


}
