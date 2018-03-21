#include <iostream>

using namespace std;

int main(){
	int notc, nosc, nr, fr;
	cin>>notc;
	for(int i=0; i<notc; i++){
		cin>>nosc;
		cin>>fr;
		for(int j=0; j<nosc-1; j++){
			cin>>nr;
			if(nr>fr) fr=nr;
		}
		cout<<"Case "<<i+1<<": "<<fr<<endl;
	}
}