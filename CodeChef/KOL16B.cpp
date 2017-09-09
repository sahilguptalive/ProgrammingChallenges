#include <iostream>

void decode(int testCase[],int testSize,int testNumber);
void printArray(int array[],int arraySize);
void checkIfBigEndian();
const int OneSiftedSixteenTimesMinusOne=65535;
bool isBigEndian=false;
const int SIZE_INT= sizeof(int);
char* ptrChar;
int main (){
	int numberOfTestCases;
	checkIfBigEndian();
	std::cin>>numberOfTestCases;
    	for(int i=0;i<numberOfTestCases;i++){
		int testSize;
		std::cin>>testSize;
		int testCase[testSize];
		for(int j=0;j<testSize;j++){
			std::cin>>testCase[j];
		}
		decode(testCase,testSize,i+1);	
	}
    return 0;
}

void checkIfBigEndian(){
	int testInt=0x1234;
	ptrChar=(char*)&testInt;
	isBigEndian = ((int)*ptrChar)==0x12;
}
/* inline void decode(int testCase[],int testSize, int testNumber){
	int A[testSize];
	int B[testSize];
	std::cout<<"\nCase "<<testNumber<<":\n";
	for(int i=0;i<testSize;i++){
		A[i]=testCase[i]&(OneSiftedSixteenTimesMinusOne);
		B[i]=testCase[i]>>16;	
	}
	printArray(A,testSize);
	printArray(B,testSize);
}*/

inline void decode(int testCase[],int testSize, int testNumber){
	int A[testSize];
	int B[testSize];
	std::cout<<"\nCase "<<testNumber<<":\n";
	for(int i=0;i<testSize;i++){
		//A[i]=testCase[i]&(OneSiftedSixteenTimesMinusOne);
		//B[i]=testCase[i]>>16;	
		ptrChar=(char*)(testCase+i);
		if(isBigEndian){
			A[i]=((int)*(ptrChar+(sizeof(int)/8)-1));
			B[i]=((int)*(ptrChar+(sizeof(int)/8)-2));
		}else{
			A[i]=((int)*(ptrChar));
			B[i]=((int)*(ptrChar+1));
		}	
	}
	printArray(A,testSize);
	printArray(B,testSize);
}

inline void printArray(int array[],int arraySize){
	std::cout<<"\n";
	for(int i=0;i<arraySize;i++){
		std::cout<<array[i]<<" ";
	}
}