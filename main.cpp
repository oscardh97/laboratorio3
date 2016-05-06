#include <iostream>
using namespace std;
void imprimirTablero(int[4][4][4]);
int main(int argc, char const *argv[]){
	int tablero[4][4][4] = {
		{{0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1}},
		{{0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1}},
		{{1,0,0,0},{1,0,0,1},{1,0,1,0},{1,0,1,1}},
		{{1,1,0,0},{1,1,0,1},{1,1,1,0},{1,1,1,1}}
	};
	int pozo[4][4][4] = {
		{{3,3,3,3},{3,3,3,3},{3,3,3,3},{3,3,3,3}},
		{{3,3,3,3},{3,3,3,3},{3,3,3,3},{3,3,3,3}},
		{{3,3,3,3},{3,3,3,3},{3,3,3,3},{3,3,3,3}},
		{{3,3,3,3},{3,3,3,3},{3,3,3,3},{3,3,3,3}}
	};
	cout<<"---------------------------------TABLERO-------------------------------------"<<endl;
	imprimirTablero(pozo);
	cout<<"-----------------------------------POZO---------------------------------------"<<endl;
	imprimirTablero(tablero);
	return 0;
}
// hacerMovimiento()
void imprimirTablero(int tablero[4][4][4]){
	int primeraPropiedad = 0;
	int segundaPropiedad = 0;
	int terceraPropiedad = 0;
	int cuartaPropiedad = 0;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			cout << '[';
			for(int k = 0; k < 4; k++){
				if(k == 3){

				}
				// tablero[i][j][k] = 1;
				cout << tablero[i][j][k];
			}
			cout << ']'<<"\t";
		}
			cout<<endl;
	}
}