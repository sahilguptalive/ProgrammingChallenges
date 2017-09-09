#include<iostream>
#include<cstdio>
#include<cmath>
#include<climits>
typedef unsigned long long int _type;
//const _type  MAX =LLONG_MAX;
const _type  MAX =10;
int main(){

    for(int x=1;x<MAX;x++){
        for(int y=1;y<MAX;y++){
            for(int z=1;z<MAX;z++){
                for(int w=1;w<MAX;w++){
                    if(std::pow(x,5)
                            + std::pow(y,5)
                            + std::pow(z,5)
                            - std::pow(w,5)==0){
                        printf("====>>>>>>>>got the result %d, %d, %d, %d<<<<<<<<<======\n",x,y,z,w);
                    }else{
                        printf("checked: %d, %d, %d, %d\n",x,y,z,w);
                    }
                }
            }
        }
    }
    return 0;
}
