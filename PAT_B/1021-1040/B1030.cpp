#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n,p;
    scanf("%d %d",&n,&p);
    vector<int> num;
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        num.push_back(temp);
    }
    sort(num.begin(),num.end());
    int i=0,j=0;
    int max=0;
    int count=0;
    while(j!=num.size()){
        if(num[j]<=(long long)num[i]*p){
            j++;
            count++;
            if(j==num.size()){
                if(count>max) max=count;
            }
        }
        else{
            i++;
            if(count>max) max=count;
            count--;
        }
    }
    printf("%d\n",max);
}