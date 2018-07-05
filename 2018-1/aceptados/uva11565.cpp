#include <iostream>

using namespace std;

int main(){
	int nc, a, b,c;
	cin>>nc;
	for(int i=0; i<nc; i++){
		cin>>a>>b>>c;

		for(int x=0; x*x<=c; x++){
			for(int y=0; x*x+y*y<=c ; y++){
				for(int z=0; x*x+y*y+z*z<=c; z++){
					if(-x-y+z==a  && x*y*z==b && x*x+y*y+z*z==c && x!=y && y!=z && z!=x){
						cout<<-y<<" "<<-x<<" "<<z<<endl;
						goto gud;
					}
					else if(x+y+z==a && x*y*z==b && x*x+y*y+z*z==c && x!=y && y!=z && z!=x){
						cout<<x<<" "<<y<<" "<<z<<endl;
						goto gud;
					}
				}
			}
		}
		cout<<"No solution."<<endl;
		gud:;
	}
}