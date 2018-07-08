#include <iostream>
#include <string>

using namespace std;

bool isSubs(string s, string t){
	if(s.empty())
		return true;
	else if(t.empty())
		return false;
	char f=s[0];
	for(int i=0; i<t.size(); i++){
		if(f==t[i]){
			string scopy=s;
			string tcopy=t;
			scopy.erase(0,1);
			tcopy=t.substr(i+1, t.size()-i);
			if(isSubs(scopy,tcopy))
				return true;
		}
	}
	return false;
}

int main(){
	string s, t;
	cin>>s>>t;
	bool ans;
	while(!cin.eof()){
		ans=isSubs(s,t);
		if(ans)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
		cin>>s>>t;
	}
}