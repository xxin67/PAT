#include<string>
#include<iostream>
#include<map>

using namespace std;

map<char,string> mp={
    {'1',"one"},{'2',"two"},{'3',"three"},{'4',"four"},{'5',"five"},{'6',"six"},
    {'7',"seven"},{'8',"eight"},{'9',"nine"},{'0',"zero"}
};

int main(){
    string N;
    cin>>N;
    int sum=0;
    for(int i=0;i<N.size();i++){
        sum+=N[i]-'0';
    }
    string ans;
    ans=to_string(sum);
    for(int i=0;i<ans.size();i++){
        if(i!=ans.size()-1) cout<<mp[ans[i]]<<" ";
        else cout<<mp[ans[i]]<<endl;
    }
}