#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct Stu{
    char name[20];
    char stuid[20];
    int score;
};

bool cmp(Stu s1,Stu s2){
    return s1.score>s2.score;
}

int main(){
    int n;
    scanf("%d", &n);
    vector<Stu> stu(n);
    for(int i=0;i<n;i++){
        scanf("%s %s %d",stu[i].name,stu[i].stuid,&stu[i].score);
    }
    sort(stu.begin(),stu.end(),cmp);
    printf("%s %s\n",stu[0].name,stu[0].stuid);
    printf("%s %s\n",stu[n-1].name,stu[n-1].stuid);
}