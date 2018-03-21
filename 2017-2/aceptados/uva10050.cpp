#include <iostream>
#include <set>

using namespace std;

void rmSfHP(set<int> & s){
	for(set<int>::iterator it=s.begin(); it!=s.end(); ++it){
		for (set<int>::iterator itt = s.begin(); itt != s.end(); ++itt){
			if(*itt%*it==0 && *itt!=*it) s.erase(*itt);
		}
	}
}

int main(){
	int caseq, simspan, ppq, hp;
	set<int> hparv, lostdays;

	cin>>caseq;
	for(int i=0; i<caseq; i++){
		cin>>simspan;
		cin>>ppq;
		for(int j=0; j<ppq; j++){
			cin>>hp;
			hparv.insert(hp);
		}
		rmSfHP(hparv);

		for(set<int>::iterator i=hparv.begin(); i!=hparv.end(); ++i){
			int ld=*i;
			while(ld<=simspan){
				if(ld%7!=0 && ld%7!=6) 
					lostdays.insert(ld);
				ld=ld+*i;
			}
		}
		cout<<lostdays.size()<<endl;
		
		lostdays.clear();
		hparv.clear();
	}
}