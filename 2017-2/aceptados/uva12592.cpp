#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
	int ns;
	char line[101];
	map<string,string> princess;

	cin>>ns;
	cin.getline(line, sizeof (line));
	for(int i=0; i<ns; i++){
		cin.getline(line, sizeof(line));
		string slogan1(line);
		cin.getline(line, sizeof(line));
		string slogan2(line);
		princess.insert(pair<string, string> (slogan1, slogan2));
	}

	cin>>ns;
	cin.getline(line, sizeof(line));
	for(int i=0; i<ns; i++){
		cin.getline(line, sizeof(line));;
		string sloganf(line);
		cout<<princess[sloganf]<<endl;
	}
}