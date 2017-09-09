//https://www.hackerrank.com/challenges/harry-potter-and-the-floating-rocks
#include<iostream>
#include<cmath>
typedef int _cord; 
unsigned GCD(unsigned u, unsigned v);
int main(){

    int n;
    std::cin>>n;
    for(int i=0;i<n;i++){
        _cord x1;
        _cord y1;
        _cord x2;
        _cord y2;
        std::cin>>x1>>y1>>x2>>y2;
        _cord p=std::abs(y1-y2);
        _cord b=std::abs(x1-x2);
        /*if(p<b){
          std::cout<<p-1;
          }else{
          std::cout<<b-1;
          }*/
        std::cout<<GCD(p,b)-1<<"\n";
    }
    return 0;

}
unsigned GCD(unsigned u, unsigned v) {
    while ( v != 0) {
        unsigned r = u % v;
        u = v;
        v = r;
    }
    return u;
}
