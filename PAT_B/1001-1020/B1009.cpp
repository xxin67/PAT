<<<<<<< HEAD
#include<cstdio>
#include<cstring>

using namespace std;

int main(){
    char str[100];
    fgets(str,100,stdin);
    int len=strlen(str);
    int beg[100],end[100];
    end[0]=len-2;
    int i=len-1,j=0;
    while(i>=0){
        while(str[i]!=(char) 32){
            i--;
            if(i<0) break;
        }
        beg[j]=i+1;
        end[j+1]=i-1;
        j++;
        i--;
    }
    for(int k=0;k<j;k++){
        while(beg[k]<=end[k]){
            printf("%c",str[beg[k]]);
            beg[k]++;
        }
        if(k!=j-1)    printf(" ");
    }
    printf("\n");
    return 0;
=======
#include<cstdio>
#include<cstring>

using namespace std;

int main(){
    char str[100];
    fgets(str,100,stdin);
    int len=strlen(str);
    int beg[100],end[100];
    end[0]=len-2;
    int i=len-1,j=0;
    while(i>=0){
        while(str[i]!=(char) 32){
            i--;
            if(i<0) break;
        }
        beg[j]=i+1;
        end[j+1]=i-1;
        j++;
        i--;
    }
    for(int k=0;k<j;k++){
        while(beg[k]<=end[k]){
            printf("%c",str[beg[k]]);
            beg[k]++;
        }
        if(k!=j-1)    printf(" ");
    }
    printf("\n");
    return 0;
>>>>>>> 23efab8ece04991320451c7178db962c2765cb46
}