#include<cstdio>
#include<string>
#include<regex>
#include<iostream>

using namespace std;

int main(){
    int n;
    int i;
    string str;
    regex pattern("A*P{1}A{1,2}T{1}A*");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int p_prior=0,t_later=0,mid=0;
        int P=0,T=0;
        int breakflag=0;
        cin>>str;
        for(int j=0;j<str.length();j++){
            if(str[j]=='P'){
                if(P==0){
                    P++;
                    continue;
                }
                else{ 
                    if(i==n-1) cout<<"NO";
                    else cout<<"NO"<<endl;
                    breakflag=1;
                    break;
                }
            }
            if(P==0){
                if(str[j]!='A'){
                    if(i==n-1) cout<<"NO";
                    else cout<<"NO"<<endl;
                    breakflag=1;
                    break;
                }
                else p_prior++;
            }
            if(P==1){
                if(str[j]=='T'||str[j]=='A'){
                    if(str[j]=='T'){
                        if(T==0){
                            T++;
                            continue;
                        }
                        else{ 
                            if(i==n-1) cout<<"NO";
                            else cout<<"NO"<<endl;
                            breakflag=1;
                            break;
                        }
                    }
                    else{
                        if(T==0) mid++;
                        else t_later++;
                    }
                }
                else{
                    if(i==n-1) cout<<"NO";
                    else cout<<"NO"<<endl;
                    breakflag=1;
                    break;
                }
            }
        }
        if(breakflag==1) continue;
        if(P==1&&T==1&&mid>=1&&t_later==p_prior*mid){
            if(i==n-1) cout<<"YES";
            else cout<<"YES"<<endl;
        }
        else{
            if(i==n-1) cout<<"NO";
            else cout<<"NO"<<endl;
        }
    }
}