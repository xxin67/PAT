#include<cstdio>
#include<cmath>

using namespace std;

bool IsPrime(int n){
    if(n<=1) return false;
    int sqr=(int) sqrt(n);
    for(int i=2;i<=sqr;i++){
        if(n%i==0) return false;
    }
    return true;
}

void PrimeTable(int range,int &count,int *table){
    for(int i=1;i<=range;i++){
        if(IsPrime(i)==true){
            table[count++]=i;
        } 
    }
}

int main(){
    int n=0,count=0;
    int ans=0;
    scanf("%d",&n);
    int table[n]={0};
    PrimeTable(n,count,table);
    for(int i=0;i<count;i++){
        if(table[i+1]-table[i]==2) ans++;
    }
    printf("%d\n",ans);
}