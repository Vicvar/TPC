#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

/*vector<int> primes;
int topN=2;

bool isPrime(int num){
	for(int i=topN; i<=num;i++){
		for(int j=2;j*j<=i;j++){
			if(i%j==0)
				goto nope;
		}
		primes.push_back(i);
		nope:;
	}
	if(num>topN)
		topN=num;
	return find(primes.begin(),primes.end(),num)!=primes.end();
}*/

bool isGud(vector<int> & v, vector<int> & pr){
	int num;
	for(int i=1; i<v.size(); i++){
		num=v[i]+v[i-1];
		if(find(pr.begin(),pr.end(), num)==pr.end())
			return false;
	}
	num=v[0]+v[v.size()-1];
	if(find(pr.begin(),pr.end(), num)==pr.end())
		return false;
	return true;
}

void addSol(vector<int> & v, set<vector<int> > & s){
	int puno;
	vector<int> aux;
	for(int i=0; i<v.size(); i++){
		if(v[i]==1){
			puno=i;
			break;
		}
	}
	for(int i=puno; i<v.size()+puno-1; i++){
		aux.push_back(v[i%v.size()]);
	}
	aux.push_back(v[(v.size()+puno-1)%v.size()]);
	s.insert(aux);
}

int main(){
	vector<int> ring;
	vector<int> primes;
	set<vector<int> > sol;
	int n, cc=1;
	cin>>n;

	while(!cin.eof()){
		if(cc>1)
			cout<<endl;
		
		for(int i=2; i<2*n; i++){
			for(int j=2; j*j<=i; j++){
				if(i%j==0)
					goto nope;
			}
			primes.push_back(i);
			nope:;
		}

		cout<<"Case "<<cc<<":"<<endl;
		for(int i=0; i<n; i++){
			ring.push_back(i+1);
		}

		do{
			if(isGud(ring, primes)){
				addSol(ring,sol);

			}
		}while(next_permutation(ring.begin(), ring.end()));

		for(set<vector<int> >::iterator it=sol.begin(); it!=sol.end(); it++){
			vector<int> disp=*it;
			for(int i=0; i<disp.size()-1; i++){
				cout<<disp[i]<<" ";
			}
			cout<<disp[disp.size()-1]<<endl;
		}

		ring.clear();
		sol.clear();
		primes.clear();
		cin>>n;
		cc++;
	}
}