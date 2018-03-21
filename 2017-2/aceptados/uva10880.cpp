#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> getQ(int eatenC, int r){
	vector<int> cpg1, cpg2;
	for(int i=1; i<=sqrt(eatenC); i++){
		if(eatenC%i==0) cpg1.push_back(i);
	}
	for(int i=0; i<cpg1.size();i++){
		if(cpg1[i]>r) cpg2.push_back(cpg1[i]);
	}
	for(int i=cpg1.size()-1; i>=0;i--){
		int p=eatenC/cpg1[i];
		if(p>r && p!=cpg1[i])cpg2.push_back(p);
	}
	return cpg2;
}

int main(){
	vector<int> cpg;
	int nc, R, C, eatenC;
	cin>>nc;
	for(int i=0; i<nc ; i++){
		cin>>C>>R;
		if(R!=C){
			eatenC = C-R;
			cpg = getQ(eatenC, R);
			//if(eatenC>R) cpg.push_back(eatenC);
			cout<<"Case #"<<i+1<<":";
			for(int j=0; j<cpg.size(); j++){
				cout<<" "<<cpg[j];
			}
			cout<<endl;
		}
		else{
			cout<<"Case #"<<i+1<<": 0"<<endl;
		}
		cpg.clear();
	}
}