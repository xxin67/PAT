#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>

using namespace std;

struct TNode{
    int id;
    int k;
    int child[1000];
    TNode(){
        id=0;
        k=0;
        memset(child,0,sizeof(child));
    }
};



int main(){
    int n,m;
    cin>>n>>m;
    TNode nodes[n+1];
    for(int i=0;i< m;i++){
        string id_temp;
        int k_temp;
        cin>>id_temp>>k_temp;
        int id_int=stoi(id_temp);
        nodes[id_int].k=k_temp;
        for(int j=0;j<k_temp;j++){
            string child_temp;
            cin>>child_temp;
            nodes[id_int].child[j]=stoi(child_temp);
        }
    }

    queue<int> q;
    q.push(1);
    int ans[1000]={0};
    int layer=0;
    while(!q.empty()){
        int qsize=q.size();
        int leafcount=0;
        for(int i=0;i<qsize;i++){
            int front_temp=q.front();
            q.pop();
            if(nodes[front_temp].k==0) leafcount++;
            else{
                for(int j=0;j<nodes[front_temp].k;j++){
                    q.push(nodes[front_temp].child[j]);
                }
            }
        }
        ans[layer++]=leafcount;
    }
    for(int i=0;i<layer;i++){
        if(i!=layer-1) cout<<ans[i]<<" ";
        else cout<<ans[i]<<endl;
    }
}