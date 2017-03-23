#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Casilla{
	char etiqueta;
	char tipo;
	int nMinas;

};
typedef struct Casilla tipoCasilla;

/*void IniciarJuego(int filas, int cols, int **matriz){
	for(int i=0; i<filas; i++){
		matriz[i] = (int *)malloc(cols * sizeof(int));
	}
}
*/

void DibujarTablero(int filas, int cols, tipoCasilla **matriz ){
	// for(int i=0; i<filas; i++){
	// 	printf("\n");
	// 	for(int j=0; j<cols; j++){
	// 		//matriz[i][j] = 0;
	// 		matriz[i][j].etiqueta ='*';
	// 		//matriz[i][j].tipo= 'c';
	// 		//matriz[i][j].nMinas= 0;
	// 		printf("%i ", matriz[i][j].nMinas);
	// 	}
	// }
	
	//printf("\n\n---------------------------------------------\n");
	
	for(int i=0; i<filas; i++){
		printf("\n");
		for(int j=0; j<cols; j++){
			//matriz[i][j] = 0;
			//matriz[i][j].etiqueta ='*';
			//matriz[i][j].tipo= 'c';
			//matriz[i][j].nMinas= 0;
			printf("%c ", matriz[i][j].tipo);
		}
	}

	printf("\n\n---------------------------------------------\n");

	// printf("\n\nhuehuehueuheeuuheuheuh\n");

	for(int i=0; i<filas; i++){
		printf("\n");
		for(int j=0; j<cols; j++){
			//matriz[i][j] = 0;
			//matriz[i][j].etiqueta ='*';
			//matriz[i][j].tipo= 'c';
			//matriz[i][j].nMinas= 0;
			printf("%i ", matriz[i][j].nMinas);
		}
	}

	printf("\n\n---------------------------------------------\n");

	for(int i=0; i<filas; i++){
		printf("\n");
		for(int j=0; j<cols; j++){
			//matriz[i][j] = 0;
			//matriz[i][j].etiqueta ='*';
			//matriz[i][j].tipo= 'c';
			//matriz[i][j].nMinas= 0;
			printf("%c ", matriz[i][j].etiqueta);
		}
	}
}

int valideichon(int filas, int cols,int i,int j){
	if( i >= 0 && j >= 0 && i < filas && j < cols){
		return 1;
	}else{
		return 0;
	}
}

void colocarMinas(int filas, int cols, int minas, tipoCasilla **matriz){
	srand(time(NULL));
	for(int i=0;i<minas;i++){
		int x = rand()%filas;
		int y = rand()%cols;
		matriz[x][y].tipo='m';
	}
}

void indicarMinas(int filas, int cols,tipoCasilla **matriz){
	int cont;
	for(int i=0;i<filas;i++){
		for(int j=0;j<cols;j++){
		cont= 0;
			if(valideichon(filas, cols,i, j+1)){
				if(matriz[i][j+1].tipo=='m'){
					cont++;
				}
			}

			if(valideichon(filas, cols,i+1, j)){
				if(matriz[i+1][j].tipo=='m'){
					cont++;
				}
			}

			if(valideichon(filas, cols,i+1, j+1)){
				if(matriz[i+1][j+1].tipo=='m'){
					cont++;
				}
			}

			if(valideichon(filas, cols,i, j-1)){
				if(matriz[i][j-1].tipo=='m'){
					cont++;
				}
			}

			if(valideichon(filas, cols,i-1, j)){
				if(matriz[i-1][j].tipo=='m'){
					cont++;
				}
			}

			if(valideichon(filas, cols,i-1, j-1)){
				if(matriz[i-1][j-1].tipo=='m'){
					cont++;
				}
			}

			if(valideichon(filas, cols,i+1, j-1)){
				if(matriz[i+1][j-1].tipo=='m'){
					cont++;
				}
			}

			if(valideichon(filas, cols,i-1, j+1)){
				if(matriz[i-1][j+1].tipo=='m'){
					cont++;
				}
			}
			matriz[i][j].nMinas=cont;
		}
	}
}

