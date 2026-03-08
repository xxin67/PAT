#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>

using namespace std;

struct bign{
    int d[1000];
    int len;
    bign(){
        memset(d,0,sizeof(d));
        len=0;
    }
};

bign change_s(string s){
    bign a;
    a.len=s.size();
    for(int i=0;i<a.len;i++){
        a.d[i]=s[s.size()-1-i]-'0';
    }
    return a;
}

bign Div(bign a,int b,int &r){
    bign c;
    c.len=a.len;
    for(int i=a.len-1;i>=0;i--){
        r=r*10+a.d[i];
        if(r/b==0) c.d[i]=0;
        else{
            c.d[i]=r/b;
            r=r%b;
        }
    }
    while(c.len>1&&c.d[c.len-1]==0){
        c.len--;
    }
    return c;
}

int main(){
    string s;
    int b=0,r=0;
    bign a,ans;
    cin>>s>>b;
    a=change_s(s);
    ans=Div(a,b,r);
    for(int i=ans.len-1;i>=0;i--){
        cout<<ans.d[i];
    }
    cout<<" "<<r<<endl;
    return 0;
}