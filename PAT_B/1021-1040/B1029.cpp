#include<iostream>
#include<string>
#include<map>
#include<queue>

using namespace std;

int main(){
    string should_in;
    string real_in;
    queue<char> err;
    int flag[3000]={0};
    cin>>should_in;
    cin>>real_in;
    int index_si=0,index_ri=0;
    while(1){
        if(should_in[index_si]!=real_in[index_ri]){
            char temp=should_in[index_si];
            if(should_in[index_si]>='a'&&should_in[index_si]<='z') temp-=32;
            if(flag[(int)temp]==0){
                flag[(int)temp]++;
                err.push(temp);
                index_si++;
            }
            else index_si++;
        }
        else{
            if(index_ri!=real_in.size()-1) index_ri++;
            index_si++;
        }
        if(index_ri==real_in.size()-1&&index_si>should_in.size()-1) break;
    }
    int qsize=err.size();
    for(int i=0;i<qsize;i++){
        if(!err.empty()){
            cout<<err.front();
            err.pop();
        }
    }
    cout<<endl;
}