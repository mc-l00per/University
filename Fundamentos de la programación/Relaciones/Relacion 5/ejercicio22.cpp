////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// DEPENDENCIAS DEL PROGRAMA
////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <unistd.h>
#include <string.h>
using namespace std;

////////////////////////////////////////////////////////////////////////////
// VARIABLES GLOBALES
////////////////////////////////////////////////////////////////////////////
const int TAM_EXAMEN = 100;
const int TAM_ALUMNOS = 100;
struct Preguntas{
	string question;
	char list_result;
};
struct Alumno{
	string name;
	int nota;
};

////////////////////////////////////////////////////////////////////////////
// CLASES
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

////////////////////////////////////////////////////////////////////////////
class Examen{

	private:
		string name_asignature;
		Preguntas list_question[TAM_EXAMEN];
		int total_question;

	public:
		Examen() :total_question(0){}
		void InitExamen(string asignature){
			name_asignature = asignature;
		}
		void NuevaPregunta(string enunciado, char respuesta){
			list_question[total_question].question = enunciado;
			list_question[total_question].list_result = respuesta;
			total_question++;
		}
		int NumPreguntas(){
			return total_question;
		}
		string Enunciado(int indice){
			return list_question[indice].question;
		}
		char Respuesta(int indice){
			return list_question[indice].list_result;
		}
		int Nota(char respuestas[]){
			int nota = 0;
			for(int i=0; i<total_question; i++)
				if(respuestas[i] != 'x'){					
					if(list_question[i].list_result != respuestas[i])
						nota -= 1;
					else
						nota += 1;
				}
			if(nota < 0)
				nota = 0;
			return nota;
		}
};

////////////////////////////////////////////////////////////////////////////
// MAIN
////////////////////////////////////////////////////////////////////////////
int main(){
	Menu menu;
	Examen examen;
	int total_alumnos, nota;
	string asignature, enunciado;
	char respuesta, name;

	menu.Inicio();
	asignature = "Gimnasia";
	examen.InitExamen(asignature);

	for(int j=0; j<2; j++)
		for(char i='a'; i<'f'; i++){
			enunciado = "Cuando me cojia los huevos llovia si o si ";
			enunciado.push_back(i);
			respuesta = i;
			examen.NuevaPregunta(enunciado, respuesta);
		}

	total_alumnos = 4;
	Alumno alumnos[total_alumnos];
	char respuestas[examen.NumPreguntas()];

	for(int i=0; i<total_alumnos; i++){
		cout << "Introduce tu nombre: ";
		do{
			cin.get(name);
			alumnos[i].name.push_back(name);
		}while(name!='#');
		for(int j=0; j<examen.NumPreguntas(); j++){
			cout << examen.Enunciado(j) << endl << "introduce una respuesta x para no contestar ==> ";
			cin >> respuesta;
			respuestas[j] = respuesta;
		}
		nota = examen.Nota(respuestas);
		alumnos[i].nota = nota;
	}

	for(int i=0; i<total_alumnos; i++)
		cout << alumnos[i].name << " tiene de nota un: " << alumnos[i].nota << endl;

	menu.Pausa();
	menu.Fin();
}