#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct Stu{
    int stuid;
    int moral;
    int intell;
    int type;
    int sum;
};

bool cmp(Stu s1, Stu s2) {
    if (s1.type != s2.type) return s1.type < s2.type;
    if (s1.sum != s2.sum) return s1.sum > s2.sum;
    if (s1.moral != s2.moral) return s1.moral > s2.moral;
    return s1.stuid < s2.stuid;
}

int main(){
    int n,l,h;
    scanf("%d %d %d",&n,&l,&h);
    vector<Stu> stu;
    for(int i=0;i<n;i++){
        Stu temp;
        scanf("%d %d %d",&temp.stuid,&temp.moral,&temp.intell);
        if(temp.moral<l||temp.intell<l) continue;
        else{
            temp.sum=temp.moral+temp.intell;
            if(temp.moral>=h&&temp.intell>=h) temp.type=0;
            else {
                if(temp.moral>=h&&temp.intell<h) temp.type=1;
                else {
                    if(temp.moral<h&&temp.intell<h&&temp.moral>=temp.intell) temp.type=2;
                    else temp.type=3;
                }
            }
        }
        stu.push_back(temp);
    }
    sort(stu.begin(),stu.end(),cmp);
    printf("%d\n",stu.size());
    for(int i=0;i<stu.size();i++){
        if(i!=stu.size()-1){
            printf("%d %d %d\n",stu[i].stuid,stu[i].moral,stu[i].intell);
        }
        else printf("%d %d %d",stu[i].stuid,stu[i].moral,stu[i].intell);
    }
    return 0;
}