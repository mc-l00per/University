/**
 * programa para obtener CountingSort
 * @author: Antonio Rodríguez Alaminos
 */

////////////////////////////////////////////////////////////////////////////
// DEPENDENCIAS NECESARIAS PARA LA APLICACIÓN
////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string.h>
using namespace std;

////////////////////////////////////////////////////////////////////////////
// VARIABLES GLOBALES
////////////////////////////////////////////////////////////////////////////
const int TAM = 100;

////////////////////////////////////////////////////////////////////////////
// CLASES DE LA APLICACION
////////////////////////////////////////////////////////////////////////////
class SecuenciaCaracteres{
	
	private:
		char cadena[TAM];
		int tamanio_total;

	public:
		/**
		 * Constructor por defecto
		 * @see SecuenciaCaracteres
		 */
		SecuenciaCaracteres() :tamanio_total(0){}
		/**
		 * Almacenar la cadena de caracteres
		 * @see InsertarCadena
		 * @param p_cadena cadena que queremos almacenar
		 */
		void InsertarCadena(char caracter){
			if(caracter != '#')
				cadena[tamanio_total] = caracter;
				tamanio_total++;
		}
		/**
		 * Muestra la cadena de caracteres
		 * @see MostrarCadena
		 * @return cadena que tenemos almacenada
		 */
		char *MostrarCadena(){
			return cadena;
		}	
		/**
		 * Muestra el tamaño real de la cadena
		 * @see MostrarTamanioTotal
		 * @return tamaño real de la cadena
		 */
		int MostrarTamanioTotal(){
			return tamanio_total;
		}
		/**
		 * calcular counting sort
		 * @see CountingSort
		 * @return nueva cadena de caracteres ordenados
		 */
		string CountingSort(){
			string p_cadena;
			char maximo = cadena[0], 
				minimo = cadena[0];

			for(int i=0; i<MostrarTamanioTotal()-1; i++)			
				if(cadena[i] >= maximo && cadena[i] != '#')
					maximo = cadena[i];
				else if(cadena[i] < minimo && cadena[i] != '#')
					minimo = cadena[i];

			int tamanio_conteo = maximo - minimo + 1;
			int frecuencia[tamanio_conteo];

			for(int i=0; i<=tamanio_conteo; i++)
				frecuencia[i] = 0;

			char letra_aux = minimo;
			int posicion_conteo = 0;
			while(letra_aux <= maximo){
				for(int i=0; i<MostrarTamanioTotal(); i++)
					if(cadena[i] == letra_aux)
						frecuencia[posicion_conteo]++;
				posicion_conteo++;
				letra_aux++;
			}

			char valor = minimo;
			int escritura = 0, lectura;

			for(int i=0; i<tamanio_conteo; i++){
				lectura = 0;
				while(lectura < frecuencia[i]){
					p_cadena.push_back(valor);
					escritura++;
					lectura++;
				}
				valor++;
			}

			return p_cadena;
		}
};

////////////////////////////////////////////////////////////////////////////
// FUNCIONES PARA LA APLICACION FUNCIONE EN TODOS LOS SO
////////////////////////////////////////////////////////////////////////////
/**
 * Salida personal del programa
 * @see Fin
 */  
void Pausa(){
	cin.ignore(256,'\n');
	cout << "\n\nPress 'Enter' to continue: ... ";
	while ( getchar() != '\n');
}

////////////////////////////////////////////////////////////////////////////
// MAIN DE LA APLICACION
////////////////////////////////////////////////////////////////////////////
int main(){
	//DECLARACION DE VARIABLES
	SecuenciaCaracteres cadena_caracteres;
	char caracter;

	//ENTRADA DE DATOS
	cout << "introduce la cadena de caracteres, recuerda que para finalizar tienes que introducir #" << endl << flush;
	do{
		cin.get(caracter);
		cadena_caracteres.InsertarCadena(caracter);	
	} while (caracter != '#');

	//SALIDA DE DATOS
	cout << "la cadena original era: " << cadena_caracteres.MostrarCadena() << endl 
		<< "transformada es: " << cadena_caracteres.CountingSort() << endl;
	Pausa();

	exit(0);
}