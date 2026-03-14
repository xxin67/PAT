#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct RecorD{
    string id;
    string entry_time;
    string exit_time;
};

bool cmp_entry(RecorD r1,RecorD r2){
    return r1.entry_time<r2.entry_time;
}

bool cmp_exit(RecorD r1,RecorD r2){
    return r1.exit_time>r2.exit_time;
}

int main(){
    int n;
    cin>>n;
    vector<RecorD> r(n);
    for(int i=0;i<n;i++){
        cin>>r[i].id>>r[i].entry_time>>r[i].exit_time;
    }
    sort(r.begin(),r.end(),cmp_entry);
    cout<<r[0].id<<" ";
    sort(r.begin(),r.end(),cmp_exit);
    cout<<r[0].id<<endl;
}