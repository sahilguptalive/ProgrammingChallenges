//https://www.hackerrank.com/challenges/summing-the-n-series
#include <iostream>
int main(){
		int testCases;
		std::cin>>testCases;
		for(int i=0;i<testCases;i++){
				long int n;
				std::cin>>n;
				std::cout<<(i>0?"\n":"")<<(long int)(n*n);
		}
		return 0;
}
