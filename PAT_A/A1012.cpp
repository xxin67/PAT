#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

struct ClassRank{
    char c;
    int r;
};

struct Id_Score{
    string id;
    int score;
};

struct Rank{
    string id;
    ClassRank scoreRank[4];
};

map<string,int> mp;
map<int,char> mp1={
    {0,'C'},{1,'M'},{2,'E'},{3,'A'}
};

bool cmp(Id_Score n1,Id_Score n2){
    return n1.score>n2.score;
}

void RankSort(vector<Id_Score> p,vector<Rank> &r,int idx){
    sort(p.begin(),p.end(),cmp);
    int current_r=1;
    int prior_r=0;
    for(int i=0;i<p.size();i++){
        string id_t=p[i].id;
        if(i==0){
            r[mp[id_t]].scoreRank[idx].r=current_r;
            r[mp[id_t]].scoreRank[idx].c=mp1[idx];
            prior_r=current_r;
            current_r++;
        }
        else{
            if(p[i].score==p[i-1].score){
                r[mp[id_t]].scoreRank[idx].r=prior_r;
                r[mp[id_t]].scoreRank[idx].c=mp1[idx];
                current_r++;
            }else{
                r[mp[id_t]].scoreRank[idx].r=current_r;
                r[mp[id_t]].scoreRank[idx].c=mp1[idx];
                prior_r=current_r;
                current_r++;
            }
        }
    }
}

bool cmp1(ClassRank t1,ClassRank t2){
    map<char,int> priority={
        {'A',4},{'C',3},{'M',2},{'E',1}
    };
    if(t1.r!=t2.r) return t1.r<t2.r;
    else{
        return priority[t1.c]>priority[t2.c];
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<Id_Score> Perform[4];
    vector<Rank> rank(n);
    for(int i=0;i<n;i++){
        string id_temp;
        cin>>id_temp;
        rank[i].id=id_temp;
        mp[id_temp]=i;
        int totalscore=0;
        for(int j=0;j<4;j++){
            Id_Score temp;
            int score_temp;
            temp.id=id_temp;
            if(j!=3){ 
                cin>>score_temp;
                temp.score=score_temp;
                totalscore+=score_temp;
                Perform[j].push_back(temp);
                continue;
            }
            else{
                temp.score=totalscore/3;
                Perform[j].push_back(temp);
                break;
            }
        }
    }

    vector<string> WaitCheck(m);
    for(int i=0;i<m;i++){
        cin>>WaitCheck[i];
    }

    for(int i=0;i<4;i++){
        RankSort(Perform[i],rank,i);
    }

    for(int i=0;i<m;i++){
        string CheckId=WaitCheck[i];
        if(mp.find(CheckId)==mp.end()){
            cout<<"N/A"<<endl;
            continue;
        }
        else{
            sort(rank[mp[CheckId]].scoreRank,rank[mp[CheckId]].scoreRank+4,cmp1);
            ClassRank temp;
            temp=rank[mp[CheckId]].scoreRank[0];
            cout<<temp.r<<" "<<temp.c<<endl;
        }
    }
}