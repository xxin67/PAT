<<<<<<< HEAD
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<int> Ans[5];
    int a1=0,a2=0,a3=0;
    double a4_sum=0.0;
    for(int i=0;i<n;i++){
        int temp=0;
        scanf("%d",&temp);
        if(temp%10==0) Ans[0].push_back(temp);
        if(temp%5==1) Ans[1].push_back(temp);
        if(temp%5==2) Ans[2].push_back(temp);
        if(temp%5==3) Ans[3].push_back(temp);
        if(temp%5==4) Ans[4].push_back(temp);
    }
    int a5_max=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<Ans[i].size();j++){
            if(i==0) a1+=Ans[i][j];
            if(i==1){
                a2+=pow(-1,j)*Ans[i][j];
            }
            if(i==2){
                a3=Ans[i].size();
            }
            if(i==3){
                a4_sum+=Ans[i][j];
            }
            if(i==4){
                a5_max=max(a5_max,Ans[i][j]);
            }
        }
    }
    for(int i=0;i<5;i++){
        if(Ans[i].size()==0){
            if(i!=4) printf("N ");
            else printf("N");
        }
        else{
            if(i==0) printf("%d ",a1);
            if(i==1) printf("%d ",a2);
            if(i==2) printf("%d ",a3);
            if(i==3) printf("%.1lf ",a4_sum/Ans[i].size());
            if(i==4) printf("%d",a5_max);
        }
    }
    printf("\n");
    return 0;
=======
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<int> Ans[5];
    int a1=0,a2=0,a3=0;
    double a4_sum=0.0;
    for(int i=0;i<n;i++){
        int temp=0;
        scanf("%d",&temp);
        if(temp%10==0) Ans[0].push_back(temp);
        if(temp%5==1) Ans[1].push_back(temp);
        if(temp%5==2) Ans[2].push_back(temp);
        if(temp%5==3) Ans[3].push_back(temp);
        if(temp%5==4) Ans[4].push_back(temp);
    }
    int a5_max=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<Ans[i].size();j++){
            if(i==0) a1+=Ans[i][j];
            if(i==1){
                a2+=pow(-1,j)*Ans[i][j];
            }
            if(i==2){
                a3=Ans[i].size();
            }
            if(i==3){
                a4_sum+=Ans[i][j];
            }
            if(i==4){
                a5_max=max(a5_max,Ans[i][j]);
            }
        }
    }
    for(int i=0;i<5;i++){
        if(Ans[i].size()==0){
            if(i!=4) printf("N ");
            else printf("N");
        }
        else{
            if(i==0) printf("%d ",a1);
            if(i==1) printf("%d ",a2);
            if(i==2) printf("%d ",a3);
            if(i==3) printf("%.1lf ",a4_sum/Ans[i].size());
            if(i==4) printf("%d",a5_max);
        }
    }
    printf("\n");
    return 0;
>>>>>>> 23efab8ece04991320451c7178db962c2765cb46
}