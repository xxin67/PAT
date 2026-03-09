#include<cstdio>

 using namespace std;

int main(){
    int n,r=0;
    char c;
    int flag=0;
    scanf("%d %c",&n,&c);
    int i=1;
    while(1){
        if(n<2*i*i-1){
            i=i-1;
            break;
        }
        else i++;
    }
    int rows_num=2*i-1;
    r=n-(2*i*i-1);
    for(int j=0;j<rows_num;j++){
        for(int k=0;k<(rows_num-(2*i-1))/2;k++){
            printf(" ");
        }
        for(int k=0;k<2*i-1;k++){
            printf("%c",c);
        }
        printf("\n");
        if(i==1) flag=1;
        if(flag==0) i--;
        else i++;
    }
    printf("%d\n",r);
}