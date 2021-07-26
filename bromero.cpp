#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <conio.h>
//Braulio Julián Romero - Ejercicio 11 - Actividad Unidad 5
using namespace std;
// Clase Tablero de Tateti
class Tablero{
public:
	Tablero(){};
	int matriz[3][3];
	void iniciar(int mat[][3]);
	void mostrar(int mat[][3]);
	
};
// Clase Juego
class Juego{
	Tablero Tablero1;
public:
	int ingresar(int col_o_fil);
	void play();
	void cabecera();
	void set_tablero(int tablero[][3],int columna,int fila,int jugador);
	int check_usado(int tablero[][3],int columna,int fila);
	int check_gana_jugador_1(int A[][3]);
	int check_gana_jugador_2(int A[][3]);
};
int Juego::check_gana_jugador_1(int A[][3]){
	if(((A[0][0]==1)&&(A[0][1]==1)&&(A[0][2]==1))||((A[1][0]==1)&&(A[1][1]==1)
		&&(A[1][2]==1))||((A[2][0]==1)&&(A[2][1]==1)&&(A[2][2]==1)))
		return 1;
	else if(((A[0][0]==1)&&(A[1][0]==1)&&(A[2][0]==1))||((A[0][1]==1)&&(A[1][1]==1)
		&&(A[2][1]==1))||((A[0][2]==1)&&(A[1][2]==1)&&(A[2][2]==1)))
		return 1;
	else if(((A[0][0]==1)&&(A[1][1]==1)&&(A[2][2]==1))||((A[0][2]==1)
		&&(A[1][1]==1)&&(A[2][0]==1)))
		return 1;
	else return 0;
}
void Tablero::iniciar(int mat[][3]){
	int i, j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			mat[i][j] = 0;
		}
		cout <<endl;
	}
}
void Tablero::mostrar(int mat[][3]){
	int i, j;
	cout <<endl;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(mat[i][j] == 0){
				cout <<" |"<<"*"<<"|";
			}
			if(mat[i][j] == 1){
				cout <<" |"<<"X"<<"|";
			}
			if(mat[i][j] == 2){
				cout <<" |"<<"O"<<"|";
			}
		}
		cout <<endl;
	}
}
int Juego::check_gana_jugador_2(int A[][3]){
	if(((A[0][0]==2)&&(A[0][1]==2)&&(A[0][2]==2))||((A[1][0]==2)&&(A[1][1]==2)
		&&(A[1][2]==2))||((A[2][0]==2)&&(A[2][1]==2)&&(A[2][2]==2)))
		return 1;
	else if(((A[0][0]==2)&&(A[1][0]==2)&&(A[2][0]==2))||((A[0][1]==2)&&(A[1][1]==2)
		&&(A[2][1]==2))||((A[0][2]==2)&&(A[1][2]==2)&&(A[2][2]==2)))
		return 1;
	else if(((A[0][0]==2)&&(A[1][1]==2)&&(A[2][2]==2))||((A[0][2]==2)&&(A[1][1]==2)
		&&(A[2][0]==2)))
		return 1;
	else return 0;
}
void Juego::set_tablero(int tablero[][3],int columna,int fila,int jugador){
	if(jugador == 1){
		tablero[fila-1][columna-1] = 1;
	}else{
		tablero[fila-1][columna-1] = 2;
	}
}
int Juego::ingresar(int col_o_fil){
	int col=0;
	int fil=0;
	bool vale=false;
	
	while (!vale){
		
		if(col_o_fil == 0){
			cout<<endl<<"-Ingrese el nro de columna en el cual quire ingresar el valor (1-3): ";
			cin>>col;
			if(col>0 && col<4){
				vale=true;    
			}else{
				cout<<endl<<"Error, ingrese nuevamente"<<endl;
			}
		}else{
			cout<<endl<<"-Ingrese el nro de fila en el cual quire ingresar el valor (1-3): ";
			cin>>fil;
			if(fil>0 && fil<4){
				vale=true;    
			}else{
				cout<<endl<<"Error, ingrese nuevamente"<<endl;
			}
		}
	}
	if(col_o_fil == 0){
		return col;
	}else{
		return fil;
	}
	
}
int Juego::check_usado(int mat[][3],int col,int fil){
	if(mat[fil-1][col-1] != 0){
		return 1;
	}else{
		return 0;
	}
}
void Juego::cabecera(){
	cout<<"=====| Bienvenido al juego del TA-TE-TI |====="<<endl<<endl;
	cout<<"Juegador 1 = X"<<endl;
	cout<<"Juegador 2 = O"<<endl<<endl;
}
//Función donde se ejecuta la lógica principal del Juego
void Juego::play(){	
	int c=0;
	int f=0;
	int usado=0;
	int J1=0;
	int J2=0;
	int movimientos = 0;
	Tablero1.iniciar(Tablero1.matriz);
	cabecera();
	Tablero1.mostrar(Tablero1.matriz);
	// Primer Jugador
	while((J1!=1)&&(J2 !=1)&&(movimientos<=5)){
		cout<<endl<<"Turno Jugador Número 1: "<<endl;
		c = ingresar(0);
		f = ingresar(1);
		usado = check_usado(Tablero1.matriz,c,f);
		while (usado==1){
			cout<<endl<<"Error, esa posición ya está usada!"<<endl;
			c = ingresar(0);
			f = ingresar(1);
			usado = check_usado(Tablero1.matriz,c,f);
		}
		set_tablero(Tablero1.matriz,c,f,1);
		Tablero1.mostrar(Tablero1.matriz);
		movimientos += 1;
		J1 = check_gana_jugador_1(Tablero1.matriz);
		if(J1 == 1 || movimientos > 5){
			break;
		}
		// Segundo Jugador
		cout<<endl<<"Turno Jugador Número 2: "<<endl;
		c = ingresar(0);
		f = ingresar(1);
		usado = check_usado(Tablero1.matriz,c,f);
		while (usado==1){
			cout<<endl<<"Error, esa posición ya está usada!"<<endl;
			c = ingresar(0);
			f = ingresar(1);
			usado = check_usado(Tablero1.matriz,c,f);
		}
		set_tablero(Tablero1.matriz,c,f,2);
		Tablero1.mostrar(Tablero1.matriz);
		J2 = check_gana_jugador_2(Tablero1.matriz);
		if(J2 == 1){
			break;
		}
	}
	if(J1==1){
		cout <<endl <<"TA-TE-TI!!" <<endl;
		cout <<endl <<"El Jugador 1 es el que Gana!!!" <<endl;
	}else{
		if(J2==1){
			cout <<endl <<"TA-TE-TI!!" <<endl;
			cout <<endl <<"El Jugador 2 es el que Gana!!!" <<endl;
		}else{
			cout <<endl <<"Es un Empate!!";
		}
	}
}
int main(int argc, char *argv[]){
	srand (time(NULL));
	Juego J;
	J.play();
	return EXIT_SUCCESS;
}
	
