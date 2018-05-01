#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <algorithm>


using namespace std;

int getDist(int a, int b){
	int x=a/5;
	int y=a%5;
	int n=b/5;
	int m=b%5;
	return abs(x-n)+abs(y-m);
}

int main(){
	int tc, nnp, r, c, p;

	cin>>tc;

	for(int i=0; i<tc; i++){
		vector<int> city(25);
		vector<int> dists(25);
		vector<int> ofs(25);
		vector<int> ans;
		int best=3000000;

		cin>>nnp;

		for(int j=0; j<nnp; j++){
			cin>>r>>c>>p;
			city[5*r+c]=p;
		}

		for(int j=0; j<25; j++){
			dists[j]=80000;
		}

		for(int j=0; j<5; j++){
			ofs[j]=1;
		}

		int d, bestd=80000*25;
		vector<int> bnewdist;
		vector<int> bofs;
		
		do{
			int tot=0;
			vector<int> newdist=dists;
			for(int j=0; j<25; j++){
				if(ofs[j]==1){ 
					for(int k=0; k<25; k++){
						d=getDist(j,k)*city[k];
						if(d<newdist[k]){
							newdist[k]=d;
						}
					}
				}
			}
			for(int k=0; k<25; k++){ 
				tot+=newdist[k];
			}
			if(tot<bestd){
				bestd=tot;
				bnewdist=newdist;
				bofs=ofs;
			}

		}while(prev_permutation(ofs.begin(), ofs.end()));

		int n=0;
		for(int j=0; j<25; j++){
			if(bofs[j]==1 && n<4){
				cout<<j<<" ";
				n++;
			}
			else if(bofs[j]==1){
				cout<<j<<endl;
			}
		}
	}
}