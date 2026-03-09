<<<<<<< HEAD
#include<cstdio>
#include<cmath>

using namespace std;

int main(){
    int c1=0,c2=0;
    scanf("%d %d",&c1,&c2);
    int totalsecond=round((c2-c1)/100.0);
    int second=totalsecond%60;
    int minus=totalsecond/60%60;
    int hour=totalsecond/60/60%60;
    printf("%02d:%02d:%02d\n",hour,minus,second);
=======
#include<cstdio>
#include<cmath>

using namespace std;

int main(){
    int c1=0,c2=0;
    scanf("%d %d",&c1,&c2);
    int totalsecond=round((c2-c1)/100.0);
    int second=totalsecond%60;
    int minus=totalsecond/60%60;
    int hour=totalsecond/60/60%60;
    printf("%02d:%02d:%02d\n",hour,minus,second);
>>>>>>> 23efab8ece04991320451c7178db962c2765cb46
}