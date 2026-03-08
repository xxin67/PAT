#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

struct Num{
    string s;
    char d;
};

int main(){
    Num temp;
    int sum=0;
    vector<Num> num;
    while(cin.peek()!='\n'){
        cin>>temp.s>>temp.d;
        num.push_back(temp);
    }
    for(int i=0;i<num.size();i++){
        int temp_sum=0,count=0;
        while(num[i].s.find(num[i].d)!=string::npos){
            temp_sum = temp_sum * 10 + ((int)num[i].d-'0');
            num[i].s.erase(num[i].s.find(num[i].d),1);
        }
        sum+=temp_sum;
    }
    cout<<sum<<endl;
}