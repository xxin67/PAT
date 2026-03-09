#include<iostream>
#include<string>
#include<vector>

using namespace std;

void Change(string s,vector<int> &a){
    for(int i=0;i<s.size();i++){
        a.push_back(s[i]-'0');
    }
}

int main(){
    string s;
    vector<int> N;
    int count[10]={0};
    cin>>s;
    Change(s,N);
    for(int i=0;i<N.size();i++){
        count[N[i]]++;
    }
    for(int i=0;i<10;i++){
        if(count[i]!=0){
            cout<<i<<":"<<count[i]<<endl;
        }
    }
    return 0;
}