///////////////////////////////////////////////////////////////////////////////////////
// Correccion de una tabla de datos sobre colores
///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
// DEPENDENCIAS DE LA APLICACIÓN
///////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <unistd.h>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////
// VARIABLES GLOBALES DE LA APLICACION
///////////////////////////////////////////////////////////////////////////////////////
const int FIL_AND_COL = 25;

///////////////////////////////////////////////////////////////////////////////////////
// CLASES DE LA APLICACIÓN
///////////////////////////////////////////////////////////////////////////////////////
class ImagenBlancoNegro{

	private:
		int imagen[FIL_AND_COL][FIL_AND_COL];

	public:
		ImagenBlancoNegro(){}

		void InsertarImagen(int valor, int fil, int col){
			imagen[fil][col] = valor;
		}

		int MostrarImagen(int fil, int col){
			return imagen[fil][col];
		}

		ImagenBlancoNegro RepararImagen(){
			ImagenBlancoNegro imagen_aux;
			int dividendo, divisor;

			for(int i=0; i<FIL_AND_COL; i++)
				for(int j=0; j<FIL_AND_COL; j++){
					divisor = 0;
					if(imagen[i][j] < 0 && i!=0 && j!=0 && i!=FIL_AND_COL-1 && j!=FIL_AND_COL-1){
						if(imagen[i+1][j] > 0){
							dividendo += imagen[i+1][j];
							divisor++;
						}
						if(imagen[i][j+1] > 0){
							dividendo += imagen[i+1][j];
							divisor++;
						}
						if(imagen[i][j-1] > 0){
							dividendo += imagen[i+1][j];
							divisor++;
						}
						if(imagen[i-1][j] > 0){
							dividendo += imagen[i+1][j];
							divisor++;
						}
						if(imagen[i+1][j+1] > 0){
							dividendo += imagen[i+1][j];
							divisor++;
						}
						if(imagen[i+1][j-1] > 0){
							dividendo += imagen[i+1][j];
							divisor++;
						}
						if(imagen[i-1][j+1] > 0){
							dividendo += imagen[i+1][j];
							divisor++;
						}
						if(imagen[i-1][j-1] > 0){
							dividendo += imagen[i+1][j];
							divisor++;
						}
						if(dividendo/divisor < 255)
							imagen_aux.InsertarImagen(dividendo/divisor, i, j);
						else
							imagen_aux.InsertarImagen(255, i, j);

					}
					else
						imagen_aux.InsertarImagen(imagen[i][j], i, j);
				}
		return imagen_aux;
	}
};

////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////
// MAIN DE LA APLICACIÓN
///////////////////////////////////////////////////////////////////////////////////////
int main(){
	//DECLARACIÓN DE VARIABLES DE LA APLICACIÓN
	ImagenBlancoNegro imagen;
	ImagenBlancoNegro imagen_reparada;
	Menu menu;
	int valor;

	//ENTRADA DE DATOS DE LA APLICACIÓN
	cout << "Introduce los valores de la imagen." << endl;
	for(int i=0; i<FIL_AND_COL; i++)
		for(int j=0; j<FIL_AND_COL; j++){
			cin >> valor;
			imagen.InsertarImagen(valor, i, j);
		}

	//CUERPO DEL PROGRAMA
	imagen_reparada = imagen.RepararImagen();

	//SALIDA DE LA APLICACIÓN
	menu.Limpiar();
	for(int i=0; i<FIL_AND_COL; i++){
		for(int j=0; j<FIL_AND_COL; j++)
			cout << imagen_reparada.MostrarImagen(i, j) << "\t";
		cout << endl;
	}

	menu.Pausa();
}

/**
	Imagen con valores negativos

	0       1       -2       3       4       5       6       -7       8       9       10      11      12      13      14      15      16      17      18      19      20      21      22      23      24
	1       2       3       4       5       6       7       8       9       10      11      12      13      14      -15      16      17      18      19      20      21      22      23      24      25
	2       3       4       5       6       7       8       9       10      11      12      13      14      15      16      17      18      19      20      21      22      23      24      25      26
	3       4       5       6       7       8       9       10      -11      12      13      14      15      16      17      18      19      20      21      22      -23      24      25      26      27
	4       5       6       7       8       9       10      11      12      13      14      15      16      -17      18      19      20      21      22      23      24      25      26      27      28
	5       6       -7       8       9       10      11      12      13      14      15      16      17      18      19      20      21      22      23      24      25      26      27      28      29
	6       7       8       9       10      11      12      13      14      15      16      17      18      19      20      21      22      23      24      25      26      27      -28      29      30
	7       8       9       10      11      12      13      14      15      16      17      18      19      20      21      22      23      24      25      26      27      28      29      30      31
	8       9       10      11      12      13      -14      15      16      17      18      19      20      21      22      23      24      25      26      27      28      29      30      31      32
	9       10      11      12      13      14      15      16      17      18      19      20      21      22      23      24      25      26      27      28      29      30      31      32      -33
	10      11      12      13      14      15      16      17      18      19      20      21      22      23      24      25      26      27      28      29      30      31      32      33      34
	11      12      13      14      15      16      17      18      19      20      21      22      23      24      25      26      27      28      29      30      31      32      33      34      35
	12      13      14      15      16      17      18      19      20      21      22      23      24      25      26      27      28      29      30      31      32      33      34      35      36
	13      14      15      -16      17      18      19      20      21      22      23      24      25      26      27      28      29      -30      31      32      33      34      35      36      37
	14      15      16      17      18      19      20      21      22      23      24      25      -26      27      28      29      30      31      32      33      34      35      36      37      38
	15      16      17      18      19      20      21      22      23      24      25      26      27      28      29      30      31      32      33      34      35      36      37      38      39
	16      17      18      19      20      21      22      23      24      25      26      27      28      29      30      31      32      33      34      35      36      37      38      39      40
	17      18      19      20      21      22      23      24      25      26      27      28      29      30      31      32      33      34      35      36      37      38      -39      40      41
	18      19      20      21      22      23      24      25      26      27      28      29      30      31      32      33      34      35      36      37      38      39      40      41      42
	19      20      -21      22      23      24      25      26      27      28      29      30      31      32      33      34      35      36      37      38      39      40      41      42      43
	20      21      22      23      24      25      26      27      -28      29      30      31      32      33      34      35      36      37      38      39      40      41      42      43      44
	21      22      23      24      25      26      27      28      29      30      31      32      33      34      35      36      37      38      39      40      41      42      43      44      45
	22      23      24      25      26      27      28      29      30      31      32      33      34      35      36      37      38      39      40      41      42      43      -44      45      46
	23      24      25      26      27      28      29      30      31      32      33      34      35      36      37      38      39      40      41      42      43      44      45      46      47
	24      25      -26      27      28      29      30      31      32      33      34      35      36      37      38      39      40      41      42      43      44      45      46      47      -48
*/