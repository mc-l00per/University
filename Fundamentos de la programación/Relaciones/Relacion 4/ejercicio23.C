
/**      
  * ejercicio23.cpp
  *
  * Copyright 2015 Antonio Rodríguez Alaminos <aralaminos@correo.ugr.es>
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation; either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program; if not, write to the Free Software
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
  * MA 02110-1301, USA.
  */


// DEPENDENCIAS DEL PROGRAMA.
#include <iostream> 	//para poder utilizar las entradas y salidas del codigo
#include <cctype>
#include <stdio.h> 		//para el system pause articial
#include <stdlib.h> 	//dependencia para las llamadas system de windows
#include <unistd.h> 	//para poder utilizar el usleep y otros comandos
using namespace std;


// DECLARACIÓN DE VARIABLES GLOBALES

//CLASES
class Numero{
	private:
		int valor;
		int posicion_x, posicion_y;
	public:
		/*Numero(int p_valor, int p_posicion_x, int p_posicion_y){
			valor = p_valor;
			posicion_x = p_posicion_x;
			posicion_y = p_posicion_y;
		}*/
		void SetValor(int p_valor){
			valor = p_valor;
		}
		int GetValor(){
			return valor;
		}
		void SetPosicion(int p_posicion_x, int p_posicion_y){
			posicion_x = p_posicion_x;
			posicion_y = p_posicion_y;
		}
		int GetPosicionX(){
			return posicion_x;
		}
		int GetPosicionY(){
			return posicion_y;
		}
		void MostrarPosicion(){
			cout << "(" << posicion_x << "," << posicion_y << ")";
		}
};

//FUNCIONES
/**
 * Introducción personal al programa
 * @see Inicio
 */
void Inicio(){
	cout << "\t                                              ____   ___" << endl 
		<< "\t  /\\   /\\    ____    /\\   /\\  _____   ___.__. \\   \\ /  /" << endl
		<< "\t /  \\ /  \\ _/ ___\\  /  \\ /  \\ \\__  \\ <   |  |  \\      /" << endl
		<< "\t/    Y    \\\\  \\___ /    Y    \\ / __ \\_\\___  |  /      \\" << endl
		<< "\t\\_/\\___/\\_/ \\___  >\\_/\\___/\\_/(____  // ____| /___/\\   \\" << endl
		<< "\t                \\/                 \\/ \\/            \\__/" << endl << endl
		<< "                           \\ ||| /" << endl
		<< "     .-.________            (o o)                      ________.-." << endl
		<< "----/ \\_)_______)   +--oooO-----------------------+   (_______(_/ \\----" << endl
		<< "   (     ()___)     |                             |      (___()    )" << endl
		<< "         ()__)      |       EJERCCICIO: 23        |       (__()" << endl
		<< " ----\\___()_)       |                             |        (_()___/---" << endl
		<< "                    +-----------------Ooo---------+" << endl;
	usleep(2000000);
	system("clear");
}

/**
 * Pausa del sistema, mas intro para continuar
 * @see Pausa
 */
void Pausa(){
	cin.ignore(256,'\n');
	cout << "\n\nPress 'Enter' to continue: ... ";
	while ( getchar() != '\n');
}

/**
 * Salida personal del programa
 * @see Fin
 */  
void Fin(){
	Pausa();
	system("clear");
	cout << endl << endl << "\t@@@@@@@  @@@  @@@  @@@@@@@@     @@@@@@@@  @@@  @@@  @@@@@@@" << endl
		<< "\t@@@@@@@  @@@  @@@  @@@@@@@@     @@@@@@@@  @@@@ @@@  @@@@@@@@" << endl
		<< "\t  @@!    @@!  @@@  @@!          @@!       @@!@!@@@  @@!  @@@" << endl
		<< "\t  !@!    !@!  @!@  !@!          !@!       !@!!@!@!  !@!  @!@" << endl
		<< "\t  @!!    @!@!@!@!  @!!!:!       @!!!:!    @!@ !!@!  @!@  !@!" << endl
		<< "\t  !!!    !!!@!!!!  !!!!!:       !!!!!:    !@!  !!!  !@!  !!!" << endl
		<< "\t  !!:    !!:  !!!  !!:          !!:       !!:  !!!  !!:  !!!" << endl
		<< "\t  :!:    :!:  !:!  :!:          :!:       :!:  !:!  :!:  !:!" << endl
		<< "\t   ::    : :  :::  :: ::::      :: ::::   ::   ::   ::::  ::" << endl
		<< "\t   :      :   : :  : :: ::      : :: ::   ::   :    :: : :" << endl << endl << endl;
	usleep(2000000);	
	exit(0);
}

