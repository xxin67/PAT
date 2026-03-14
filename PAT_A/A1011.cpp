#include<cstdio>
#include<vector>
#include<map>

using namespace std;

map<int,char> mp={
    {0,'W'},{1,'T'},{2,'L'}
};

struct Pairodds{
    char result;
    double ratio;
    Pairodds(char c,double r):result(c),ratio(r){}
};

int main(){
    vector<Pairodds> ans;
    for(int i=0;i<3;i++){
        int flag_temp=-1;
        double max_temp=-1;
        for(int j=0;j<3;j++){
            double temp;
            scanf("%lf",&temp);
            if(temp>max_temp){
                max_temp=temp;
                flag_temp=j;
            }
        }
        Pairodds temp(mp[flag_temp],max_temp);
        ans.push_back(temp);
    }

    double profit=1;
    for(int i=0;i<3;i++){
        printf("%c ",ans[i].result);
        profit*=ans[i].ratio;
    }
    printf("%.2lf\n",(profit*0.65-1)*2);
}