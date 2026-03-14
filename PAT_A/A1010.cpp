#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>

//注意溢出问题

using namespace std;

long long Trandecimal(string s1,const long long radix){
    long long decimal=0;
    for(int i=0;i<s1.size();i++){
        if(s1[i]>='0'&&s1[i]<='9') decimal=(s1[i]-'0')+decimal*radix;
        else{
            decimal=(s1[i]-'a'+10)+decimal*radix;
        }
    }
    return decimal;
}

int compare(const string& s, long long radix, long long target) {
    long long res = 0;
    for (char c : s) {
        int digit = (c >= '0' && c <= '9') ? c - '0' : c - 'a' + 10;
        if (res > (target - digit) / radix) return 1;
        res = res * radix + digit;
    }
    if (res == target) return 0;
    return res < target ? -1 : 1;
}

bool cmp(char s1,char s2){
    return s1 > s2;
}

long long MinRadix(string s){
    long long min = 0;
    sort(s.begin(), s.end(),cmp);
    if(s[0]>='0'&&s[0]<='9')
        return min = max(s[0] - '0'+1,2);
    else
        return min = max(s[0] - 'a' + 11,2);
}


int main(){
    long long tag,radix;
    string n1;
    string n2;
    cin>>n1>>n2>>tag>>radix;
    long long decimal_target=0;
    long long decimal_another=0;
    long long ans=-1;
    if(tag==1){
        decimal_target=Trandecimal(n1,radix);
        long long low=MinRadix(n2);
        long long high=max(low,decimal_target);
        while(low<=high){
            long long mid=low+(high-low)/2;
            int flag=compare(n2,mid,decimal_target);
            if(flag==0){
                ans=mid;
                high=mid-1;
            }
            else if(flag==1){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if(ans==-1) cout<<"Impossible\n";
        else cout<<ans<<endl;
    }
    else{
        decimal_target=Trandecimal(n2,radix);
        long long low=MinRadix(n1);
        long long high=max(low,decimal_target);
        while(low<=high){
            long long mid=low+(high-low)/2;
            int flag=compare(n1,mid,decimal_target);
            if(flag==0){
                ans=mid;
                high=mid-1;
            }
            else if(flag==1){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if(ans==-1) cout<<"Impossible\n";
        else cout<<ans<<endl;
    }
}