#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

//邻接表形式

const int MaxV=600;
const int INF=0x3fffffff;

struct Node{
    int v;
    int dis;
};

vector<Node> Adj[MaxV];
int n;
int d[MaxV];
int MaxTeam[MaxV];
int TeamsWeigh[MaxV];
int num[MaxV];
bool visit[MaxV]={false};

void Dijkstra(int s){
    fill(d,d+MaxV,INF);
    memset(num,0,sizeof(num));
    memset(MaxTeam,0,sizeof(MaxTeam));
    d[s]=0;
    MaxTeam[s]=TeamsWeigh[s];
    num[s]=1;
    for(int i=0;i<n;i++){
        int u=-1,Min=INF;
        for(int j=0;j<n;j++){
            if(visit[j]==false&&d[j]<Min){
                u=j;
                Min=d[j];
            }
        }
        if(u==-1) return;
        visit[u]=true;
        for(int k=0;k<Adj[u].size();k++){
            int v_temp=Adj[u][k].v;
            if(visit[v_temp]==false){
                if(d[u]+Adj[u][k].dis<d[v_temp]){
                    d[v_temp]=d[u]+Adj[u][k].dis;
                    MaxTeam[v_temp]=MaxTeam[u]+TeamsWeigh[v_temp];
                    num[v_temp]=num[u];
                }
                else if(d[u]+Adj[u][k].dis==d[v_temp]){
                    if(MaxTeam[u]+TeamsWeigh[v_temp]>MaxTeam[v_temp]) MaxTeam[v_temp]=MaxTeam[u]+TeamsWeigh[v_temp];
                    num[v_temp]+=num[u];
                }
            }
        }
    }
}


int main(){
    int m,c1,c2;
    scanf("%d %d %d %d",&n,&m,&c1,&c2);
    for(int i=0;i<n;i++){
        scanf("%d",&TeamsWeigh[i]);
    }
    for(int i=0;i<m;i++){
        Node temp;
        int s_temp,e_temp;
        scanf("%d %d %d",&s_temp,&temp.v,&temp.dis);
        Adj[s_temp].push_back(temp);
        e_temp=temp.v;
        temp.v=s_temp;
        s_temp=e_temp;
        Adj[s_temp].push_back(temp);
    }

    Dijkstra(c1);
    printf("%d %d\n",num[c2],MaxTeam[c2]);
}