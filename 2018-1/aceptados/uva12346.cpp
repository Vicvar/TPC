#include <iostream>
#include <vector>

using namespace std;

int main(){
	int nwg, F, C, tc, V, T, maxc=0;
	vector<int> frs, costs; 

	cin>>nwg;

	for(int i=0; i<nwg; i++){
		cin>>F>>C;
		frs.push_back(F);
		costs.push_back(C);
		maxc+=C;
	}

	cin>>tc;

	for(int i=0; i<tc; i++){

		cin>>V>>T;

		int bestc=maxc;
		int bsub=0;
		int fsum=0;

		for(int j=0; j<1<<nwg; j++){

			int inset=j;
			int csum=0;
			fsum=0;

			for(int k=0; k<nwg; k++){
				if(inset&1){
					fsum+=frs[k]*T;
					csum+=costs[k];
				}
				if(fsum>=V){
					if(csum<bestc){
						bestc=csum;
						bsub=j;
					}
					break;
				}
				inset=inset>>1;
			}
		}
		cout<<"Case "<<i+1<<": ";
		if(bestc==maxc && fsum<V)
			cout<<"IMPOSSIBLE"<<endl;
		else
			cout<<bestc<<endl;
	}
}