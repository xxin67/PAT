<<<<<<< HEAD
#include<cstdio> 

using namespace std;

int main(){
    int a,b,d;
    char out[10000];
    int count=0;
    scanf("%d %d %d",&a,&b,&d);
    int sum=a+b;
    while(sum/d!=0){
        out[count++]=sum%d;
        sum=sum/d;
    }
    out[count]=sum;
    for(int i=count;i>=0;i--){
        printf("%d",out[i]);
    }
    return 0;
=======
#include<cstdio> 

using namespace std;

int main(){
    int a,b,d;
    char out[10000];
    int count=0;
    scanf("%d %d %d",&a,&b,&d);
    int sum=a+b;
    while(sum/d!=0){
        out[count++]=sum%d;
        sum=sum/d;
    }
    out[count]=sum;
    for(int i=count;i>=0;i--){
        printf("%d",out[i]);
    }
    return 0;
>>>>>>> 23efab8ece04991320451c7178db962c2765cb46
}