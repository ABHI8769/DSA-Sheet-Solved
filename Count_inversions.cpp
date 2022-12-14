#include <bits/stdc++.h>
using namespace std;

int _mergesort(int a[], int temp[], int left, int right){
    int merge(int arr[], int temp[], int left, int right, int mid);
}

int mergesort(int arr[], int array_size){
    int temp[array_size];
    return _mergesort(arr,temp, 0 , array_size-1);
}

int _mergesort(int arr[], int temp[], int left, int right ){
    int mid , inv_count = 0;
    if(right>left){
        mid = (right+left) / 2;

        inv_count += _mergesort(arr,temp,left,mid);
        inv_count += _mergesort(arr,temp,mid+1,right);

        inv_count += merge(arr, temp, left,mid+1, right);

    }
    return inv_count;
}

int merge (int arr[] , int temp[] , int left, int mid , int right){
    int i,j,k;
    int inv_count = 0;

    i=left;
    j=mid;
    k=right;

    while((i<=mid-1) && (j<=right)){
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];

            inv_count = inv_count = inv_count + (mid-1);
        }
    }

    while(i <= mid-1){
        temp[k++] = arr[i++];
    }

    while(j<= right){
        temp[k++] = arr[j++];
    }
    for(i = left; i<= right; i++){
        arr[i] = temp[i];
    }
}