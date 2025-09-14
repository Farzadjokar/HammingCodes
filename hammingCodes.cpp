#include<iostream>
#include<vector>
#include<cmath>
#include<vector>
#include<algorithm>
bool isPowerOfTwo(int number){
double mod=log2(number);
      if(mod-int(mod)==0){
         return true;
      }else{
      return false;
      }
}
void doParrityCheck(int array[],int size){
   int counter=1;
   while (counter<size){
      if(isPowerOfTwo(counter)){
         int newNumber=counter;
         while (newNumber<size){
            if((newNumber&counter)==counter){
               array[counter]=array[counter]^array[newNumber];
            }
            newNumber++;
         }
      }
      counter++;
   }
}
void computeSyndorme(std::vector<int>& v1,int array[],int arraySize){
int counter=0;
while (counter<v1.size()){
   int number=pow(2,counter);
   int newNumber=number;
   while (newNumber<arraySize){
            if((newNumber&number)==number){
               v1[counter]=v1[counter]^array[newNumber];
            }
            newNumber++;
         }
         counter++;
}
}
int main(int length,char* args[]){
   int numberOfBits=0;
   std::cout<<"enter number of bits for sending";
   std::cin>>numberOfBits;
   int totalNumberOfFrames=(ceil(log10(numberOfBits)/log10(2)))+1+numberOfBits;
   int array[totalNumberOfFrames+1]={};
   int counter=1;
   int messageCounter=1;
   while (counter<totalNumberOfFrames+1){
      double mod=log2(counter);
      if(mod-int(mod)==0){
         array[counter]=0;
      }else{
      std::cout<<"please enter the "<<messageCounter<<"th message:";
      std::cin>>array[counter];
      messageCounter++;
      }
      counter++;
   }
   doParrityCheck(array,totalNumberOfFrames+1);
   for(int x=1;x<totalNumberOfFrames+1;x++){
      std::cout<<array[x]<<" ";
   }
   //do the error
   array[5]=!array[5];
   //now compute the syndrome;
int size = int(std::ceil(std::log2(totalNumberOfFrames)));
std::vector<int> syndrome(size, 0);
//compute the syndrome
std::cout<<"\n\n syndrome is = ";
computeSyndorme(syndrome,array,totalNumberOfFrames+1);
std::reverse(std::begin(syndrome),std::end(syndrome));
std::for_each(std::begin(syndrome),std::end(syndrome),[](int x)->void{
std::cout<<x<<"  ";
});
    return 0;
}