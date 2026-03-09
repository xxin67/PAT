#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>

using namespace std;

bool cmp1(int a,int b){
    return a>b;
}

void change(string s,int *a){
    for(int i=0;i<4;i++){
        if(i>s.size()-1){
            a[i]=0;
        }
        else a[i]=s[i]-'0';
    }
}

void Min(int l[],int r[],int* out){
    for(int i=0;i<4;i++){
        if(l[4-1-i]<r[4-1-i]){
            l[4-1-i-1]--;
            l[4-1-i]+=10;
            out[4-1-i]=l[4-1-i]-r[4-1-i];
        }
        else out[4-1-i]=l[4-1-i]-r[4-1-i];
    }
}

void Pr(int l[],int r[],int out[]){
    for(int i=0;i<4;i++){
        cout<<l[i];
    }
    cout<<" - ";
    for(int i=0;i<4;i++){
        cout<<r[i];
    }
    cout<<" = ";
    for(int i=0;i<4;i++){
        cout<<out[i];
    }
    cout<<endl;
}

int main(){
    string n;
    int num[4];
    cin>>n;
    change(n,num);
    while(1){
        int flag=0;
        sort(num,num+4,cmp1);
        int l[4];
        int temp[4];
        memcpy(l, num, sizeof(num));
        memcpy(temp, num, sizeof(num));
        sort(num,num+4);
        int r[4];
        memcpy(r, num, sizeof(num));
        Min(temp,r,num);
        Pr(l,r,num);
        for(int i=0;i<4;i++){
            flag=flag*10+num[i];
        }
        if(flag==6174||flag==0) break;
    }
}