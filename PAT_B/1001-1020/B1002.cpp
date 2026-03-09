#include<cstdio>
#include<string>
#include<iostream>
#include<map>

using namespace std;

map<char,string> pin_num={
    {0,"ling"},{1,"yi"},{2,"er"},{3,"san"},{4,"si"},{5,"wu"},{6,"liu"},{7,"qi"},
    {8,"ba"},{9,"jiu"}
};


int main(){
    string n;
    cin>>n;
    int len=n.length();
    string sum;
    int temp;
    int count=0;
    for(int i=0;i<len;i++){
        temp+=n[i]-48;
    }
    while(temp!=0){
        sum[count++]=temp%10;
        temp/=10;
    }
    for(int j=count-1;j>=0;j--){
        if(j==0){
            cout<<pin_num[sum[j]];
        }
        else{
            cout<<pin_num[sum[j]]<<" ";
        }
    }
    cout<<endl;
    return 0;
}