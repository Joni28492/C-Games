/*
AUTOR: Jonathan Fernández López
fecha:
fuente: practica 2 Black Jack
sede: ESNE- Asturias- Oviedo

descripcion: 
	Juego de blackjack, este programa se trata de llegar lo mas cerca posible de 21 
	sin pasarse, aparecera un menu con las opciones de iniciar juego o salir,
	si se inicia se reparten 2 cartas a cada jugador y se distribuiran los turnos
	con las opciones de pedir carta, plantarse o salir
	si alguno se pasa de 21 se dara ganador automaticamente 
		*nota: este programa no tiene en cuenta el numero de cartas o que el maximo son 4 de cada numero



ultima revision: 17/01/2015
*/

#include<stdio.h>
#include<stdlib.h>
#define TAM 8

//inicializamos la matriz con valores a cero
void inicializaMano(int m[TAM]){

int i;
	
	for(i=0; i<TAM; i++)
		m[i]=0;
}


//mostrarmos todos los elementos de la matriz y separamos con una barra y un tabulador
void mostrarMano(int m[TAM]){

int i;
	
	for(i=0; i<TAM; i++)
	
		if(m[i]!=0)
		printf("%i|\t", m[i]);
		
		
	printf("que suman %i\n\n", sumaJugada(m));
	
	if(sumaJugada(m)>21)
	printf("te Has Pasao\n\n");
}

//si se pasa de 21 devolvemos 1 y sino 0
int teHasPasao(int m[TAM]){

	if(sumaJugada(m)>21)
		return 1;
	else
		return 0;
}

//inicializamos variable a cero y vamos sumando todos los elementos de la matriz
int sumaJugada(int m[TAM]){
	int i, res=0;
	
	for(i=0; i<TAM; i++)
		res+=m[i];
		
	return res;
}

//generamos un aleatorio
int aleatorio(){
	return rand()%10+1;
}



//pedimos una nueva carta para el primer elemento que encontremos a 0 en la matriz
void pedirCarta(int m[TAM]){

int i;

	for(i=0;i<TAM;i++){
	
		if(m[i]==0){
			m[i]=aleatorio();
			break;
		}
	}
}

//distribuimos todos los casos posibles de ganadores perdedores o empates
void Ganador(int m01[TAM], int m02[TAM], int m03[TAM]){
	
	int res;
	
	if(teHasPasao(m01)==0 && teHasPasao(m02)==1 && teHasPasao(m03)==1)
		printf("gana el jugador 1\n");
	if(teHasPasao(m01)==1 && teHasPasao(m02)==0 && teHasPasao(m03)==1)
		printf("gana el jugador 2\n");
	if(teHasPasao(m01)==1 && teHasPasao(m02)==1 && teHasPasao(m03)==0)
		printf("gana el jugador 3\n");
		
	if(teHasPasao(m01)==0 && teHasPasao(m02)==0){
		
		res=sumaJugada(m01)-sumaJugada(m02);
		
		if(res>0)
			printf("gana el jugador 1\n");
		if(res<0)
			printf("gana el jugador 2\n");
		if(res==0)
			printf("hay un empate entre los jugadores 1 y 2\n");		
	}
	
		if(teHasPasao(m02)==0 && teHasPasao(m03)==0){
		
		res=sumaJugada(m02)-sumaJugada(m03);
		
		if(res>0)
			printf("gana el jugador 2\n");
		if(res<0)
			printf("gana el jugador 3\n");
		if(res==0)
			printf("hay un empate entre los jugadores 2 y 3\n");		
		}
	
		if(teHasPasao(m01)==0 && teHasPasao(m03)==0){
		
		res=sumaJugada(m01)-sumaJugada(m03);
		
		if(res>0)
			printf("gana el jugador 1\n");
		if(res<0)
			printf("gana el jugador 3\n");
		if(res==0)
			printf("hay un empate entre los jugadores 1 y 3\n");		
		}
}

