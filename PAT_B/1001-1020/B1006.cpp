#include<cstdio>

using namespace std;

int main(){
    int n;
    int i = 0;
    int fig[5];
    scanf("%d",&n);
    for (;n!=0;n/=10){
        fig[i++] = n % 10;
    }
    for (i; i > 0;i--){
        for (int j = 0; j < fig[i - 1];j++){
            if(i==3)
                printf("B");
            if(i==2)
                printf("S");
            if(i==1){
                printf("%d", j + 1);
            }
        }
    }
    printf("\n");
    return 0;
}