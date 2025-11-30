#include<iostream>
using namespace std;
int missno(int arr[],int n){
    int sum=0;
    for(int i=0;i<n-1;i++)
    sum+=arr[i];

    int missno=(n*(n+1)/2)-sum;
    return missno;
}
int main(){
    int arr[]={1,3,4,5,6};
    int n=6;
    cout<<"Missing number is "<<missno(arr,n)<<endl;
    
          
}