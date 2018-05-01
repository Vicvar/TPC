#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
	int t, n, num, sum;
	int inset;
	vector<int> list;
	vector<int> sol;
	set<vector<int> > soluciones;

	cin>>t>>n;
	while(n!=0){
		cout<<"Sums of "<<t<<":"<<endl;

		for(int i=0; i<n; i++){
			cin>>num;
			list.push_back(num);
		}

		for(int i=0; i<1<<n; i++){
			inset=i;
			sum=0;
			for(int j=0; j<n; j++){
				if(inset&1){
					sum+=list[j];
				}
				if(sum>t)
					break;
				inset>>=1;
			}
			if(sum==t){
				inset=i;
				for(int j=0; j<n; j++){
					if(inset&1){
						sol.push_back(list[j]);
					}
					inset>>=1;
				}
				soluciones.insert(sol);
			}
			sol.clear();
		}

		if(soluciones.size()==0)
			cout<<"NONE"<<endl;
		else{
			for(set<vector<int> >::reverse_iterator it=soluciones.rbegin(); it!=soluciones.rend(); it++){
				vector<int> ans = *it;
				for(int i=0; i<ans.size()-1; i++){
					cout<<ans[i]<<"+";
				}
				cout<<ans[ans.size()-1]<<endl;
			}
		}

		soluciones.clear();
		list.clear();
		cin>>t>>n;
	}
}