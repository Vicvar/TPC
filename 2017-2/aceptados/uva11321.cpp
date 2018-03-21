#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct compare{
	compare(int M){
		this->M=M;
	}
	bool operator () (int i, int j){
		if(i%M!=j%M){return i%M<j%M;}
		else{
			if(i%2!=0 && j%2==0) return true;
			else if(i%2==0 && j%2!=0) return false;
			else if(i%2!=0 && j%2!=0) return i>j;
			else return i<j;
		}
	}
	int M;
};

int main (){
	int N,M,n;
	vector<int> numbers;
	cin>>N>>M;
	cout<<N<<" "<<M<<endl;
	while(M!=0){
		for(int i=0; i<N; i++){
			cin>>n;
			numbers.push_back(n);
		}
		sort(numbers.begin(), numbers.end(), compare(M));
		for(int i=0; i<numbers.size(); i++){
			cout<<numbers[i]<<endl;
		}
		cin>>N>>M;
		cout<<N<<" "<<M<<endl;
		numbers.clear();
	}
}