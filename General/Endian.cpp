#include <iostream>

int main(){

	int testInt=0x12345678;
	char* ptrChar;
	ptrChar=(char*)&testInt;
	if(((int)*ptrChar)==0x12){
		std::cout<<"big endian";
		std::cout<<"\nfirst byte "<<((int)*(ptrChar+(sizeof(int)/8)-1));
		std::cout<<"\nsecond byte "<<((int)*(ptrChar+(sizeof(int)/8)-2));
	}else{
		std::cout<<"little endian";
		std::cout<<"\nfirst byte "<<((int)*(ptrChar));
		std::cout<<"\nsecond byte "<<((int)*(ptrChar+1));
		std::cout<<"\nfirst two bytes "<<((int)*ptrChar)+(((int)*(ptrChar+1))*512);
	}
	std::cout<<"\n"<<((int)*ptrChar);
	
	return 0;
}