int main() {
	// PORTADA DE INICIO DEL EJERCICIO.
	Inicio();

	// DECLARACIÓN DE VARIABLES LOCALES
	int fil_matiz, col_matriz, entero;
	/*
		//parte A
		// ENTRADA DE DATOS DEL PROGRAMA
		cout << "Parte A del ejercicio." << endl;
		cout << "Introduce cuantas filas tendra la matriz: ";
		cin >> fil_matiz;
		cout << "Introduce cuantas columnas tendra la matriz: ";
		cin >> col_matriz;
		Numero matriz_a[fil_matiz][col_matriz];
		for(int i=0; i<fil_matiz; i++)
			for(int j=0; j<col_matriz; j++){
				cin >> entero;
				matriz_a[i][j].SetValor(entero);
				matriz_a[i][j].SetPosicion(i,j);
			}

		// CUERPO DEL PROGRAMA 
		Numero matriz_aux[fil_matiz][col_matriz];
		for(int i=fil_matiz - 1, z=0; i>=0; z++, i--)
			for(int j=col_matriz - 1, x=0; j>=0; x++, j--){
				matriz_aux[z][x] = matriz_a[i][j];
			}
		//SALIDA DE DATOS
		for(int  i=0; i<fil_matiz; i++){
			for(int j=0; j<col_matriz; j++)
				cout << "   " << matriz_a[i][j].GetValor();
			cout << endl;
		}
		for(int  i=0; i<fil_matiz; i++){
			for(int j=0; j<col_matriz; j++)
				cout << "   " << matriz_aux[i][j].GetValor();
			cout << endl;
		}
	*/
	//parte  B
	// ENTRADA DE DATOS DEL PROGRAMA
	Pausa();
	system("clear");
	cout << "Parte B del problema" << endl;
	cout << "Introduce cuantas filas tendra la matriz: ";
	cin >> fil_matiz;
	cout << "Introduce cuantas columnas tendra la matriz: ";
	cin >> col_matriz;
	Numero matriz_b[fil_matiz][col_matriz];
	for(int i=0; i<fil_matiz; i++)
		for(int j=0; j<col_matriz; j++){
			cin >> entero;
			matriz_b[i][j].SetValor(entero);
			matriz_b[i][j].SetPosicion(i,j);
		}

	// CUERPO DEL PROGRAMA 
	Numero menor[col_matriz], mayor;
	for(int  i=0; i<fil_matiz; i++){
		for(int j=0; j<col_matriz; j++)
			cout << "   " << matriz_b[i][j].GetValor();
		cout << endl;
	}
	for(int i=0; i<fil_matiz; i++)
		for(int j=0; j<col_matriz; j++)
			if(j == 0)
				menor[i] = matriz_b[i][j];
			else if(menor[i].GetValor() > matriz_b[i][j].GetValor())
				menor[i] = matriz_b[i][j];
	for(int i=0; i<fil_matiz; i++)
		if(i == 0)
			mayor = menor[i];
		else if(mayor.GetValor() < menor[i].GetValor())
			mayor = menor[i];
	
	// SALIDA DE DATOS
	cout << "El mayor valor, de todos los minimos por fila es: " << mayor.GetValor() << endl << "Posición: ";
	mayor.MostrarPosicion();
/*
	//parte  C
	// ENTRADA DE DATOS DEL PROGRAMA
	Pausa();
	system("clear");
	cout << "Parte B del problema" << endl;
	cout << "Introduce cuantas filas tendra la matriz: ";
	cin >> fil_matiz;
	cout << "Introduce cuantas columnas tendra la matriz: ";
	cin >> col_matriz;
	Numero matriz_c[fil_matiz][col_matriz];
	for(int i=0; i<fil_matiz; i++)
		for(int j=0; j<col_matriz; j++){
			cin >> entero;
			matriz_c[i][j].SetValor(entero);
			matriz_c[i][j].SetPosicion(i,j);
		}

	// CUERPO DEL PROGRAMA 
	Numero menorc[col_matriz], mayorc[fil_matiz];
	int tamanio_maxmin, total_maxmin = 0;
	if(fil_matiz >= col_matriz)
		tamanio_maxmin = fil_matiz;
	else
		tamanio_maxmin = col_matriz;
	Numero maxmin[tamanio_maxmin];
	bool hay_maximin = false;
	for(int i=0; i<fil_matiz; i++)
		for(int j=0; j<col_matriz; j++){
			if(j == 0)
				mayorc[i] = matriz_c[i][j];
			else if(mayorc[i].GetValor() < matriz_c[i][j].GetValor())
				mayorc[i] = matriz_c[i][j];
		}
	for(int j=0; j<col_matriz; j++)
		for(int i=0; i<fil_matiz; i++){
			if(i == 0)
				menorc[j] = matriz_c[i][j];
			else if(menorc[j].GetValor() > matriz_c[i][j].GetValor())
				menorc[j] = matriz_c[i][j];
		}
	for(int i=0; i<fil_matiz; i++)
		for(int j=0; j<col_matriz; j++){
			if(mayorc[i].GetPosicionX() == menorc[j].GetPosicionX() && mayorc[i].GetPosicionY() == menorc[j].GetPosicionY() && mayorc[i].GetValor() == menorc[i].GetValor()){
				hay_maximin = true;
				maxmin[total_maxmin] = mayorc[i];
				total_maxmin++;
			}
		}
	if(hay_maximin)
		for(int i=0; i<total_maxmin; i++){
			cout << "\nEl valor maxmin en la posicion ";
			maxmin[i].MostrarPosicion();
			cout << " es: " << maxmin[i].GetValor();
		}
	else
		cout << "\nNo hay maxMin." << endl;

	//parte  D*//*
	// ENTRADA DE DATOS DEL PROGRAMA
	Pausa();
	system("clear");
	cout << "Parte B del problema" << endl;
	cout << "Introduce cuantas filas tendra la matriz: ";
	cin >> fil_matiz;
	cout << "Introduce cuantas columnas tendra la matriz: ";
	cin >> col_matriz;
	Numero matriz_d[fil_matriz][col_matriz];
	for(int i=0; i<fil_matiz; i++)
		for(int j=0; j<col_matriz; j++){
			cin >> entero;
			matriz_d[i][j].SetValor(entero);
			matriz_d[i][j].SetPosicion(i,j);
		}
	system("clear");
	int col_matriz_aux = fil_matriz;
	int fil_matriz_aux = col_matriz;
	Numero matriz_d_aux[col_matriz_aux][fil_matriz_aux];
	for(int i=0; i<fil_matiz_aux; i++)
		for(int j=0; j<col_matriz_aux; j++){
			cin >> entero;
			matriz_d_aux[i][j].SetValor(entero);
			matriz_d_aux[i][j].SetPosicion(i,j);
		}

	// CUERPO DEL PROGRAMA 
	int valor, multiplicador_tmp;
	int matriz_resultante[fil_matriz][col_matriz];
	for(int i=0; i<fil_matiz; i++){
		for(int j=0; j<col_matriz; j++){
			for(int x=0; x<fil_matriz_aux; x++){
				for(int y=0; y<col_matriz_aux; y++){

				}
			}
		}
	}*/
	// FINAL Y PAUSA DEL SISTEMA.
	Fin();
}

 
