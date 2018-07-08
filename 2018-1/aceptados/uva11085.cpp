#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> board(8);
	vector<vector<int> > sols;
	bool gud;
	for(int i=0; i<8; i++){
		board[i]=i+1;
	}
	do{
		gud=true;
		for(int i=0; i<8; i++){
			for(int j=i+1; j<8; j++){
				if(board[j]==board[i]+j-i || board[j]==board[i]-j+i){
					gud=false;
					break;
				}
			}
			if(!gud)
				break;
		}
		if(gud)
			sols.push_back(board);
	}while(next_permutation(board.begin(),board.end()));

	int c=0;
	while(1){
		c++;
		int moves, best=8;
		board=vector<int>(8);
		for(int i=0; i<8; i++){
			cin>>board[i];
		}
		for(int i=0; i<sols.size(); i++){
			moves=0;
			for(int j=0; j<8; j++){
				if(board[j]!=sols[i][j])
					moves++;
			}
			if(moves<best)
				best=moves;
		}
		if(cin.eof())
			break;
		cout<<"Case "<<c<<": "<<best<<endl;

	}
}