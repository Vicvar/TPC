#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

bool isPrime(int n){
	bool ans=true;
	for(int i=2; i*i<=n; i++){
		if(n%i==0)
			ans=false;
	}
	return ans;
}

void getRings(vector<int> h, vector<int> t, int n, vector<vector<int> > &sol){
	if(h.size()==n && isPrime(h[0]+h[h.size()-1]))
		sol.push_back(h);
	for(int i=0; i<t.size(); i++){
		if(isPrime(h[h.size()-1]+t[i])){
			vector<int> auxh = h;
			vector<int> auxt = t;
			auxh.push_back(t[i]);
			auxt.erase(auxt.begin()+i);
			getRings(auxh, auxt, n, sol);
		}
	}
}

int main(){
	int n, c=0;
	vector<int> pring;
	vector<int> one(1,1);
	vector<vector<int> > sol;
	cin>>n;
	while(!cin.eof()){
		c++;
		if(c>1)
			cout<<endl;
		sol.clear();
		pring=vector<int>(n-1);
		
		for(int i=0; i<n-1; i++)
			pring [i]=i+2;

		getRings(one, pring, n, sol);
		cout<<"Case "<<c<<":"<<endl;
		for(int i=0; i<sol.size(); i++){
			for(int j=0; j<sol[i].size()-1; j++){
				cout<<sol[i][j]<<" ";
			}
			cout<<sol[i][sol[i].size()-1];
			cout<<endl;
		}
		cin>>n;
	}
}