/**
 * /////////////////////////////////////////////////////////////////////////
 * // programa para corregir un sudoku
 * // @author Antonio Rodríguez Alaminos
 * /////////////////////////////////////////////////////////////////////////
 */

////////////////////////////////////////////////////////////////////////////
// DEPENDENCIAS NECESARIAS PARA LA APLICACIÓN
////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <unistd.h>
using namespace std;

////////////////////////////////////////////////////////////////////////////
// VARIABLES GLOBALES DE LA APLICACIÓN
////////////////////////////////////////////////////////////////////////////
const int FIL = 3;
const int COL = 3;
const int FIL_REGION = 3;
const int COL_REGION = 3;
struct Contador{
	int valor;
	bool presente;
};


////////////////////////////////////////////////////////////////////////////
// CLASES DE LA APLICACIÓN
////////////////////////////////////////////////////////////////////////////
/**
 * Clase con la informacion de una region
 * @see Region
 */
class Region{

	private:
		int region[FIL_REGION][COL_REGION];

	public:
		/**
		 * Constructor por defecto
		 * @see Region
		 */
		Region() {}
		/**
		 * Almacenar valor en una posicion concreta
		 * @see InsertarValores()
		 * @param valor valor que queremos almacenar
		 * @param fil posicion de la fila donde insertaremos el valor
		 * @param col posicion de la columna donde insertaremos el valor
		 */
		void InsertarValores(int valor, int fil, int col){
			//cout << fil << " " << col << "\t" << valor << endl;
			region[fil][col] = valor;
		}
		/**
		 * muestra el valor de una posicion concreta
		 * @see MostrarValor
		 * @param fil posicion de la fila donde insertaremos el valor
		 * @param col posicion de la columna donde insertaremos el valor
		 */
		int MostrarValor(int fil,  int col){
			return region[fil][col];
		}
};

////////////////////////////////////////////////////////////////////////////

/**
 * Clase que contiene todas las propiedades del sudoku
 * @see Sudoku
 */
class Sudoku{
	
	private:
		Region sudoku[FIL][COL];
		Contador vector_contador[9];

	public:
		Sudoku(){}
		void InsertarValores(int valor, int fil_sud, int col_sud, int fil_reg, int col_reg){
			//cout << fil_sud << " " << col_sud << " " << fil_reg << " " << " " << col_reg << "\t" <<  valor << endl;
			sudoku[fil_sud][col_sud].InsertarValores(valor, fil_reg, col_reg);
			//cout << sudoku[fil_sud][col_sud].MostrarValor(fil_reg, col_reg) << endl;
		}
		int MostrarValor(int fil_sud, int col_sud, int fil_reg, int col_reg){
			return sudoku[fil_sud][col_sud].MostrarValor(fil_reg, col_reg);
		}
		void InitContador(){
			for(int i=0; i<9; i++){
				vector_contador[i].valor = i+1;
				vector_contador[i].presente = false;
			}
		}
		void ResetContador(){
			for(int i=0; i<9; i++){
				vector_contador[i].presente = false;
			}
		}
		bool Comprobar(){
			int valor_aux;
			bool error = false;

			InitContador();

			cout << "\ntabla de presentes filas:" << endl << endl << flush;
			for(int i=0; i<FIL; i++){
				for(int x=0; x<FIL_REGION; x++){
					for(int j=0; j<COL; j++)
						for(int y=0; y<COL_REGION; y++){
							valor_aux = MostrarValor(i, j, x, y);
							for(int contador=0; contador<9; contador++)
								if(valor_aux == vector_contador[contador].valor)
									vector_contador[contador].presente = true;
						}
					for(int contador=0; contador<9; contador++){
						cout << vector_contador[contador].presente << " ";
						if(!vector_contador[contador].presente)
							error= true;
					}
					cout << endl;
					ResetContador();					
				}
			}

			cout << "\ntabla de presentes columnas:" << endl << endl << flush;
			for(int j=0; j<COL; j++){
				for(int y=0; y<COL_REGION; y++){
					for(int i=0; i<FIL; i++)
						for(int x=0; x<FIL_REGION; x++){
							valor_aux = MostrarValor(i, j, x, y);
							for(int contador=0; contador<9; contador++)
								if(valor_aux == vector_contador[contador].valor)
									vector_contador[contador].presente = true;
						}
					for(int contador=0; contador<9; contador++){
						cout << vector_contador[contador].presente << " ";
						if(!vector_contador[contador].presente)
							error = true;
					}
					cout << endl;
					ResetContador();					
				}
			}

			for(int i=0; i<FIL; i++){
				for(int j=0; j<COL; j++){
					cout << "\ntabla de presentes region:" << endl << endl << flush;
					for(int x=0; x<FIL_REGION; x++)
						for(int y=0; y<COL_REGION; y++){
							valor_aux = MostrarValor(i, j, x, y);
							for(int contador=0; contador<9; contador++)
								if(valor_aux == vector_contador[contador].valor)
									vector_contador[contador].presente = true;
						}
					for(int contador=0; contador<9; contador++){
						cout << vector_contador[contador].presente << " ";
						if(!vector_contador[contador].presente)
							error = true;
						if(contador == 2 || contador == 5)
							cout << endl;
					}
					cout << endl;
					ResetContador();					
				}
			}

			if(error)
				return false;
			else
				return true;		
		}
};

