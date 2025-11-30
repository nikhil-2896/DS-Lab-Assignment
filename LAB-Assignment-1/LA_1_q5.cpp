#include<iostream>
using namespace std;
int main(){
    int arr[2][2];
    int rows,cols;
    cout<<"enter no of rows and cols"<<endl;
    cin>>rows>>cols;
    cout<<"enter the elements in Matrix"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++)
        cin>>arr[i][j];
    }
    for(int i=0;i<rows;i++){
        int rowsum=0;
        for(int j=0;j<cols;j++){
            rowsum+=arr[i][j];
        }
        cout<<"sum of rows is "<<rowsum<<endl;
    }
    for(int i=0;i<rows;i++){
        int colsum=0;
        for(int j=0;j<cols;j++){
            colsum+=arr[j][i];
        }
        cout<<"sum of column is "<<colsum<<endl;
    }

}