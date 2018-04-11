#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <algorithm>


using namespace std;

int getDist(int a, int b){
	int x=a/5;
	int y=a%5;
	int n=b/5;
	int m=b%5;
	return abs(x-n)+abs(y-m);
}

int main(){
	vector<int> city;
	vector<int> dists;
	vector<int> ans;
	set<int> avpos;
	int tc, nnp, r, c, p;

	cin>>tc;

	for(int i=0; i<tc; i++){

		cin>> nnp;

		for(int j=0; j<nnp; j++){
			cin>>r>>c>>p;
			city[5*r+y]=q;
		}

		for(int j=0; j<25; j++){
			dists[j]=100;
			avpos.insert(j);
		}

		for(int j=0; j<5; j++){

			for(set::iterator it=avpos.begin(); it!=avpos.end(); it++){
				for(int k=0; k<25; k++){
					
				}
			}
		}
	}
}

/*int main(){

	int t;
	cin>>t;

	for(int i=0; i<t; i++){
		vector<int> city(25);//valores de poblacion
		vector<int> mind(25);//distancia de cada cuadrante a la of. mas cercana
		vector<int> auxd(25);//distancias "mejoradas" a la of. a ubicar
		vector<int> loc;
		int nnp;

		cin>>nnp;
		for(int j=0; j<nnp; j++){
			int x,y,q;
			cin>>x>>y>>q;
			city[5*x+y]=q;
		}

		//init con dist inf
		for(int j=0; j<25; j++){
			mind[j]=1000;
		}

		//obtener la mejor pos para cada oficina
		int bl=100*25;
		int distaux;

		for(int j=0; j<5; j++){
		int mejor=0;
		distaux=bl;

			//probar todos los cuadrantes(no asignados)
			for(int k=0; k<25;k++){
				int dist=0; //dist acumulada
				auxd=mind;

				if(!(find(loc.begin(), loc.end(), k)==loc.end()))
					break;
				//calcular la mejora y elegir la mayor
				for(int l=0; l<25; l++){
					//calc dist w act di
					int d=getDist(l,k);
					if(d<mind[l]){
						dist+=d*city[l];
						auxd[l]=d;
					}
					else
						dist+=mind[l]*city[l];
				}

				if(dist<distaux){
					distaux=dist;
					mejor=k;
					mind=auxd;
				}
			}
			bl=distaux;
			loc.push_back(mejor);
		}


		sort(loc.begin(), loc.end());
		for(int j=0; j<loc.size(); j++){
			cout<<loc[j]<<" ";
		}
		cout<<endl;

		city.clear();
		mind.clear();
		auxd.clear();
		loc.clear();

	}
}*/