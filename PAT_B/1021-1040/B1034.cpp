#include<iostream>
#include<string>
#include<cmath>

using namespace std;

struct Fracture{
    int a,b;
    char sig;
    Fracture(){
        a = 0;
        b = 0;
    }
};

void Trans_int(const string s,Fracture& n){
    if(s[0]=='+'||s[0]=='-') n.sig=s[0];
    for(int i=0;i<s.find('/');i++){
        if(s[i]>='0'&&s[i]<='9') n.a=n.a*10+(s[i]-'0');
    }
    for(int i=s.find('/');i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9') n.b=n.b*10+(s[i]-'0');
    }
}

int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

Fracture reduction(Fracture n){
    if(n.sig=='-') n.a=-n.a;
    if(n.a==0) n.b=1;
    else{
        int d=gcd(abs(n.a),abs(n.b));
        n.a/=d;
        n.b/=d;
    }
    return n;
}

Fracture add(Fracture n1,Fracture n2){
    Fracture result;
    result.a=n1.a*n2.b+n2.a*n1.b;
    result.b=n1.b*n2.b;
    return reduction(result);
}

Fracture minus(Fracture n1,Fracture n2){
    Fracture result;
    result.a=n1.a*n2.b-n2.a*n1.b;
    result.b=n1.b*n2.b;
    return reduction(result);
}

Fracture multi(Fracture n1,Fracture n2){
    Fracture result;
    result.a=n1.a*n2.a;
    result.b=n1.b*n2.b;
    return reduction(result);
}

Fracture divid(Fracture n1,Fracture n2){
    Fracture result;
    result.a=n1.a*n2.b;
    result.b=n1.b*n2.a;
    return reduction(result);
}

void Showformat(Fracture n){
    n=reduction(n);
    if(n.b==1) cout<<n.a;
    else if(abs(n.a)>abs(n.b)){
        cout<<n.a/n.b<<" "<<n.a<<"/"<<n.b;
    }
        else{
        cout<<n.a<<"/"<<n.b;
        }
}

int main(){
    string num1,num2;
    cin>>num1>>num2;
    Fracture n1,n2;
    Trans_int(num1,n1);
    Trans_int(num2,n2);
    
    Showformat(n1);
    cout<<" + ";
    Showformat(n2);
    cout<<" = ";
    Showformat(add(n1,n2));
    cout<<endl;
}