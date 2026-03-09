#include<cstdio>

using namespace std;

int main(){
    int num[15];
    char min[60];
    int index=1;
    for(int i=0;i<10;i++){
        scanf("%d",&num[i]);
    }
    for(int i=1;i<10;i++){
        if(num[i]!=0){
            min[0]=i;
            num[i]--;
            break;
        }
    }
    for(int i=0;i<10;i++){
        while(num[i]!=0){
            min[index++]=i;
            num[i]--;
        }
    }
    for(int i=0;i<index;i++) printf("%d",min[i]);
    printf("\n");
    return 0;
}