#include<cstdio>
#include<map>

using namespace std;

struct Count{
    int win;
    int neu;
    int lose;
    map<char,int> most;
    Count(){
        win=0;
        neu=0;
        lose=0;
        most['C']=0;
        most['B']=0;
        most['J']=0;
    }
};

int Jud(char a,char b){
    if(a=='C'){
        if(b=='C') return 0;
        if(b=='J') return 1;
        if(b=='B') return -1;
    }
    if(a=='J'){
        if(b=='C') return -1;
        if(b=='J') return 0;
        if(b=='B') return 1;
    }
    if(a=='B'){
        if(b=='C') return 1;
        if(b=='J') return -1;
        if(b=='B') return 0;
    }
}

void Prin(Count a){
    char max_c='B';
    int max=0;
    for(map<char,int>::iterator it=a.most.begin();it!=a.most.end();it++){
        if(it->second>max){
            max=it->second;
            max_c=it->first;
        }
    }
    printf("%c",max_c);
}

int main(){
    int n=0;
    scanf("%d\n",&n);
    Count a,b;
    for(int i=0;i<n;i++){
        char temp_a,temp_b;
        scanf("%c %c\n",&temp_a,&temp_b);
        if(Jud(temp_a,temp_b)==1){
            a.win++;
            b.lose++;
            a.most[temp_a]++;
        }
        if(Jud(temp_a,temp_b)==0){
            a.neu++;
            b.neu++;
        }
        if(Jud(temp_a,temp_b)==-1){
            a.lose++;
            b.win++;
            b.most[temp_b]++;
        }
    }
    printf("%d %d %d\n",a.win,a.neu,a.lose);
    printf("%d %d %d\n",b.win,b.neu,b.lose);
    Prin(a);
    printf(" ");
    Prin(b);
    printf("\n");
}