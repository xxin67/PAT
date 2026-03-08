#include<cstdio>

using namespace std;

void reverse(int begin,int end,int *num){
    int length=end-begin;
    for(int i=0;i<length/2;i++){
        int temp=num[begin+i];
        num[begin+i]=num[end-1-i];
        num[end-1-i]=temp;
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int num[n]={0};
    for(int i=0;i<n;i++) scanf("%d",&num[i]);
    reverse(0,n-(m%n),num);
    reverse(n-(m%n),n,num);
    reverse(0,n,num);
    for(int i=0;i<n;i++){
        if(i!=n-1) printf("%d ",num[i]);
        else printf("%d",num[i]);
    }
    printf("\n");
}