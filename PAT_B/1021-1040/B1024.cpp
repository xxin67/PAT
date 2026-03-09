#include<iostream>
#include<string>
#include<vector>

using namespace std;

int IndexT(string s){
    int index=0;
    int it=s.find('E')+2;
    for(it;it<s.size();it++){
        index=index*10+(s[it]-'0');
    }
    return index;
}

void PR(string s,vector<int> n,char i_s,int index){
    if(s[0]=='-'){
        cout<<"-";
    }
        if(i_s=='+'){
            for(int i=0;i<n.size();i++){
                if(n.size()==index+1) cout<<n[i];
                else{
                    if(i==index+1) cout<<"."<<n[i];
                    else cout<<n[i];
                }
            }
        }
        if(i_s=='-'){
            for(int i=0;i<n.size();i++){
                if(i==0) cout<<n[i]<<".";
                else cout<<n[i];
            }
        }
}


void Tran(string s){
    int count=-1;
    char index_signal=s[s.find('E')+1];
    int index=IndexT(s);
    vector<int> num;
    vector<int> temp;
    for(int it=0;it!=s.find('E');it++){
        if(s[it]>='0'&&s[it]<='9'){
            count++;
            temp.push_back(s[it]-'0');
        }
    }
    if(index_signal=='-'){
        int idx=index;
        while(count>=0){
            if(idx>0){
                num.push_back(0);
                idx--;
            }
            else{
                num.push_back(temp[temp.size()-1-count]);
                count--;
            }
        }
    }
    if(index_signal=='+'){
        if(count >= index) {
            for(int j=0; j<temp.size(); j++) num.push_back(temp[j]);
        } else {
            for(int j=0; j<temp.size(); j++) num.push_back(temp[j]);
            int need = index + 1 - temp.size();
            for(int k=0; k<need; k++) num.push_back(0);
        }
    }
    PR(s,num,index_signal,index);
}

int main(){
    string s;
    cin>>s;
    Tran(s);
    cout<<endl;
    return 0;
}