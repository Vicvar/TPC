#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int nc, a, b,c;
	cin>>nc;
	for(int i=0; i<nc; i++){
		cin>>a>>b>>c;

		while(?)?;
		/*for(int j=1; j<10001; j++){
			if(j>a-2 || j>b || j*j>c) break;
			for(int k=1; k<10001; k++){
				if(j+k>a || j*k>b || j*j+k*k>c) break;
				for(int l=1; l<10001; l++){
					if((j+k+l)==a){
						if((j*k*l)==b){
							if(pow(j,2)+pow(k,2)+pow(l,2)==c){
								cout<<j<<" "<<k<<" "<<l<<endl;
								goto oc;
							}
						}
					}
				}
			}
		}*/
		cout<<"No solution."<<endl;
		oc:;
	}
}