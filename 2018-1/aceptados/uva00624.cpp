#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N, ntr, track;
	vector<int> tracks;
	bool end=false;

	while(cin>>N){
		cin>>ntr;
		for(int i=0; i<ntr; i++){
			cin>>track;
			tracks.push_back(track);
		}

		int bestsum=0;
		int bestc=0;
		int bestntracks=0;

		for(int i=0; i<1<<ntr; i++){
			
			int inset=i;
			int sum=0;
			int tracksincd=0;

			for(int j=0; j<ntr; j++){
				if(inset&1){
					sum+=tracks[j];
					tracksincd++;
				}
				if(sum>N)
					break;
				inset>>=1;
			}
			if(sum>bestsum && sum<=N ){
				bestsum=sum;
				bestc=i;
				bestntracks=tracksincd;
			}
			else if(sum==bestsum && sum<=N && tracksincd>bestntracks){
				bestsum=sum;
				bestc=i;
				bestntracks=tracksincd;
			}
		}

		for(int i=0; i<ntr; i++){
			if(bestc&1){
				cout<<tracks[i]<<" ";
			}
			bestc>>=1;
		}
		cout<<"sum:"<<bestsum<<endl;
		tracks.clear();
	}
}