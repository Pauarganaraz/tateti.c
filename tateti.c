#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#include <time.h>

	/*
		Requisitos:
			Mostrar info del juego al principio
			Mostrar el tablero
			Juego es por turnos
				Verifique el movimiento
				Diferenciar jugadores
				Información actual de cada turno
			REcibir nombres
			Verificar si alguno logró el 3 en línea
				Informar situación final
					Gano X o O
					En caso de empate
				Verificar a partir del 5to turno inclusive
				En caso de empate
					Debería terminar
					(extra)* debería comenzar otra ronda
					(extra)* deber+ia definirse al ganador con un juego de piedra papel o tijera
			Comienza inicialmente con X o O
			Informar errores
			Crear un bot cpmp segundo jugador (el jugador 1 es el usuario)

	*/



#define NOMBRE_JUEGO "tateti"

#define MAX_NOMBRE 100

#define NOMBRE_DEF_JUG_A "def nombre A"
#define NOMBRE_DEF_JUG_B "def nombre B"
#define NOMBRE_DEF_JUG_ACT "def jugador actual"


#define INFO_INICIAL_JUEGO_PART1 "\t\tjuego de tablero con 9 casillas \n\t\tCada jugador solo debe colocar su simbolo una vez por turno y no debe ser sobre una casilla ya jugada"
#define INFO_INICIAL_JUEGO_PART2 "\t\tSe debe conseguir realizar una linea recta o diagonal por simbolo"

#define MAX_FILA 3
#define MAX_COL 3
#define MAX_TURNOS MAX_FILA*MAX_COLUM
const int MAX_VERIF_DIAGONAL = 2;
const int TURNO_EMPEZAR VERIF = 5;

const int FILA_DEF = -1;
const int COL_DEF = -1;

const char SIMB_JUGADOR_A = 'X';
const char SIMB_JUGADOR_B = 'O';
#define SIM_VACIO ''
const char SIMB_JUGADOR_INICIAL_DEF = SIMB_JUGADOR_A;
const int NUM_CARACTER_VACIO = 0;

const int MOVIMIENTO_INVALIDO = 0;
const int MOVIMIENTO_VALIDO = 1;


const int NO_GANO =0;
const int SI_GANO =1;


#define SIN_ERROR 0
#define ERROR_TAMANIO 1
#define ERROR_CASILLA_OCUPADA 2

