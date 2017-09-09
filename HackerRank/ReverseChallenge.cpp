//https://www.hackerrank.com/challenges/reverse-game
#include<iostream>
#include<fstream>
#include<string>

std::ofstream f;
void output(int a){
        f<<a;
}
void output(std::string a){
        f<<a;
}
int main(){

    int test;
    f.open("reverse_game.txt");
    std::cin>>test;
    for(int i=0;i<test;i++){
        int n;
        int k;
        std::cin>>n;
        std::cin>>k;
        if(k<(n/2)){
            output((2*k+1));
        }else{
            output((n-1-k)*2);
        }
        output("\n");
    }
    return 1;
}
