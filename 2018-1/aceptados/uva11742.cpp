#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool validPerm(vector<int> perm, int a, int b, int c){
	int dist;
	vector<int>::iterator it;
	dist = abs(find(perm.begin(),perm.end(),a) - find(perm.begin(),perm.end(),b));
	if(c>=0){
		if(dist<=c)
			return true;
		else
			return false;
	}
	if(c<0){
		if(dist>=-c)
			return true;
		else
			return false;
	}
}


int main(){
	int n, m, a, b, c;
	vector<int> perm;
	vector<vector<int> > rest;

	cin>>n>>m;
	while(!(n==0 && m==0)){
		int cont=0;
		vector<int> aux;
		for(int i=0; i<m; i++){
			cin>>a>>b>>c;
			aux.push_back(a);
			aux.push_back(b);
			aux.push_back(c);
			rest.push_back(aux);
			aux.clear();
		}

		for(int i=0; i<n; i++){
			perm.push_back(i);
		}

		do{
			bool valid=true;
			for(int i=0; i<m; i++){
				if(!validPerm(perm, rest[i][0], rest[i][1], rest[i][2])){
					valid=false;
					break;
				}
			}
			if(valid)
				cont++;
		}while(next_permutation(perm.begin(),perm.end()));

		rest.clear();
		perm.clear();
		cout<<cont<<endl;
		cin>>n>>m;
	}
}