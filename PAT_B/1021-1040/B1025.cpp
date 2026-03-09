#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<map>


using namespace std;

struct LNode{
    string address;
    int data;
    string next;
};

void BuildLink(vector<LNode> &l,string h,map<string,LNode> mp){
    string next_flag=h;
    while(next_flag!="-1"){
        auto it = mp.find(next_flag);
        if (it == mp.end()) break;   // 防止意外，理论上不会发生
        l.push_back(it->second);
        next_flag = it->second.next;
    }
}

void Reverse(vector<LNode> l,vector<LNode> &a,int k){
    stack<LNode> s;
    int count=0;
    int begin=0,end=0;
    for(int i=0;i<l.size();i++){
        count++;
        end++;
        if(count%k==0){
            for(begin;begin<end;begin++){
                s.push(l[begin]);
            }
            for(int j=0;j<k;j++){
                LNode temp=s.top();
                s.pop();
                a.push_back(temp);
            }
        }
    }
    if(count%k!=0){
        for(begin;begin<end;begin++){
            a.push_back(l[begin]);
        }
    }
}

int main(){
    string head;
    int n,k;
    vector<LNode> l;
    map<string,LNode> mp;
    vector<LNode> ans;
    cin>>head>>n>>k;
    for(int i=0;i<n;i++){
        LNode temp;
        cin>>temp.address>>temp.data>>temp.next;
         mp[temp.address]=temp;
    }
    BuildLink(l,head,mp);
    Reverse(l,ans,k);
    for(int i=0;i<ans.size();i++){
        if(i!=ans.size()-1){
            cout<<ans[i].address<<" "<<ans[i].data<<" "<<ans[i+1].address<<endl;
        }
        else{
            cout<<ans[i].address<<" "<<ans[i].data<<" "<<"-1"<<endl;
        }
    }
}