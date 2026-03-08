#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

bool IsPrime(int n){
    if(n<=1) return false;
    else{
        int sqr=sqrt(n);
        for(int i=2;i<=sqr;i++){
            if(n%i==0) return false;
        }
        return true;
    }
}

void PrimeTable(int end,vector<int> &t){
    int temp=0;
    while(end!=0){
        if(IsPrime(temp)){
            t.push_back(temp);
            temp++;
            end--;
        }
        else{
            temp++;
        }
    }
}

int main(){
    int m,n;
    int count=0;
    scanf("%d %d",&m,&n);
    vector<int> table;
    PrimeTable(n,table);
    for(int i=m-1;i<n;i++){
        count++;
        if(count%10==0){
            if(i!=n-1){
                printf("%d\n",table[i]);
            }
            else printf("%d",table[i]);
        }
        else{
            if(i!=n-1){
                printf("%d ",table[i]);
            }
            else printf("%d",table[i]);
        }
    }
    printf("\n");
}