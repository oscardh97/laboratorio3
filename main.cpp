#include <iostream>
#include <cmath>
using namespace std;
void imprimirTablero(int[4][4][4]);
void hacerMovimiento(int[4][4][4], int[4][4][4], bool);
bool gano(int, int, int[4][4][4]);
int main(int argc, char const *argv[]){
	bool jugador = false;
	int pozo[4][4][4] = {
		{{0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1}},
		{{0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1}},
		{{1,0,0,0},{1,0,0,1},{1,0,1,0},{1,0,1,1}},
		{{1,1,0,0},{1,1,0,1},{1,1,1,0},{1,1,1,1}}
	};
	int tablero[4][4][4] = {
		{{3,3,3,3},{3,3,3,3},{3,3,3,3},{3,3,3,3}},
		{{3,3,3,3},{3,3,3,3},{3,3,3,3},{3,3,3,3}},
		{{3,3,3,3},{3,3,3,3},{3,3,3,3},{3,3,3,3}},
		{{3,3,3,3},{3,3,3,3},{3,3,3,3},{3,3,3,3}}
	};
	do{
		cout<<"-----------------------------------POZO---------------------------------------"<<endl;
		imprimirTablero(pozo);
		cout<<"---------------------------------TABLERO-------------------------------------"<<endl;
		imprimirTablero(tablero);
		jugador = !jugador;
		hacerMovimiento(pozo,tablero, jugador);
	}while(1);
	return 0;
}
void hacerMovimiento(int pozo[4][4][4], int tablero[4][4][4], bool jugador){
	int fila, columna, filaTablero, columnaTablero;
	do{
		cout << "JUGADOR " << (jugador ? 1 : 2) << endl;
		cout << "INGRESE LA FILA DEL POZO" << endl;
		cin >> fila;
		cout << "INGRESE LA COLUMNA DEL POZO" << endl;
		cin >> columna;
		if(pozo[fila][columna][0] != 3){
			break;
		}
		cout << "Ficha Invalida" << endl;
		cout << pozo[fila][columna] << endl;
	}while(1);
	do{	
		cout << "JUGADOR " << (jugador ? 2 : 1) << endl;
		cout << "INGRESE LA FILA DEL TABLERO" << endl;
		cin >> filaTablero;
		cout << "INGRESE LA COLUMNA DEL TABLERO" << endl;
		cin >> columnaTablero;
		if(tablero[filaTablero][columnaTablero][0] == 3){
			break;
		}
		cout << "Posicion Invalida" << endl;
	}while(1);
	for(int k = 0; k < 4; k++){
		tablero[filaTablero][columnaTablero][k] = pozo[fila][columna][k];
		pozo[fila][columna][k] = 3;
	}
	cout<<"GANO??? =>" << gano(filaTablero, columnaTablero, tablero);
}
void imprimirTablero(int tablero[4][4][4]){
	const int DIFERENCIA = 3;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			cout << "F" << i << "C" << j << "\t => "<< '[';
			for(int k = 0; k < 4; k++){
				cout << tablero[i][j][k];
			}
			cout << ']'<<"\t";
		}
			cout<<endl;
	}
}
bool gano(int fila, int columna, int tablero[4][4][4]){
	for(int i = 0; i < 4; i++){
		int valFila[4] = {0};
		for(int j = 0; j < 4; j++){
			int valCol[4] = {0};
			if(fila == i || j == columna){
				for(int k = 0; k < 4; k++){
					if(tablero[i][j][k] == tablero[fila][columna][k]){
						valFila[k]++;
						valCol[k]++;
						// break;
					}
				}
				for(int l = 0; l < 4; l++){
					if(valCol[l] == 4){
						return true;
					}
				}
			}
		}
		
		for(int l = 0; l < 4; l++){
			if(valFila[l] == 4){
				return true;
			}
		}
	}
	// for(int i = 0; i < 4; i++){
	// 	int valFila[4] = {0};
	// 	for(int j = 0; j < 4; j++){
	// 		if(abs(i - 1 || j == columna){
	// 			for(int k = 0; k < 4; k++){
	// 				if(tablero[i][j][k] == tablero[fila][columna][k]){
	// 					valFila[k]++;
	// 					valCol[k]++;
	// 					// break;
	// 				}
	// 			}
	// 			for(int l = 0; l < 4; l++){
	// 				if(valCol[l] == 4){
	// 					return true;
	// 				}
	// 			}
	// 		}
	// 	}
		
	// 	for(int l = 0; l < 4; l++){
	// 		if(valFila[l] == 4){
	// 			return true;
	// 		}
	// 	}
	// }
	return 0;
}