////////////////////////////////////////////////////////////////////////////
/**
 * Clase con las opciones del menu de presentacion
 * @see Menu
 */
class Menu{
	
	private:
		int option;
	
	public:
		/**
		 * Constructor por defecto
		 * @see Menu
		 */
		Menu() :option(0){			
		}
		/**
		 * Cambiar option
		 * @see Option
		 * @param p_option opcion que queremos tener
		 */
		void Option(int p_option){
			option = p_option;
		}
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
			<< "         ()__)      |       EJERCCICIO: 04        |       (__()" << endl
			<< " ----\\___()_)       |                             |        (_()___/---" << endl
			<< "                    +-----------------Ooo---------+" << endl;
			usleep(2000000);
			system("clear");
		}
		/**
		* Salida personal del programa
		* @see Fin
		*/  
		void Fin(){
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
		/**
		 * Limpiar el buffer
		 * @see Limpiar
		 */
		void Limpiar(){
			cin.ignore(256,'\n');
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
};

////////////////////////////////////////////////////////////////////////////
// MAIN DE LA APLICACIÓN
////////////////////////////////////////////////////////////////////////////
int main(){
	//DECLARACIÓN DE VARIABLES
	Menu menu;
	Sudoku sudoku;
	int numero;
	bool error;

	//ENTRADA DE DATOS DE LA APLICACIÓN
	menu.Inicio();
	for(int i=0; i<FIL; i++)
		for(int x=0; x<FIL_REGION; x++)
			for(int j=0; j<COL; j++)
				for(int y=0; y<COL_REGION; y++){
					cin >> numero;
					//cout << i << " " << j << " " << x << " " << " " << y << " " <<  numero << endl;
					sudoku.InsertarValores(numero, i, j, x, y);
				}

	//CUERPO DE LA APLICACION
	if(sudoku.Comprobar())
		error = false;
	else
		error = true;

	//SALIDA DE DATOS DE LA APLICACION
	menu.Limpiar();

	if(!error)
		cout << "\033[32m" << "El sudoku es correcto" << endl << flush;
	else
		cout << "\033[31m" << "El sodoku es incorrecto" << endl << flush;
	
	for(int i=0; i<FIL; i++)
		for(int x=0; x<FIL_REGION; x++){
			for(int j=0; j<COL; j++)
				for(int y=0; y<COL_REGION; y++)
					cout << sudoku.MostrarValor(i, j, x, y) << "  ";
			cout << endl;
		}

	menu.Pausa();


	//FIN DE LA APLICACIÓN
	menu.Fin();
}

/**
	Esta matriz es correcta
	1 2 3 4 5 6 7 8 9
	4 5 6 7 8 9 1 2 3
	7 8 9 1 2 3 4 5 6
	2 3 4 5 6 7 8 9 1
	5 6 7 8 9 1 2 3 4
	8 9 1 2 3 4 5 6 7
	3 4 5 6 7 8 9 1 2
	6 7 8 9 1 2 3 4 5
	9 1 2 3 4 5 6 7 8

	Esta matriz no es correcta
	1 2 3 4 5 6 7 8 9
	4 5 6 7 8 9 1 2 3
	7 8 3 1 2 3 4 5 6
	2 3 4 5 6 7 8 3 1
	5 6 7 8 3 1 2 3 4
	8 3 1 2 3 4 5 6 7
	3 4 5 6 7 8 3 1 2
	6 7 8 3 1 2 3 4 5
	9 1 2 3 4 5 6 7 8
*/