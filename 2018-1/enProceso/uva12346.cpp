#include <iostream>
#include <vector>

using namespace std;

int main(){
	int nwg, F, C, tc, V, T;
	vector<int> frs, costs; 

	cin>>nwg;
	for(int i=0; i<nwg; i++){
		cin>>F>>C;
		frs.push_back(F);
		costs.push_back(C);
	}

	cin>>tc;
	for(int i=0; i<tc; i++){
		cin>>V>>T;
		for(int j=0; j<1<<nwg; j++){
			
		}
	}
}