#include<iostream>
using namespace std;
int main(){
    int A[2][2],B[2][2],C[2][2];
    cout<<"enter the elements of matrix in A"<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++)
        cin>>A[i][j];
    }
    cout<<"enter the elements of matrix in B"<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++)
        cin>>B[i][j];
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
        C[i][j]=0;
        for(int k=0;k<2;k++)
        C[i][j]+=A[i][k]*B[k][j];
    }
  }   
  cout<<"matrix multiplication is "<<endl;
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++)
    cout<<C[i][j]<<endl;
  }
}