#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct Poly{
    int expo;
    double coeff;
    Poly(){
        coeff=0;
        expo=-1;
    }
};

bool cmp(Poly s1,Poly s2){
    return s1.expo>s2.expo;
}

int main(){
    int n1,n2;
    vector<Poly> num1,num2;
    vector<Poly> ans;
    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        Poly temp;
        scanf("%d %lf",&temp.expo,&temp.coeff);
        num1.push_back(temp);
    }
    scanf("%d",&n2);
    for(int i=0;i<n2;i++){
        Poly temp;
        scanf("%d %lf",&temp.expo,&temp.coeff);
        num2.push_back(temp);
    }


    for(int i=0;i<num1.size();i++){
        for(int j=0;j<num2.size();j++){
            Poly multi_temp;
            multi_temp.expo=num1[i].expo+num2[j].expo;
            multi_temp.coeff=num1[i].coeff*num2[j].coeff;
            if(ans.size()==0){
                ans.push_back(multi_temp);
                continue;
            }
            else{
                for(int k=0;k<ans.size();k++){
                    if(ans[k].expo!=multi_temp.expo){
                        if(k==ans.size()-1){ 
                            ans.push_back(multi_temp);
                            break;
                        }
                        else continue;
                    }
                    else{
                        ans[k].coeff+=multi_temp.coeff;
                        break;
                    }
                }
            }
        }
    }

    sort(ans.begin(),ans.end(),cmp);

    vector<Poly> ans_Nozero;
    for(int i=0;i<ans.size();i++){
        if(ans[i].coeff!=0) ans_Nozero.push_back(ans[i]);
    }
    
    printf("%d ",ans_Nozero.size());
    for(int i=0;i<ans_Nozero.size();i++){
        if(i!=ans_Nozero.size()-1) printf("%d %.1lf ",ans_Nozero[i].expo,ans_Nozero[i].coeff);
        else printf("%d %.1lf\n",ans_Nozero[i].expo,ans_Nozero[i].coeff);
    }
}