#include <iostream>

using namespace std;

int main(){
	int n1, n2, max, min, next;
	cin>>n1;
	for(int i=0;i<n1; i++){
		cin>>n2;
		cin>>max;
		min=max;
		for (int j=0;j<n2-1; j++){
			cin>>next;
			if (next>max) max=next;
			else if (next<min) min=next;
		}
		cout<<(max-min)*2<<endl;
	}
}