#include<cstdio>

using namespace std;

struct MoonCake{
    double store;
    double total_price;
    double price;
};

int main(){
    int n;
    double d;
    double profit=0;
    int empty=0;
    scanf("%d %lf",&n,&d);
    MoonCake mc[n];
    for(int i=0;i<n;i++){
        scanf("%lf",&mc[i].store);
    }
    for(int i=0;i<n;i++){
        scanf("%lf",&mc[i].total_price);
        mc[i].price=mc[i].total_price/mc[i].store;
    }
    while(d!=0&&empty==0){
        double max_price=0; 
        int max;
        for(int i=0;i<n;i++){
            if(mc[i].price>max_price){
                max_price=mc[i].price;
                max=i;
            }
        }
        if(d>=mc[max].store){
            d=d-mc[max].store;
            profit+=mc[max].total_price;
            mc[max].store=0;
            mc[max].price=0;
            mc[max].total_price=0;
        }
        else{
            profit+=d*mc[max].price;
            d=0;
        }
        if(max_price==0) empty=1;
    }
    printf("%.2f\n",profit);
}