#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> countMods(vector<int> nums){
	int mod;
	vector<int> mods(3,0);
	for(int i=0; i<nums.size(); i++){
		mod=nums[i]%3;
		mods[mod]++;
	}
	return mods;
}

vector<int> sep(string N){
	vector<int> r;
	for(int i=0; i<N.size(); i++){
		r.push_back((int)N[i]-'0');
	}
	return r;
}


int main(){
	int nc, sum, cuenta;
	string N;
	vector<int> nums, mods;
	cin>>nc;
	for(int i=0; i<nc; i++){
		cin>>N;
		sum=0;
		cuenta=0;
		nums=sep(N);
		mods=countMods(nums);
		cout<<"Case "<<i+1<<": ";
		for(int j=0; j<nums.size(); j++){
			sum+=nums[j];
		}
		if(nums.size()>1){
			cuenta=mods[0];
			if(sum%3==0) cuenta++; 
			if(mods[sum%3]>0){
				if((cuenta+1)%2==1){
					cout<<"S"<<endl;
				}
				else cout<<"T"<<endl;
			}
			else{
				cout<<"T"<<endl;
			}
		}
		else cout<<"S"<<endl;
	}
}