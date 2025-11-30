#include<iostream>
#include<string>
using namespace std;
int main(){
    string str1,str2;
    cout<<"enter first string "<<endl;
    getline(cin,str1);
    cout<<"enter second string "<<endl;
    getline(cin,str2);
    str1+=str2;
    cout<<str1<<endl;
    return 0;
}