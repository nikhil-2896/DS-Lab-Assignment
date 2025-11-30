#include<iostream>
using namespace std;
int main(){
    int Matrix[2][2],Transpose[2][2];
    int rows,cols;
    cout<<"enter no of rows and cols"<<endl;
    cin>>rows>>cols;
    cout<<"enter the elements in Matrix"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++)
        cin>>Matrix[i][j];
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            Transpose[j][i]=Matrix[i][j];
        }
    }
    for(int i=0;i<cols;i++){
        for(int j=0;j<rows;j++)
        cout<<Transpose[i][j]<<" ";
        cout<<endl;
    }
}