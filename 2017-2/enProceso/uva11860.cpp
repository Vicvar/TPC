#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	int nd, foundwc, p, q;
	string line, w1;
	vector<string> doc, wlist;
	vector<pair<int,int> > possol;
	cin>>nd;
	getline(cin,line);
	for(int i=0; i<nd; i++){

		int wnum=-1;
		getline(cin,line);
		while(line!="END"){
			for(int j=0; j<line.size(); j++){
				if(line[j]>='a' && line[j]<='z'){
					if(j==0){
						doc.push_back("");
						wnum++;
						doc[wnum]+=line[j];
					}
					if(j>0){
						if(!(line[j-1]>='a' && line[j-1]<='z')){
							doc.push_back("");
							wnum++;
							doc[wnum]+=line[j];
						}
						else{
							doc[wnum]+=line[j];
						}
					}
				}
			}
			getline(cin,line);
		}

		wlist=doc;
		sort(wlist.begin(),wlist.end());
		wlist.erase(unique(wlist.begin(),wlist.end()), wlist.end());

		for(int j=0; j<=doc.size()-wlist.size(); j++){
			foundwc=0;
			q=j;
			for(int k=0; k<wlist.size(); k++){
				w1=wlist[k];
				for(int l=j; l<doc.size(); l++){
					if(w1==doc[l]){
						if(l>q)
							q=l;
						foundwc++;
						break;
					}
				}
			}
			/*if(foundwc==wlist.size())
				possol.push_back(make_pair(q-j,q));
		}
		sort(possol.begin(),possol.end());

		p=-(possol[0].first-possol[0].second-1);
		q=possol[0].second+1;*/
		}
		
		p++;
		q++;
		cout<<"Document "<<i+1<<": "<<p<<" "<<q<<endl;

		doc.clear();
		wlist.clear();
		possol.clear();
	}
}