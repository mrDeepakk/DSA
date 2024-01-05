#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;
    int a[n1];
    int b[n2];
    for(int i=0; i<n1; i++){
        a[i]=arr[left+i];
    }
    for(int i=0; i<n2; i++){
        b[i]=arr[mid+i+1];
    }
    int i=0;
    int j=0;
    int k=left;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
           arr[k++]=a[i++];
        }else{
           arr[k++]=b[j++];
        }
    }
    while(i<n1){
        arr[k++]=a[i++];
    }
    while(j<n2){
        arr[k++]=b[j++];
    }
}
void mergeSort(int arr[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main(){
    int arr[]={2,3,1,5,8,9,11,0,100};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergeSort(arr,0,n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}