#include<cstdio>
#include<string>
#include<map>
#include<iostream>
#include<algorithm>

using namespace std;

map<char,string> day={
    {'A',"MON"},{'B',"TUE"},{'C',"WED"},{'D',"THU"},{'E',"FRI"},
    {'F',"SAT"},{'G',"SUN"}
};

int main(){
    string str[4];
    int day_flag=0;
    int same_flag=0;
    int day_i,hour_i,minute_i;
    for(int i=0;i<4;i++){
        cin>>str[i];
    }
    for(int i=0;i<min(str[0].size(),str[1].size());i++){
        if(str[0][i]==str[1][i]){
            if(str[0][i]>='A'&&day_flag==0&&str[0][i]<='G'){
                day_i=i;
                day_flag=1;
                continue;
            }
            if(day_flag==1){
                if((str[0][i]>='A'&&str[0][i]<='N')||(str[0][i]>='0'&&str[0][i]<='9')){
                    hour_i=i;
                    break;
                }
            }
        }
    }
    for(int i=0;i<min(str[2].size(),str[3].size());i++){
        if(str[2][i]==str[3][i]&&((str[2][i]>='A'&&str[2][i]<='Z')||(str[2][i]>='a'&&str[3][i]<='z'))){
            minute_i=i;
            break;
        }
    }
    int hour;
    if(str[0][hour_i]>='0'&&str[0][hour_i]<='9'){
        hour=(int)(str[0][hour_i]-'0');
    }
    if(str[0][hour_i]>='A'&&str[0][hour_i]<='N'){
        hour=(int)(str[0][hour_i]-'A')+10;
    }
    if(minute_i<10){
        if(hour<10) cout<<day[str[0][day_i]]<<" "<<0<<hour<<":"<<0<<minute_i;
        else cout<<day[str[0][day_i]]<<" "<<hour<<":"<<0<<minute_i;
    }
    if(minute_i>=10){
        if(hour<10) cout<<day[str[0][day_i]]<<" "<<0<<hour<<":"<<minute_i;
        else cout<<day[str[0][day_i]]<<" "<<hour<<":"<<minute_i;
    }
    return 0;
}