#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int start,int end){
    int pivot=arr[end];
   
    int i=start-1;  
    for (int j = start ;j < end ;j++) {
        if (arr[j] <= pivot ){
        swap(arr[++i],arr[j]);
        }
    }
    swap(arr[++i],arr[end]);
    return i;
}


void quickSort(int arr[],int start,int end){

    if(start<end){
        //partitioning the array
        int pi=partition(arr,start,end);
        quickSort(arr,start,pi-1);
        quickSort(arr,pi+1,end);
    }
}

int main(){
    int arr[]={2,4,1,8,-1,3,99,1,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    quickSort(arr,0,n-1);
    cout<<endl;
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    

    return 0;
}

