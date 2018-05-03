#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> primes;

bool isPrime(int num){
	if(primes.size()<sqrt(num)){
		
	}
	return find(primes.begin(),primes.end(),num)!=primes.end();
}

bool isGud(vector<int> & v){
	int num;
	for(int i=1; i<v.size(); i++){
		num=v[i]+v[i-1];
		if(!isPrime(num))
			return false;
	}
	num=v[0]+v[v.size()-1];
	if(!isPrime(num))
		return false;
	return true;
}

void display(vector<int> & v){
	int puno;
	for(int i=0; i<v.size(); i++){
		if(v.[i]==1){
			puno=i;
			break;
		}
	}
	for(int i=puno; i<v.size()+puno-1; i++){
		cout<<v[i%v.size()]<<" ";//revisar
	}
	cout<<v[(v.size()+puno-1)%v.size()]<<endl;
}

int main(){
	vector<int> ring;
	int n;
	cin>>n;

	while(!cin.eof()){
		for(int i=0; i<n; i++){
			ring.push_back(i+1);
		}

		do{
			if(isGud(ring)){
				display(ring);
			}
		}while(next_permutation(ring.begin(), ring.end()));
		ring.clear();
		cin>>n;
	}
}