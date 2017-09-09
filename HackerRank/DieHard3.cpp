//https://www.hackerrank.com/challenges/die-hard-3
#include <iostream>
bool isPossible(int a,int b,int c);
int main(){

    int testCases;
    std::cin>>testCases;
    int a,b,c;
    for(int i=0;i<testCases;i++){
        std::cin>>a>>b>>c;
        std::cout<<(isPossible(a,b,c)?"YES":"NO")<<"\n";
    }
    return 0;
}
bool isPossible(int a,int b,int c){
    if(a<b){
        a=b+a;
        b=a-b;
        a=a-b;
    }
    if((a<c)||(a==b&&b!=c)||(a%b==0&&c%b!=0)){
        return false;
    }
    else if((a==c||b==c)||(a%b==0&&c%b==0)){
        return true;
    }else{
        int rem=0;
        int remToCheck=0;
        int loopCounter=0;
        do{
            if(c<b){
                if(rem==c){
                    return true;
                }
            }
            else if(c<a){
                if((c-rem)%b==0 ){
                    return true;	
                }
            }
            rem=b-((a-rem)%b);
            if(loopCounter==0){
                remToCheck=rem;
            }
            loopCounter++;
            //std::cout<<"\nrem:"<<rem<<"\n";
        }while(loopCounter==1||rem!=remToCheck);
        return false;
    }
}
