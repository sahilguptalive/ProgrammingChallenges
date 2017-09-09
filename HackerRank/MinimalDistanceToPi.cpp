#include <iostream>
#include <cmath>
const double PI=3.1415926535897932384626433832795028841971693993751;
void printClosestFractionToPI(unsigned long min,unsigned long max);
unsigned long closestLong(double val);
void printFrac(unsigned long num,unsigned long den);
bool doesOptimizationLevel1Worked(unsigned long min,unsigned long max);
bool doesOptimizationLevel1Worked(unsigned long min,unsigned long max,unsigned long piNum,unsigned long piDen);

int main(){
		unsigned long min;
		unsigned long max;
		std::cin>>min>>max;
		printClosestFractionToPI(min,max);
		return 0;
}
void printClosestFractionToPI(unsigned long min,unsigned long max){
		//level 1 of optimization
		/*if(doesOptimizationLevel1Worked(min,max)){
			return;
		}*/
		//actual algo
		double minFrac=99999999;//TODO: replace with integer max range
		unsigned long num=0;
		unsigned long den=0;
		double prevValV1=((double)(min-1))*PI;
		for(unsigned long d=min;d<=max;d++){
				//if(d%7==6||d%7==1){
						double integerPart;
						double fractionalPart;
						prevValV1+=PI;
						double v1=prevValV1;
						fractionalPart=std::modf(v1,&integerPart);
						//std::cout<<"\n"<<fractionalPart;
						unsigned long v2=((unsigned long)integerPart+(fractionalPart<0.5?0:1));
						fractionalPart=fractionalPart<0.5?fractionalPart:(1-fractionalPart);
						//unsigned long v2=closestLong(v1);
						//double v3=((double)v2/(double)d);
						//double v4=std::abs(v3-PI);
						if(fractionalPart<minFrac){
								num=v2;
								den=d;
								minFrac=fractionalPart;
				//		}
				}
		}
		printFrac(num,den);
}

bool doesOptimizationLevel1Worked(unsigned long min,unsigned long max){
				return doesOptimizationLevel1Worked(min,max,1146408,364913)||
				doesOptimizationLevel1Worked(min,max,833719,265381)||
				doesOptimizationLevel1Worked(min,max,312689,99532)||
				doesOptimizationLevel1Worked(min,max,208341,66317)||
				doesOptimizationLevel1Worked(min,max,104348,33215)||
				doesOptimizationLevel1Worked(min,max,103993,33102)||
				doesOptimizationLevel1Worked(min,max,52163,16604)||
				doesOptimizationLevel1Worked(min,max,355,113)||
				doesOptimizationLevel1Worked(min,max,333,106)||
				doesOptimizationLevel1Worked(min,max,22,7);
}
bool doesOptimizationLevel1Worked(unsigned long min,unsigned long max,unsigned long piNum,unsigned long piDen){
		unsigned long intendedDen=(std::ceil((double)min/(double)piDen))*piDen;
		if(intendedDen<=max){
				printFrac(piNum*(intendedDen/piDen),intendedDen);
				return true;
		}
		return false;
}
void printFrac(unsigned long num,unsigned long den){
		std::cout<<num<<"/"<<den;
}

unsigned long closestLong(double val){
		unsigned long floor=std::floor(val);
		unsigned long ceiling=std::ceil(val);
		return val-floor<ceiling-val?floor:ceiling;
}
