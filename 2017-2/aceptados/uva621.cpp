#include <iostream>
#include <string>

using namespace std;

int main(){
	int N;
	string cod;
	cin>>N;
	for (int i = 0; i < N; ++i){
	 	cin>>cod;
	 	if(cod=="1"||cod=="4"||cod=="78") cout<<"+"<<endl;
	 	else if(cod[0]=='9'&& cod[cod.length()-1]=='4') cout<<"*"<<endl;
	 	else if(cod.length()>1 && cod.substr(cod.length()-2,2)=="35") cout<<"-"<<endl;
	 	else cout<<"?"<<endl;
	}
}