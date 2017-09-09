#include<iostream>
#include<fstream>
void printNcrFor(int n);
std::ofstream file;
int main(){

    int test;
    file.open("out.txt");
    std::cin>>test;
    for(int i=0;i<test;i++){
        int n;
        std::cin>>n;
        printNcrFor(n);
    }
    return 0;
}
void printNcrFor(int n){
    unsigned long int prev=1;
    file<<1<<" ";
    for(int r=1;r<=n;r++){
        prev=(((prev*(n-r+1))/(r)));
        file<<(prev%1000000000)<<" ";
    }
    file<<"\n";
}
