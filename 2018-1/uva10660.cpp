#include <iostream>
#include <vector>
#include <cstdlib>


using namespace std;

int getDist(int a, int b, int x, int y){
	return abs(a-x)+abs(b-y);
}

int main(){

	int t;
	cin>>t;

	for(int i=0; i<t; i++){
		vector<int> city(25);
		int nnp;

		cin>>nnp;
		for(int j=0; j<nnp; j++){
			int x,y,q;
			cin>>x>>y>>q;
			city[5*x+y]=q;
		}

		//obtener la mejor pos para cada oficina
		for(int j=0; j<5; j++){
			int bl=80*25;
			int mejor=0;
			for(int k=0; k<25;k++){
				int dist=0;
				for(int l=0; l<25; l++){
					dist+=getDist()/*...*/;
				}

			}
		}
	}
}