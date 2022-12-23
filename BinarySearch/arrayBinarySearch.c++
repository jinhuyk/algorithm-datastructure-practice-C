/******************************************/
//********Written by JinHuyk. Mun*********//
/******************************************/

#include <stdio.h>

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

int main(void){
    //Binary_search_normaliz
    int key = 7;
    int index = binary_search_n(key);
    if(index == -1) printf("key is no this arr");
    else printf("key is Arr index[ %d ] \n",index+1);
}