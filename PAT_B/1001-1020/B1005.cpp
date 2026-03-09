<<<<<<< HEAD
#include<cstdio>
#include<algorithm>

using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    int k;
    int ans[300]={0};
    int count=0;
    int flag[100000]={0};
    scanf("%d",&k);
    int n[300]={0};
    for(int i=0;i<k;i++){
        scanf("%d",&n[i]);
        int temp=n[i];
        while(temp!=1){
            if(temp%2==0){
                temp/=2;
                flag[temp]++;
            }
            else{
                temp=(3*temp+1)/2;
                flag[temp]++;
            }
        }
    }
    for(int i=0;i<k;i++){
        if(flag[n[i]]==0) ans[count++]=n[i];
    }
    sort(ans,ans+count,cmp);
    for(int i=0;i<count;i++){
        if(i==count-1) printf("%d",ans[i]);
        else printf("%d ",ans[i]);
    }
    printf("\n");
=======
#include<cstdio>
#include<algorithm>

using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    int k;
    int ans[300]={0};
    int count=0;
    int flag[100000]={0};
    scanf("%d",&k);
    int n[300]={0};
    for(int i=0;i<k;i++){
        scanf("%d",&n[i]);
        int temp=n[i];
        while(temp!=1){
            if(temp%2==0){
                temp/=2;
                flag[temp]++;
            }
            else{
                temp=(3*temp+1)/2;
                flag[temp]++;
            }
        }
    }
    for(int i=0;i<k;i++){
        if(flag[n[i]]==0) ans[count++]=n[i];
    }
    sort(ans,ans+count,cmp);
    for(int i=0;i<count;i++){
        if(i==count-1) printf("%d",ans[i]);
        else printf("%d ",ans[i]);
    }
    printf("\n");
>>>>>>> 23efab8ece04991320451c7178db962c2765cb46
}