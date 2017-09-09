#include <iostream>
int main(){
	int y;
	std::cin>>y;
	std::cout<<((y<1918)?(y%4==0?12:13):(y>1918?(y%400==0||(y%4==0&&y%100!=0)?12:13):26))<<'.'<<"09"<<'.'<<y;
	return 0;
}
