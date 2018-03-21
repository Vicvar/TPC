#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comparef(string a, string b){
	if(a.size()!=b.size())
		return a.size() < b.size();
	else
		return a.compare(b)<0;
}


int main(){
	vector<string> palabras;
	string palabra;
	map<string, int> index;

	for(char i='a'; i<='z'; i++){
		palabra="";
		palabra+=i;
		palabras.push_back(palabra);
		for(char j=i+1; j<='z'; j++){
			palabra="";
			palabra+=i;
			palabra+=j;
			palabras.push_back(palabra);
			for(char k=j+1; k<='z'; k++){
							palabra="";
			palabra+=i;
			palabra+=j;
			palabra+=k;
			palabras.push_back(palabra);
				for(char l=k+1; l<='z'; l++){
					palabra="";
					palabra+=i;
					palabra+=j;
					palabra+=k;
					palabra+=l;
					palabras.push_back(palabra);
					for(char m=l+1; m<='z'; m++){
						palabra="";
						palabra+=i;
						palabra+=j;
						palabra+=k;
						palabra+=l;
						palabra+=m;
						palabras.push_back(palabra);	
					}	
				}
			}
		}
	}
	sort(palabras.begin(),palabras.end(), comparef);
	for(int i=0; i<palabras.size(); i++){
		index.insert(pair<string, int> (palabras[i],i+1));
	}

	char w[6];
	map<string,int>::iterator it;

	cin.getline(w,sizeof(w));
	bool nend=true;
	while(nend){
		string word(w);
		it=index.find(word);
		if(it!=index.end()){
			cout<<it->second<<endl;
		}
		else
			cout<<0<<endl;
		nend=(bool)cin.getline(w,sizeof(w));
	}
}