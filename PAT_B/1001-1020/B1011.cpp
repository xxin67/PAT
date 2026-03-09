#include<cstdio>

using namespace std;

int main(){
    int t;
    long long a,b,c;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%ld %ld %ld",&a,&b,&c);
        if(a+b>c) printf("Case #%d: true\n",i+1);
        else printf("Case #%d: false\n",i+1);
    }
}