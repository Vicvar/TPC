#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string strToLow(string s){
	for(int i=0; i<s.size(); i++){
		if(s[i]<='Z' && s[i]>='A') s[i]= s[i]-('Z'-'z');
	}
	return s;
}

bool isAnag(string a, string b){
	map<char, int> chars;
	if(a.size()==b.size()){
		a=strToLow(a);
		b=strToLow(b);
		for(int i=0; i<a.size(); i++){
			if(chars.count(a[i])==0) chars.insert(pair<char,int>(a[i],1));
			else chars.at(a[i])++;
		}
		for(int i=0; i<b.size(); i++){
			if(chars.count(b[i])!=0){
				if (chars.at(b[i])==1) chars.erase(b[i]);
				else chars.at(b[i])--;
			}
			else return false;
		}
		if(chars.size()==0) return true;
		else return false;
	}
	return false;
}

int main(){
	bool isAnAn=true;
	vector<string> dic, anans;
	string word;
	cin>>word;
	while(word[0]!='#'){
		dic.push_back(word);
		cin>>word;
	}
	for(int i=0; i<dic.size(); i++){
		for(int j=i+1; j<dic.size(); j++){
			if(isAnag(dic[i],dic[j])){
				dic.erase(dic.begin()+j);
				isAnAn=false;
				j--;
			}
		}
		if(isAnAn) anans.push_back(dic[i]);
		isAnAn=true;
	}
	sort(anans.begin(),anans.end());
	for(int i=0; i<anans.size(); i++){
		cout<<anans[i]<<endl;
	}
}