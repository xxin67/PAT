#include<iostream>
#include<string>

using namespace std;

void BirIn(string &name,string& birth){
    string temp;
    cin>>name>>temp;
    for(int i=0;i<temp.size();i++){
        if(temp[i]=='/') continue;
        else{
            birth.push_back(temp[i]);
        }
    }
}

int main(){
    int n;
    cin>>n;
    string name[n];
    string birth[n];
    for(int i=0;i<n;i++){
        BirIn(name[i],birth[i]);
    }

    int count=0;
    int young_i=0,old_i=0;
    for(int i=0;i<n;i++){
        if(birth[i]>="18140906"&&birth[i]<="20140906"){
            count++;
            if(count==1){
                young_i=i;
                old_i=i;
            }
            if(birth[i]>birth[young_i]) young_i=i;
            if(birth[i]<birth[old_i]) old_i=i;
        }
    }
    if(count==0) cout<<count<<endl;
    else cout<<count<<" "<<name[old_i]<<" "<<name[young_i]<<endl;
}