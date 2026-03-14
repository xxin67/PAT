#include<cstdio>
#include<queue>

using namespace std;

int main(){
    int n;
    queue<int> q;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        q.push(temp);
    }

    int currentfloor=0;
    int total=0;
    while(q.size()!=0){
        if(q.front()>currentfloor){
            total+=(q.front()-currentfloor)*6+5;
            currentfloor=q.front();
            q.pop();
        }
        else{
            total+=(currentfloor-q.front())*4+5;
            currentfloor=q.front();
            q.pop();
        }
    }

    printf("%d\n",total);
}