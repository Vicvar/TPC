#include <iostream>
#include <string>
#include <map>
#include <tuple>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <clocale>

using namespace std;

void updateScores(string ht, int hts, string at, int ats, map<string, vector<int> > & teams){
	int htpoints, atpoints;
	if(hts>ats){
		teams[ht].at(0)+=3;
	}
	else if(ats>hts){
		teams[at].at(0)+=3;
	}
	else{
		teams[ht].at(0)++;
		teams[at].at(0)++;
	}
	teams[ht].at(1)+=hts-ats;
	teams[at].at(1)+=ats-hts;
	teams[ht].at(2)+=hts;
	teams[at].at(2)+=ats;
	teams[ht].at(3)++;
	teams[at].at(3)++;
}

void display(vector<tuple<int,int,int, int, string> > tabla){
	int s, gdif, sg, ngp, cont=1;
	for(int i=0; i<tabla.size(); i++){
		string nombre=get<4>(tabla.at(i));

		s=get<0>(tabla.at(i));
		gdif=get<1>(tabla.at(i));
		sg=get<2>(tabla.at(i));
		ngp=get<3>(tabla.at(i));
		string str=to_string(cont);
		str+=".";
		cout<<left;
		if(i==0) cout<<setw(3)<<str;
		if(i>0 && !(get<0>(tabla.at(i-1))==s && get<1>(tabla.at(i-1))==gdif && get<2>(tabla.at(i-1))==sg)){
			cout<<setw(3)<<str;
		}else{
			cout<<right;
			if(i!=0) cout<<"   ";	
		} 
		cout<<right;
		cout<<setw(15)<<nombre<<setw(4)<<-s<<setw(4)<<-ngp<<setw(4)<<-sg<<setw(4)<<-(sg-gdif)<<setw(4)<<-gdif;
		if(ngp<0){
			float fl = 100*(float)(-s)/((float)(-ngp)*3);
			cout<<setw(7)<<fl;
		}
		else cout<<setw(7)<<"N/A";
		cout<<endl;
		cont++;
	}
}

int main(){
	cout<<fixed;
	cout<<setprecision(2);
	int T, G, hts, ats;
	vector<int> score;
	vector<tuple<int, int, int , int, string> > postab;
	vector<string> teamlist;
	string t;
	string tname, homet, awayt, dash;
	map<string, vector<int> > teams; 
	vector<int> cero(4,0);

	setlocale(LC_COLLATE, "C");
	cin>>T>>G;
	while(T!=0){
		for(int i=0; i<T; i++){
			cin>>tname;
			teamlist.push_back(tname);
			teams.insert(pair<string, vector<int> >(tname,cero));
		}
		for(int i=0; i<G; i++){
			cin>>homet>>hts>>dash>>ats>>awayt;
			updateScores(homet, hts, awayt, ats, teams);
		}
		for(int i=0; i<teams.size(); i++){
			t=teamlist.at(i);
			score=teams.at(t);
			tuple<int, int, int , int, string> tupla=make_tuple(-score[0],-score[1],-score[2],-score[3],t);
			postab.push_back(tupla);
		}
		
		sort(postab.begin(),postab.end(),strcoll);
		display(postab);
		teams.clear();
		score.clear();
		postab.clear();
		teamlist.clear();
		cin>>T>>G;
		if(T!=0)cout<<endl;
	}
}