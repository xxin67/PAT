#include<cstdio>
#include<vector>

using namespace std;

struct Poly{
    int N;
    double aN;
    Poly(){
        N=0;
        aN=0;
    }
};

int main(){
    int K1=0,K2=0;
    vector<Poly> Num1,Num2;
    scanf("%d",&K1);
    for(int i=0;i<K1;i++){
        Poly temp;
        scanf("%d %lf",&temp.N,&temp.aN);
        Num1.push_back(temp);
    }
    scanf("%d",&K2);
    for(int i=0;i<K2;i++){
        Poly temp;
        scanf("%d %lf",&temp.N,&temp.aN);
        Num2.push_back(temp);
    }

    int i=0;
    int j=0;
    vector<Poly> ans;
    while(i!=Num1.size()&&j!=Num2.size()){
        Poly temp;
        if(Num1[i].N==Num2[j].N){
            temp.N=Num1[i].N;
            temp.aN=Num1[i].aN+Num2[j].aN;
            if(temp.aN!=0){
                ans.push_back(temp);
                i++;
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        if(Num1[i].N>Num2[j].N){
            temp=Num1[i];
            ans.push_back(temp);
            i++;
        }
        if(Num1[i].N<Num2[j].N){
            temp=Num2[j];
            ans.push_back(temp);
            j++;
        }
    }
    if(i!=Num1.size()){
        for(int k=i;k<Num1.size();k++){
            Poly temp=Num1[k];
            ans.push_back(temp);
        }
    }
    if(j!=Num2.size()){
        for(int k=j;k<Num2.size();k++){
            Poly temp=Num2[k];
            ans.push_back(temp);
        }
    }
    if(ans.size()!=0) printf("%d ",ans.size());
    else printf("%d",ans.size());
    for(int k=0;k<ans.size();k++){
        if(k!=ans.size()-1){
            printf("%d %.1lf ",ans[k].N,ans[k].aN);
        }
        else printf("%d %.1lf\n",ans[k].N,ans[k].aN);
    }
}