#include <iostream>

using namespace std;

int main(){
	long int num, sum;
	cin>>num;
	while (num!=0){
		while(num/10!=0){
			sum=0;
			while(num!=0){
				sum=sum+num%10;
				num=num/10;
			}
			num=sum;
		}
		cout<<num<<endl;
		cin>>num;
	}
}