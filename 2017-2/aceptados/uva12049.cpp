#include <iostream>
#include <queue>

using namespace std;

int main(){
	int nc, N, M, numero, cuenta;
	priority_queue<int> pq1, pq2;

	cin>>nc;
	for(int i=0; i<nc; i++){
		cuenta=0;
		cin>>N>>M;

		for(int j=0; j<N; j++){
			cin>>numero;
			pq1.push(-numero);
		}
		for(int j=0; j<M; j++){
			cin>>numero;
			pq2.push(-numero);
		}
		int top1, top2;
		while(!pq1.empty() && !pq2.empty()){
			top1=pq1.top();
			top2=pq2.top();
			if(top1==top2){
				pq1.pop();
				pq2.pop();
			}
			else{
				if(top1<top2)
					pq2.pop();
				else
					pq1.pop();
			cuenta++;
			}
		}
		cuenta+=pq1.size()+pq2.size();
		cout<<cuenta<<endl;
		pq1 = priority_queue<int> ();
		pq2 = priority_queue<int> ();
	}
}