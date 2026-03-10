#include<cstdio>

using namespace std;

int main(){
    int n;
    int order,score_temp;
    scanf("%d",&n);
    int score[n+1]={0};
    for(int i=1;i<n+1;i++){
        scanf("%d%d",&order,&score_temp);
        score[order]+=score_temp;
    }
    int max_order,max=-1;
    for(int i=1;i<n+1;i++){
        if(score[i]>max){
            max=score[i];
            max_order=i;
        }
    }
    printf("%d %d\n",max_order,max);
    return 0;
}