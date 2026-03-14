#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

//邻接矩阵形式

const int MaxV=600;
const int INF=0x3fffffff;

int G[MaxV][MaxV];
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
        for(int k=0;k<n;k++){
            if(visit[k]==false&&G[u][k]!=INF){
                if(d[u]+G[u][k]<d[k]){
                    d[k]=d[u]+G[u][k];
                    MaxTeam[k]=MaxTeam[u]+TeamsWeigh[k];
                    num[k]=num[u];
                }
                else if(d[u]+G[u][k]==d[k]){
                    if(MaxTeam[u]+TeamsWeigh[k]>MaxTeam[k]) MaxTeam[k]=MaxTeam[u]+TeamsWeigh[k];
                    num[k]+=num[u];
                }
            }
        }
    }
}


int main(){
    int m,c1,c2;
    scanf("%d %d %d %d",&n,&m,&c1,&c2);
    fill(G[0],G[0]+MaxV*MaxV,INF);
    for(int i=0;i<n;i++){
        scanf("%d",&TeamsWeigh[i]);
    }
    for(int i=0;i<m;i++){
        int s,e,dis;
        scanf("%d %d %d",&s,&e,&dis);
        G[s][e]=dis;
        G[e][s]=G[s][e];
    }

    Dijkstra(c1);
    printf("%d %d\n",num[c2],MaxTeam[c2]);
}