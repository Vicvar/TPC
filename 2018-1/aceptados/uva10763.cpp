#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main(){
	int n, ori, dest;
	multimap<int,int> od;
	pair<multimap<int,int>::iterator,multimap<int,int>::iterator> its;
	cin>>n;
	while(n!=0){
		od.clear();
		for(int i=0; i<n; i++){
			cin>>ori>>dest;
			bool add=true;
			its=od.equal_range(dest);
			for(multimap<int,int>::iterator it=its.first; it!=its.second; it++){
				if(it->second==ori){
					od.erase(it);
					add=false;
					break;
				}
			}
			if(its.first==its.second)
				od.insert(make_pair(ori,dest));
			else if(add)
					od.insert(make_pair(ori,dest));
		}
		if(od.size()==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		cin>>n;
	}
}