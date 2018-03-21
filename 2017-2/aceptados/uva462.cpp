#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cstdio>

using namespace std;

void getBet(vector<pair<char,char> >);

int main(){
	string card;
	pair<char, char> aux;
	vector<pair<char, char> > hand;
	do{
		cin>>card;
		aux.first=card[0];
		aux.second=card[1];
		hand.push_back(aux);
		if(hand.size()==13){
			getBet(hand);
			hand.clear();
		}
	}
	while(!cin.eof());
}

int rule234(vector<char> suit, bool* stop){
	int score=0;

	for (vector<char>::iterator i=suit.begin(); i!=suit.end(); ++i){
		if(*i=='A') *stop=true;
		if(*i=='K'){
			if(suit.size()==1) score--;
			else *stop=true;
		}
		if(*i=='Q'){
			if(suit.size()<3)score--;
			else *stop=true;
		}
		if(*i=='J' && suit.size()<4) score--;
	}
	return score;
}

void  getBet(vector<pair<char,char> > hand){
	int score=0, count=0;
	vector<char> sS, sH, sC, sD;
	bool stopS=false, stopH=false, stopC=false, stopD=false;

	//rule 1
	for(vector<pair<char,char> >::iterator i=hand.begin(); i!=hand.end(); ++i){
		if(i->first=='A') score+=4;
		if(i->first=='K') score+=3;
		if(i->first=='Q') score+=2;
		if(i->first=='J') score+=1;

		if(i->second=='S') sS.push_back(i->first);
		if(i->second=='H') sH.push_back(i->first);
		if(i->second=='C') sC.push_back(i->first);
		if(i->second=='D') sD.push_back(i->first);
	}

	//rules 2,3,4
	score=score+rule234(sS,&stopS);
	score=score+rule234(sH,&stopH);
	score=score+rule234(sC,&stopC);
	score=score+rule234(sD,&stopD);

	if(stopS && stopH && stopC && stopD && score>15){
		cout<<"BID NO-TRUMP"<<endl;
		return;
	}

	//rule 5
	if(sS.size()==2) score++;
	if(sH.size()==2) score++;
	if(sC.size()==2) score++;
	if(sD.size()==2) score++;

	//rules 6,7
	if(sS.size()==1 | sS.size()==0) score+=2;
	if(sH.size()==1 | sH.size()==0) score+=2;
	if(sC.size()==1 | sC.size()==0) score+=2;
	if(sD.size()==1 | sD.size()==0) score+=2;
	
	//bid
	if(score<14) cout<<"PASS"<<endl;
	if(score>13){
		if(sS.size() >= sH.size() && sS.size() >= sC.size() && sS.size() >= sD.size()) 
			cout<<"BID S"<<endl;
		else if(sH.size() >= sS.size() && sH.size() >= sC.size() && sH.size() >= sD.size())
			cout<<"BID H"<<endl;
		else if(sD.size() >= sH.size() && sD.size() >= sS.size() && sD.size() >= sC.size())
			cout<<"BID D"<<endl;
		else 
			cout<<"BID C"<<endl;
	}
}