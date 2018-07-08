#include <iostream>
#include <vector>

using namespace std;

bool nPath(int s, int f, int n, vector<vector<int> > p){
	if(s==f && n==0)
		return true;
	if(n<0)
		return false;
	for(int i=0; i<7; i++){
		if(p[s][i]){
			vector<vector<int> > pcopy=p;
			pcopy[s][i]--;
			pcopy[i][s]--;
			if(nPath(i,f,n-1,pcopy))
				return true;
		}
	}
	return false;
}

int main(){
	int n, m, a, b, s, f;
	bool ans;
	vector<vector<int> > p;
	cin>>n;
	while(n!=0){
		cin>>m;
		cin>>s>>s;
		cin>>f;
		cin>>a;
		p=vector<vector<int> >(7, vector<int>(7, 0));
		for(int i=0; i<m; i++){
			cin>>a>>b;
			p[a][b]++;
			p[b][a]++;
		}
		ans=nPath(s,f,n,p);
		if(ans)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		cin>>n;
	}
}