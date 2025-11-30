#include<iostream>
using namespace std;
int main(){
    int arr[]={12,53,54,57,93,108,172,345};
    int n=sizeof(arr)/sizeof(arr[0]);
    int start=0,end=n-1,mid,target=93;
    while(start<=end){
        mid=start+(end-start)/2;
        if(arr[mid]==target){
        cout<<"got the index "<<mid<<endl;
        break;
        }
        else if(arr[mid]<target)
        start=mid+1;
        else 
        end=mid-1;
    }
    return 0;
}