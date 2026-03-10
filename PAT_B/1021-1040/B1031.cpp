#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

map<int,char> mp={
    {0,'1'},{1,'0'},{2,'X'},{3,'9'},{4,'8'},{5,'7'},{6,'6'},{7,'5'},
    {8,'4'},{9,'3'},{10,'2'}
};

const int weigh[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};

int main(){
    int n;
    cin>>n;
    vector<string> id;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        id.push_back(temp);
    }

    int count=0;
    for(int i=0;i<id.size();i++){
        int z_total=0;
        int flag=1;
        for(int j=0;j<id[i].size()-1;j++){
            if(id[i][j]>='0'&&id[i][j]<='9'){
                z_total+=(id[i][j]-'0')*weigh[j];
            }
            else{
                cout<<id[i];
                if(i!=id.size()-1) cout<<endl;
                flag=0;
                count++;
                break;
            }
        }
        if(flag==1){
            int z=z_total%11;
            if(id[i][id[i].size()-1]!=mp[z]){
                cout<<id[i];
                if(i!=id.size()-1) cout<<endl;
                count++;
            }
        }
    }
    if(count==0) cout<<"All passed";
}