//funcion para los opciones de pedir carta plantarse o salir, y damos ganadores introduciendo la funcion anterior
void turnos(int mano01[TAM], int mano02[TAM], int mano03[TAM]){

	//variables para plantarse j1 y j2; s es para la opcion que escojamos del menu y la r es para
// cuando se rompa el bucle vayamos a los ganadores si no se ha salido de ka partida
int j1=0, j2=0, j3=0, r=0, s;
//iniciamos los turnos, utilizamos un bucle con un booleano(si es 0 es falso y si es 1 es cierto asi que el bucle se cumple siempre
	while(1){
		
		printf("\n\nTurno Jugador 1\n\n");
		//al ser la variable j1 o j2 igual a cero nos aseguramos de que si uno de los 2 se planta el siguiente 
		//tenga su turno
		if(j1==0){
			
			printf("\n\n1.\tPedir Carta\n\n2.\tPlantarse\n\n3.\tSalir\n\n");
			scanf("%i", &s);
			
			//evitamos datos malintencionados
			while(s<1 || s>3){
			printf("vuelve a introducir opcion: ");
			scanf("%i", &s);
			}
			
			if(s==1){
			pedirCarta(mano01);
			mostrarMano(mano01);
				if(teHasPasao(mano01)==1){
					break;
				
				}
			}
			
			//igualamos la variable j1 a 0 y asi puede seguir el jugador 2 hasta que salga se plante o se pase 
			if(s==2){
			j1=1;
			printf("jugador 1 te plantas con la siguiente mano\n\n");
			mostrarMano(mano01);
			printf("\n\ntu total es %i\n\n", sumaJugada(mano01));
			}
			
			//si nos salimos de la partida
			if(s==3){
			r=1;
			break;
			}
			
		}
		
		//mismo bloque de codigo que el anterior pero con en jugador 2
		if(j2==0){
			
			printf("\n\nTurno Jugador 2\n\n");
			
			printf("\n\n1.\tPedir Carta\n\n2.\tPlantarse\n\n3.\tSalir\n\n");
			scanf("%i", &s);
			
			while(s<1 || s>3){
			printf("vuelve a introducir opcion: ");
			scanf("%i", &s);
			}
			
			if(s==1){
			pedirCarta(mano02);
			mostrarMano(mano02);
			if(teHasPasao(mano01)==1){
					break;
				
				}
			}
			
			if(s==2){
			j2=1;
			printf("jugador 2 te plantas con la siguiente mano\n\n");
			mostrarMano(mano02);
			printf("\n\ntu total es %i\n\n", sumaJugada(mano02));
			}
		
			if(s==3){
			r=1;
			break;
			}
			
			if(j3==0){
				
			printf("\n\nTurno Jugador 3\n\n");
			
			printf("\n\n1.\tPedir Carta\n\n2.\tPlantarse\n\n3.\tSalir\n\n");
			scanf("%i", &s);
			
			//evitamos datos malintencionados
			while(s<1 || s>3){
			printf("vuelve a introducir opcion: ");
			scanf("%i", &s);
			}
			
			if(s==1){
			pedirCarta(mano03);
			mostrarMano(mano03);
				if(teHasPasao(mano03)==1){
					break;
				
				}
			}
			
			//igualamos la variable j1 a 0 y asi puede seguir el jugador 2 hasta que salga se plante o se pase 
			if(s==2){
			j3=1;
			printf("jugador 3 te plantas con la siguiente mano\n\n");
			mostrarMano(mano03);
			printf("\n\ntu total es %i\n\n", sumaJugada(mano03));
			}
			
			//si nos salimos de la partida
			if(s==3){
			r=1;
			break;
			}
			
		}
			
		}		
		
		//si ambos se plantan
		if(j1==1 && j2==1 && j3==1)
		break;
		
		//si uno de los 2 se sale de la partida
		if(teHasPasao(mano01)==1 && teHasPasao(mano02)==1)
			printf("gana el jugador 3");
		if(teHasPasao(mano02)==1 && teHasPasao(mano03)==1)
			printf("gana el jugador 1");
		if(teHasPasao(mano01)==1 && teHasPasao(mano03)==1)
			printf("gana el jugador 2");
	}
	
	//si ninguno se ha salido damos ganadores
	if(r==0)
	Ganador(mano01, mano02, mano03);

}




int main (){

srand(time(NULL));
	
int mano01[TAM], mano02[TAM], mano03[TAM];
int i;

//menu inicio
printf("\n\n1.\tIniciar Juego\n\n2.\tSalir");
scanf("%i", &i);



if(i==1){
inicializaMano(mano01);
inicializaMano(mano02);
inicializaMano(mano03);

//pedimos carta 2 veces por ser la primera mano
printf("\njugador 1\n\n");
pedirCarta(mano01);
pedirCarta(mano01);	
mostrarMano(mano01);

printf("\njugador 2\n\n");
pedirCarta(mano02);
pedirCarta(mano02);	
mostrarMano(mano02);

printf("\njugador 3\n\n");
pedirCarta(mano03);
pedirCarta(mano03);	
mostrarMano(mano03);
	
system("PAUSE");

turnos(mano01,mano02, mano03);
	
}
	

system("PAUSE");
}
