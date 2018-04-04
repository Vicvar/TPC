#include <iostream>
#include <vector>
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

	int t;
	cin>>t;

	for(int i=0; i<t; i++){
		vector<int> city(25);//valores de poblacion
		vector<int> dto(25);//distancia de cada cuadrante a la of. mas cercana
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
			dto[j]=100;
		}

		//obtener la mejor pos para cada oficina
		for(int j=0; j<5; j++){
			int bl=80*25;
			int mejor=0;

			//probar todos los cuadrantes(no asignados)
			for(int k=0; k<25;k++){
				if(find(loc.begin(), loc.end(), k)==loc.end()){
					int dist=0;
					auxd=dto;
					//calcular la mejora y elegir la mayor
					for(int l=0; l<25; l++){
						//calc dist w act di
						int d=getDist(l,k);
						if(d<dto[l]){
							dist+=d*city[l];
							auxd[l]=d;
						}
						else
							dist+=dto[l]*city[l];
					}
					if(dist<bl){
						bl=dist;
						mejor=k;
					}
					dto=auxd;
				}
			}
			loc.push_back(mejor);
		}
		sort(loc.begin(), loc.end());
		for(int j=0; j<loc.size(); j++){
			cout<<loc[j]<<" ";
		}
		cout<<endl;

		city.clear();
		dto.clear();
		auxd.clear();
		loc.clear();

	}
}