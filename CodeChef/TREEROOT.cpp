#include <iostream>

int max(int left,int right);
void printRange(int start,int end);
int main(){
	int testCases;
	std::cin>>testCases;
	for(int i=0;i<testCases;i++){
		int nodes;
		std::cin>>nodes;
		int start=1;
		int j=0;
		do{
			int nodeId;
			int childSum;
			std::cin>>nodeId>>childSum;
			start=max(nodeId==childSum?childSum:childSum+1,start);
			j++;
		}while(j<nodes&&start<nodes);
		printRange(start,nodes);
	}
return 1;
}
int max(int left, int right){
	return left>right?left:right;
}
void printRange(int start,int end){
	std::cout<<" s="<<start<<"e="<<end<<"\n";
	for(int i=start;i<=end;i++){
		std::cout<<i<<" ";	
	}
}