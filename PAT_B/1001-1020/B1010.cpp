#include<cstdio>
#include<vector>

using namespace std;

struct Poly{
    int c;
    int index;
};

int main(){
    vector<Poly> p;
    Poly temp;
    while(scanf("%d %d",&temp.c,&temp.index)!=EOF){
        p.push_back(temp);
    }
    if(p.size()==1&&(p[0].c==0||p[0].index==0)){
        printf("%d %d",0,0);
    }
    
    for(int i=0;i<p.size();i++){
        if(p[i].index!=0){
            p[i].c=p[i].c*p[i].index;
            p[i].index--;
        }
        else p.erase(p.begin()+i);
    }
    for(int i=0;i<p.size();i++){
        if(i!=p.size()-1) printf("%d %d ",p[i].c,p[i].index);
        else printf("%d %d",p[i].c,p[i].index);
    }
}