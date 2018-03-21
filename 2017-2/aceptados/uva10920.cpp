#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

long long int getTopLeftD(long long int n){
	long long int c=(sqrt(n)+1)/2;
	while(n>(2*c-1)*(2*c-1)){
		c++;
	}
	return c;
}

pair<int,int> countCC(int tld, int P){
	int X=tld-1, Y=tld-1;
	int tlr=(tld*2-1);
	int tl=(tlr*tlr);
	if(tl==P) return make_pair(X,Y);
	for(int i=0; i<tlr-1; i++){
		Y--;
		tl--;
		if(tl==P) return make_pair(X,Y);
	}
	for(int i=0; i<tlr-1; i++){
		X--;
		tl--;
		if(tl==P) return make_pair(X,Y);
	}
	for(int i=0; i<tlr-1; i++){
		Y++;
		tl--;
		if(tl==P) return make_pair(X,Y);
	}
	for(int i=0; i<tlr-1; i++){
		X++;
		tl--;
		if(tl==P) return make_pair(X,Y);
	}
}

int main(){
	pair<int,int> cdiff;
	long long int SZ, P, X, Y, tld;

	cin>>SZ>>P;
	while(SZ!=0 && P!=0){
		tld=getTopLeftD(P);
		cdiff=countCC(tld,P);
		X=SZ/2+1+cdiff.first;
		Y=SZ/2+1+cdiff.second;
		cout<<"Line = "<<Y<<", column = "<<X<<"."<<endl;
		cin>>SZ>>P;
	}
}