#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"enter a string"<<endl;
    getline(cin,str);
    int start=0;
    int end=str.length()-1;
    while(start<end){
         swap(str[start],str[end]);
         start++;
         end--;

    }
    cout<<"reversed string is "<<str<<endl;
    return 0;
}