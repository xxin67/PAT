#include<iostream>
#include<cmath>
#include<stack>
#include<string>

using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int sum=a+b;
    string ssum=to_string(sum);
    stack<string> temp;
    while(1){
        if(sum/1000!=0){
            temp.push(ssum.substr(ssum.size()-3,3));
            ssum.erase(ssum.size()-3);
            sum/=1000;
        }
        else{
            temp.push(ssum);
            break;
        }
    }
    int ssize=temp.size();
    for(int i=0;i<ssize;i++){
        cout<<temp.top();
        if(i!=ssize-1) printf(",");
        temp.pop();
    }
    cout<<endl;
}