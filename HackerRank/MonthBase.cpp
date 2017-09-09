#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#define MAX_DAYS 31
 bool doesMonthExist(int* monthArr,int month,int daySum);
int main(){
    int n;
    int eventArr[MAX_DAYS];
    int monthArr[MAX_DAYS];
    char buffer[64];
    for(int i=0;i<MAX_DAYS;i++){
        eventArr[i]=0;
    }
    for(int i=0;i<MAX_DAYS;i++){
        monthArr[i]=0;
    }
    std::cin>>n;
    for(int i=0;i<n;i++){
        int m;
        int d;
        std::cin>>m>>d;
        int d0=d%10;
        int d1=d/10;
        if(d0>=m||d1>=m||m==1){
            continue;
        }
        int daySum=d0+d1*m;
        if(daySum<=MAX_DAYS&&daySum>0&&((monthArr[daySum-1]&(1<<m))==0)){
            eventArr[daySum-1]+=1;
            monthArr[daySum-1]|=(1<<m);
        }else{
            int andR=monthArr[daySum-1]&(1<<m);
            bool result=(andR==0);
            std::cout<<"\n month arr val"<<monthArr[daySum-1]<<"shifted 1"<<(1<<m)<<" andR: "<<andR<<" result:"<<result;
        }
        std::cout<<"\ni="<<i;
    }
    long int sum=0;
    for(int i=0;i<MAX_DAYS;i++){
        std::cout<<"\nsum:i:sa"<<i<<"hil val: "+(eventArr[i]);
        itoa(eventArr[i],buffer,10);
        //std::cout<<"\nsum:i:sa"<<i<<"hil val: "+(to_string(eventArr[i]));
        std::cout<<"\nsum:i:sa"<<i<<"hil val: "<<buffer;
        if(eventArr[i]!=0){
            sum+=((long int)(eventArr[i]*eventArr[i]-1)/2);
        }
    }
    std::cout<<sum<<"\n";
    return 0;
}