void inFraganti(int filas, int cols, tipoCasilla **matriz, int x_1, int y_1, char comand){
	for(int i=0;i<filas;i++){
		for(int j=0;j<cols;j++){
			if(matriz[i][j].tipo=='c'){
				if(valideichon(filas, cols,x_1, y_1)){
					if(matriz[x_1][y_1].nMinas==0){
						if(comand=='e'){
							if(matriz[x_1][y_1].etiqueta=='*'){
								inFraganti(filas,cols,matriz,x_1,y_1,comand);
							}
						}
					}
				}
			}

			if(matriz[i][j+1].tipo=='c'){
				if(valideichon(filas, cols,x_1, y_1+1)){
					if(matriz[x_1][y_1+1].nMinas==0){
						if(comand=='e'){
							if(matriz[x_1][y_1].etiqueta=='*'){
								inFraganti(filas,cols,matriz,x_1,y_1+1,comand);
							}
						}
					}
				}
			}

			if(matriz[i+1][j].tipo=='c'){
				if(valideichon(filas, cols,x_1+1, y_1)){
					if(matriz[x_1+1][y_1].nMinas==0){
						if(comand=='e'){
							if(matriz[x_1][y_1].etiqueta=='*'){
								inFraganti(filas,cols,matriz,x_1+1,y_1,comand);
							}
						}
					}
				}
			}

			if(matriz[i+1][j+1].tipo=='c'){
				if(valideichon(filas, cols,x_1+1, y_1+1)){
					if(matriz[x_1+1][y_1+1].nMinas==0){
						if(comand=='e'){
							if(matriz[x_1][y_1].etiqueta=='*'){
								inFraganti(filas,cols,matriz,x_1+1,y_1+1,comand);
							}
						}
					}
				}
			}

			if(matriz[i][j-1].tipo=='c'){
				if(valideichon(filas, cols,x_1, y_1-1)){
					if(matriz[x_1][y_1-1].nMinas==0){
						if(comand=='e'){
							if(matriz[x_1][y_1].etiqueta=='*'){
								inFraganti(filas,cols,matriz,x_1,y_1-1,comand);
							}
						}
					}
				}
			}

			if(matriz[i-1][j].tipo=='c'){
				if(valideichon(filas, cols,x_1-1, y_1)){
					if(matriz[x_1-1][y_1].nMinas==0){
						if(comand=='e'){
							if(matriz[x_1][y_1].etiqueta=='*'){
								inFraganti(filas,cols,matriz,x_1-1,y_1,comand);
							}
						}
					}
				}
			}

			if(matriz[i-1][j-1].tipo=='c'){
				if(valideichon(filas, cols,x_1-1, y_1-1)){
					if(matriz[x_1-1][y_1-1].nMinas==0){
						if(comand=='e'){
							if(matriz[x_1][y_1].etiqueta=='*'){
								inFraganti(filas,cols,matriz,x_1-1,y_1-1,comand);
							}
						}
					}
				}
			}

			if(matriz[i+1][j-1].tipo=='c'){
				if(valideichon(filas, cols,x_1+1, y_1-1)){
					if(matriz[x_1+1][y_1-1].nMinas==0){
						if(comand=='e'){
							if(matriz[x_1][y_1].etiqueta=='*'){
								inFraganti(filas,cols,matriz,x_1+1,y_1-1,comand);
							}
						}
					}
				}
			}

			if(matriz[i-1][j+1].tipo='c'){
				if(valideichon(filas, cols,x_1-1, y_1+1)){
					if(matriz[x_1-1][y_1+1].nMinas==0){
						if(comand=='e'){
							if(matriz[x_1][y_1].etiqueta=='*'){
								inFraganti(filas,cols,matriz,x_1-1,y_1+1,comand);
							}
						}
					}
				}
			}
		}
	}
}

void niggaPlay(int filas, int cols, char comand, int x_1, int y_1, tipoCasilla **matriz){
	if(comand=='e' && matriz[x_1][y_1].etiqueta=='*'){
		//matriz[x_1][y_1].tipo=matriz[x_1][y_1].nMinas;
		//if(matriz[x_1][y_1].etiqueta=='*'){
		if(matriz[x_1][y_1].nMinas==0){
			matriz[x_1][y_1].etiqueta=matriz[x_1][y_1].nMinas;
			inFraganti(filas,cols,matriz,x_1,y_1,comand);
			printf("\n\n---------------------------------------------\n");

			for(int i=0; i<filas; i++){
				printf("\n");
				for(int j=0; j<cols; j++){
					//matriz[i][j] = 0;
					//matriz[i][j].etiqueta ='*';
					//matriz[i][j].tipo= 'c';
					//matriz[i][j].nMinas= 0;
					printf("%c ", matriz[i][j].etiqueta);
				}
			}
		}
	}else if(comand=='f'){
		matriz[x_1][y_1].etiqueta='f';
	}
}

void main(int argc, char *argv[]){
	int filas = atoi(argv[1]);
	int cols = atoi(argv[2]);
	int m = atoi(argv[3]);
	char comand;
	int x_1, y_1;

	tipoCasilla **matriz = (tipoCasilla **) malloc((filas+50) * sizeof(tipoCasilla));
	
	for(int i=0;i<filas;i++){
		matriz[i] = (tipoCasilla *) malloc((cols+50) * sizeof(tipoCasilla));
		for(int h=0;h<cols;h++){
			matriz[i][h].etiqueta='*';
			matriz[i][h].tipo='c';
			matriz[i][h].nMinas= 0;
		}
	}
	//IniciarJuego(filas, cols, matriz);
	colocarMinas(filas, cols, m, matriz);
	indicarMinas(filas, cols,matriz); //Revisar por qué el programa colapsa al inicializar esta función.
	DibujarTablero(filas, cols, matriz);

	printf("\n\nEscriba el comando (e) para seleccionar la casilla, (f) para poner bandera y despues la coordenada de la casilla:\n");
	scanf("%c %i %i",&comand, &x_1, &y_1);

	inFraganti(filas,cols,matriz,x_1,y_1,comand);
	niggaPlay(filas, cols, comand,x_1,y_1,matriz);

}