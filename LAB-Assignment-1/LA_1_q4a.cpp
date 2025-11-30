#include<iostream>
using namespace std;
int main(){
    int arr[] = {2, 3, 2, 4, 3, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    for(int i=0;i<n/2;i++){
        swap(arr[i],arr[n-1-i]);
    }
    cout<<"reversed array is\n";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}