#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<cmath>
typedef double _cord;
int main(){
    int n;
    std::cin>>n;
    _cord top=0;
    _cord left=0;
    _cord right=0;
    _cord bottom=0;
    bool isTop=true;
    bool isLeft=true;
    bool isRight=true;
    bool isBottom=true;
    for(int i=0;i<n;i++){
        _cord x;
        _cord y;
        std::cin>>x>>y;
        //if point lies on x axis
        //check if x is +ve or -ve
        //if +ve check if more than right, if yes then assign new value 
        //if -ve check if less than left, if yes then assign new value
        if(y==0){
            if(x>=right){
                int temp=right;
                right=x;
                x=temp;
            }
                left=x<left?x:left;
            }
        }
        //if point lies on y axis
        //check if y is +ve or -ve
        //if +ve check if more than top, if yes then assign new value 
        //if -ve check if less than bottom, if yes then assign new value
        else{
            if(y>0){
                top=y>top?y:top;
                isTop=true;
            }else{
                bottom=y<bottom?y:bottom;
                isBottom=true;
            }
        }

    }
    _cord max=0;
    _cord dis=0;
    if(isRight&&isLeft){
        dis=right-left;
        if(dis>max){
            max=dis;
        }
    }
    if(isBottom&&isTop){
        dis=bottom-top;
        if(dis>max){
            max=dis;
        }
    }
    if(isLeft&&isTop){
        dis=std::sqrt(left*left+top*top);
        if(dis>max){
            max=dis;
        }
    }
    if(isTop&&isRight){
        dis=std::sqrt(top*top+right*right);
        if(dis>max){
            max=dis;
        }
    }
    if(isLeft&&isBottom){
        dis=std::sqrt(left*left+bottom*bottom);
        if(dis>max){
            max=dis;
        }
    }
    if(isRight&&isBottom){
        dis=std::sqrt(right*right+bottom*bottom);
        if(dis>max){
            max=dis;
        }
    }
    printf("%.6f\n",max);
    return 0;
}