/*
	Descripción: Recibir los nombres de los jugadores
	Pre: "nombreJugadorA" y "nombreJugadorB" correctamente definidos  asignados
	Post: Asigna los nuevos nombres a "nombreJugadorA" y "nombreJugadorB"
*/
void recibirNombresJugadores (char nombreJugadorA [MAX_NOMBRE], char nombrejugadorB[MAX_NOMBRE]){
	printf(" Ingrese nombre de jugador A\n");
	scanf ( "%s" , nombreJugadorA );
	printf("Ingrese nombre de jugador B\n");
	scanf ( "%s , nombreJugadorB );
	printf("Nombres asignados ...\n");
}"


/*	
	Descripción: Muestra la presentacion del juego
	Pre: "nombreJugadorA" y "nombreJugadorB" correctamente definidos y asignados con los nombres
		de los jugadores actuales
	Post: Muestra el "NOMBRE_JUEGO", información del juego y los nombres de los jugadores actuales
*/
void presentarJuego (char nombreJugadorA [MAX_NOMBRE], char nombrejugadorB [MAX_NOMBRE]){
	printf("\n\n\t\t***%s***\n\n" , NOMBRE_JUEGO);
	printf("%s\nInfo del juego:\n");
	printf("%s\n", INFO_INICIAL_JUEGO_PART1);
	printf("%s\n\n", INFO_INICIAL_JUEGO_PART2);
	printf("Jugadores: %s y %s\n", nombreJugadorA , nombrejugadorB );
}


/*
	Descripción: muestra el tablero actualizado
	Pre: "tablero" correctamente definido y asignado con valores actuales correspondientes
	Post: muestra el tablero con los valores actuales
*/
void mostrarTablero (char tablero [MAX_FILA] [MAX_COLUM]){
	printf("\t\t 0  1  2 \n");
	for( int fila = 0; fila < MAX_FILA ; fila++) {
		printf("\t\t%i ", fila++);
		for (int col = 0; col <MAX_COLUM ; col++){
			printf("[%c] ", tablero [fila][col] );
		}
		printf("\n\n");
	}
}	

/*
	Descripcion: solicitamos el movimiento del usuario
	Pre: "fila" y "col" correctamente definidos y asignados
	Post: recibe nuevos valores para "fila" y "col"
*/
void recibirMovimientoUsuario (int *fila , int *col){
	printf("ingrese fila\n");
	scanf ("%i", fila);
	printf ("ingrese columna\n");
	scanf ("%i , col");
}

/*
	Descripción: recibimos el movimiento del bot
	Pre: "fila" y "col" correctamente definidos y asignados
	Post: se genera posiciones aleatorias para "fila" y "col"
*/
void recibirMovimientoBot (int *fila, int *col){



*fila = rand () % MAX_FILA;
*col = rand () %MAX_COLUM;
}

/*
	DEscripcion: informar el error detectado
	Pre: "tipoError" correctamente definido y actualizado
	Post: informa "tipoError" detectado mediante consola
*/
void infomarError (int tipoError){
	printf("Error": "" );
	switch (tipoError){
		case ERROR_TAMANIO
			printf("posicion invalida\n");
			break;
		case ERROR_CASILLA_OCUPADA
			printf("casilla ocupada\n");
	}
}



/*
	Descripcion verifica la casilla del movimiento al ingresar
	Pre: "tablero", "tipoError", "fila" y "col" correctamente definidos y actualizados
	Post: devuelve "MOVIMIENTO_INVALIDO" si la casilla esta ocupada, caso contrario devuelve "MOVIMIENTO_VALIDO"
		actualiza "tipoError" con "ERROR_CASILLA-OCUPADA" si se detecta un error
*/
int verificarCasillaOcupada (char tablero [MAX_FILA] [MAX_COLUM], int "tipoError", int fila, int col){
	int validacionMovimiento = MOVIMIENTO_INVALIDO

	if (tablero [fila][col] == NUM_CARACTER_VACIO){
		validacionMovimiento =MOVIMIENTO_VALIDO;
	}else{
		tipoError = ERROR_CASILLA-OCUPADA;
	} 
	
	return validacionMovimiento;	
}


/*
	Descripción: verifica si el movimiento es valido
		Es válido si: 
			-la posicion esta dentro del "tablero"
			-la posición NO contiene un valor "SIM_JUGADOR_A" y "SIM_JUGADOR_B"
	Pre: "fila" y "col" corresponden al movimiento ingresado por el jugador
		"tablero" correctamente definido y actualizado
	Post: Verifica si el movimiento es valido 
		Si el movimiento es valido devuelvo el valor de "MOVIMIENTO_VALIDO" caso
	contrario devuelvo "MOVIMIENTO_INVALIDO"
*/
int verificarMovimiento (int *fila, int *col, char tablero[MAX_FILA][MAX_COLUM]) {
	int validacionMovimiento = MOVIMIENTO_INVALIDO;
	int tipoError = SIN_ERROR; 
	if( (*fila >=0 && *fila <MAX_FILA) && ( *col >=0 && *col < MAX_COLUM) ) {
			validacionMovimiento = verificarCasillaOcupada ( tablero, tipoError, fila, col);
	}else{
			tipoError = ERROR_TAMANIO;
	}
		if (tipoError){
			infomarError (tipoError);
		}
		return validacionMovimiento;
	}



	/*
		Descripcion: solicitamos el movimiento del jugador actual
		Pre: "simActual" y "tablero" correctamente definidos y actualizados
		Post: solicita y asigna el movimiento del jugador en "fila" y "col"
	*/
void recibirMovimiento (char simActual , int *fila, int *col, char tablero [MAX_FILA][MAX_COLUM]){
	do {
			if(simActual == SIM_JUGADOR_A){
			recibirMovimientoUsuario (fila, col);
			}else{
			recibiMovimientoBot (fila, col);
		}
	}while (!verificarMovimiento (fila, col, tablero ) );
}



/*
	Descripción: cambia de simbolo al correspondiente del siguiente jugador
	Pre: "simActual" debe corresponder al simbolo del jugador actual en el juego
	Post: devuelve el "simActual" del siguiente jugador
*/
	char alternarTurno (char simActual){
		if (simActual == SIM_JUGADOR_A){
			simActual = SIM_JUGADOR_B;
		}else{
			simActual = SIM_JUGADOR_A;
		}
		return simActual;
	}

/*
	descripción: muestra la información del turno
	Pre: "turnoActual" , "simActual" y "nombreJugadorActual" correctamente asignados
	Post: muestra mediante consola la información del turno actual
*/
	void mostrarInfoTurno (int turnoActual, char simActual, char nombreJugadorActual [MAX_NOMBRE]){
		printf("\n\tTurno numero: %i\n, turnoActual+1");
		printf("\tJugador Actual: %s [%c] \n\n" nombreJugadorActual, simActual);
	}


/*
		Descripción: seleccionar el nombre del jugador actual
		Pre: "simActual" , "nombreJugadorActual" , "nombreJugadorA" y "nombrejugadorB correctamente asignados y definidos
		Post: copia el nombre del jugador actual en el turno actual a "nombreJugadorActual"
*/
void seleccNombreJugadorActual (char simActual, char nombreJugadorActual [MAX_NOMBRE], char nombreJugadorA [MAX_NOMBRE]){
	if (simActual == SIM_JUGADOR_A){
		strcpy (nombreJugadorActual, nombreJugadorA);
	}else{
		strcpy (nombreJugadorActual, nombreJugadorB);
	}
}
	
/*
	Descripcion verifica el 3 en linea horizontal
	Pre: "tablero" y "simActual" correctamente definidos y actualizados
	Post: devuelve "SI_GANO" si se logro un 3 en linea horizontal, caso contrario devuelve "NO_GANO"
*/
int verificacionHorizontal (char tablero [MAX_FILA] [MAX_COLUM], char simActual){
	int estadoGano = NO_GANO;
	for (int verHor = 0; verHor < MAX_FILA ; verHor++){
			if ( tablero [verHor] [0] == simActual && tablero [verHor][1] == simActual && tablero [verHor] [2] == simActual){
				estadoGano = SI_GANO;
				verHor = MAX_FILA;
			}
	}
	return estadoGano;			
}

/*
	Descripcion: verifica el 3 en linea vertical
	Pre "tablero" y "simActual" correctamente definidos y actualizados
	Post: devuelve "SI_GANO" si se logro un 3 en linea vertical, caso contrario devuelve "NO_GANO"
*/
int verificacionVertical (char tablero [MAX_FILA] [MAX_COLUM] , char simActual){
	int estadoGano = NO_GANO;
	for (int verVer = 0; verVer < MAX_COLUM; verVer++){
		if (tablero [0] [verVer] == simActual && tablero [1] [verVer] == simActual && tablero [2] [verVer] == simActual){
			estadoGano = SI_GANO;
			verVer = MAX_COLUM;
		}
	}
	return estadoGano;
}



/*
	Descripcion: verifica el tres en linea en diagonal
	Pre: "tablero" y "simActual" correctamente definidos y actualizados
	"estadoGano" apunta a la variable que contiene el estado si gano alguien
	Post: actualiza el valor "estadoGano" al "SI_GANO" si se logro un 3 en linea
	diagonal caso constrario actualiza a "NO_GANO"
*/
void verificacionDiagonal (char tablero [MAX_FILA][MAX_COLUM], char simActual, int estadoGano){
	for (int verDiag = 0; verDiag <= MAX_VERIF_DIAGONAL ; verDiag += 2;){
		if (tablero [verDiag] [0] == simActual && tablero [1][1] == simActual && tablero [(2 = verDiag)][2] == simActual){
			estadoGano = SI_GANO;
			verDiag = MAX_VERIF_DIAGONAL;
		}
	}
}


/*
	Descripcion: verifica si algun jugador gano/ realizo 3 en linea
	Pre: "tablero" y "simActual" correctamente definidos y actualizados
		"estadoGanoJuego" correctamente definido y apunta a la variable que contiene el estado del juego
	Post: devuelve "SI_GANO" si se logra verificar un tres en linea, caso contrario vuelve a "NO_GANO"
		actualiza "estadoGanoJuego" con el valor de "estadoGano"
*/
int VerificarGanoJugador (char tablero [MAX_FILA][MAX_COLUM], char simActual, int estadoGanoJuego){
	int estadoGano = NO_GANO;
	estadoGano = verificacionHorizontal (tablero. simActual);
	if (estadoGano) {
		estadoGano = verificacionVertical (tablero, simActual);
	}
	if (estadoGano){
		verificacionDiagonal (tablero, simActual, &estadoGano);
	}
	estadoGanoJuego = estadoGano;
	return estadoGano;
}

/*
	Descripcion: informa la situacion final del juego
	Pre: "nombreJugadorA", "tablero" "estadoGanoJuego" correctamente definido y actualizado
	Post: informar la situacion final del juego
*/
void informarSituacionFinal (char nombreJugadorActual [MAX_NOMBRE], char tablero [MAX_FILA] [MAX_COLUM], int estadoGanoJuego){
	if (estadoGanoJuego){
		printf("Jugador %s GANO!\n", nombreJugadorActual);
	}else{
		printf("EMPATE!!\n");
	}
	mostrarTablero (tablero);
	printf("Gracias por jugar!\n", );
}


/*
	Descripcion: evaluamos la situacion del turno
	Pre: "turnoActual", "tablero", "simActual" y "estadoGanoJuego" correctamente definidos y actualizados
	Post: Dependiendo de la situacion del turno actual:
		-alternar los turnos
		-verificar si algun jugador gano
		-actualizar "turnoActual" si algun jugador gano
*/
void evaluarSituacionTurno (int turnoActual , char tablero [MAX_FILA] [MAX_COLUM] , char simActual, int estadoGanoJuego){
	if ((("turnoActual+1">= TURNO_EMPEZAR_VERIFICAR) && VerificarGanoJugador (tablero, simActual, estadoGanoJuego)){
		turnoActual = MAX_TURNOS;
	}else{
		simActual = alternarTurno (simActual);
	}
}


/*
	Descripcion: inicia el juego hasta que se define un final
	Pre: "tablero", "nombreJugadorA" , "nombreJugadorB" correctamente definidos y actualizado
	Post: iniciamos el juego implementando los requisitos establecidos
*/
void iniciarJuego (char tablero [MAX_FILA] [MAX_COLUM], char nombreJugadorA [MAX_NOMBRE], char nombrejugadorB [MAX_NOMBRE]){
	char simActual = SIMB_JUGADOR_INICIAL_DEF;
	int fila = FILA_DEF;
	int col = COL_DEF;
	char nombreJugadorActual [MAX_NOMBRE] = NOMBRE_DEF_JUG_ACT;
	int estadoGanoJuego = NO_GANO;

	for (int turnoActual = 0; turnoActual < MAX_TURNOS ; turnoActual++){
		seleccNombreJugadorActual (turnoActual, simActual, nombreJugadorActual);
		mostrarInfoTurno (turnoActual, simActual, nombreJugadorActual);
		mostrarTablero (tablero);
		recibirMovimiento (simActual, &fila, &col, tablero);
		tablero [fila][col] = simActual;
		evaluarSituacionTurno (&turnoActual, tablero, &simActual, &estadoGanoJuego);
	}
	informarSituacionFinal (nombreJugadorActual, tablero, estadoGanoJuego);
}


int main(){

	srand (time (NULL));

	char tablero [MAX_FILA][MAX_COLUM]= {};

	char nombreJugadorA [MAX_NOMBRE] = NOMBRE_DEF_JUG_A;
	char nombrejugadorB [MAX_NOMBRE] = NOMBRE_DEF_JUG_B;

	recibirNombresJugadores (nombreJugadorA, nombrejugadorB);
	presentarJuego (nombreJugadorA, nombrejugadorB);

	iniciarJuego (nombreJugadorA, nombreJugadorB);
	
	return 0;
}
