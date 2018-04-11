#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	int testn, len, barnum, bar;
	vector<int> bars;

	cin>>testn;
	for(int i=0; i<testn; i++){
		bool yes=false;
		cin>>len>>barnum;
		for(int j=0; j<barnum; j++){
			cin>>bar;
			bars.push_back(bar);
		}
		for(int j=0; j<pow(2,barnum); j++){
			int sum=0;
			unsigned int iis=j;
			for(int k=0; k<barnum; k++){
				if(iis&1) sum+=bars[k];
				iis=iis>>1;
			}
			if(sum==len){
				yes=true;
				break;
			}
		}
		bars.clear();
		if(yes) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}