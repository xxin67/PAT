#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
    string broken_key,shouldin;
    int nocaps_flag=0;
    getline(cin,broken_key);
    getline(cin,shouldin);
    if(broken_key.size()==0){
        cout<<shouldin<<endl;
        return 0;
    }
    map<char,int> mp;
    int count=0;
    for(int i=0;i<broken_key.size();i++){
        mp[broken_key[i]]=1;
        if(broken_key[i]=='+') nocaps_flag=1;
    }
    for(int i=0;i<shouldin.size();i++){
        if(nocaps_flag==1&&shouldin[i]>='A'&&shouldin[i]<='Z'){
            continue;
        }
        if(mp[shouldin[i]]==1||(mp[shouldin[i]-32]==1&&shouldin[i]>='a'&&shouldin[i]<='z')) continue;
        count++;
        cout<<shouldin[i];
    }
    cout<<endl;
}