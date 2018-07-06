#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int tc, n, best;
	vector<vector<int> > grid;
	vector<int> choice;
	cin>>tc;
	for(int i=0; i<tc; i++){
		cin>>n;
		best=1000*8;
		choice=vector<int>(n);
		grid=vector<vector<int> >(n,vector<int>(n));
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				cin>>grid[j][k];
			}
		}
		for(int j=0; j<n; j++){
			choice[j]=j;
		}
		do{
			int sum=0;
			for(int j=0; j<n; j++){
				sum+=grid[choice[j]][j];
			}
			if(sum<best)
				best=sum;
		}while(next_permutation(choice.begin(), choice.end()));
		cout<<best<<endl;
	}
}