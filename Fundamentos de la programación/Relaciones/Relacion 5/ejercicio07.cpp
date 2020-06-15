/**
 * programa para obtener la moda de una secuencia de caracteres
 * @author: Antonio Rodríguez Alaminos
 */

////////////////////////////////////////////////////////////////////////////
// DEPENDENCIAS NECESARIAS PARA LA APLICACIÓN
////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////
// VARIABLES GLOBALES
////////////////////////////////////////////////////////////////////////////
const int TAM = 100;
const int TAM_ABECEDARIO = 'z' - 'a';
struct FrecuenciaCaracter{
	char caracter;
	int frecuencia;
};

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
		void InsertarCadena(){
			char caracter;
			do{
				cin.get(caracter);
				if(caracter != '#')
					cadena[tamanio_total] = caracter;
					tamanio_total++;
			} while (caracter != '#');
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
		 * calcula la moda de la secuencia
		 * @see Moda
		 * @return el caracter mas repetido
		 */
		FrecuenciaCaracter Moda(){
			FrecuenciaCaracter moda[TAM_ABECEDARIO];
			char letra = 'a';
			int i = 0;
			int posicion=0, posicion_moda=0;

			while(letra != 'z' + 1){
				moda[posicion].caracter=letra;
				moda[posicion].frecuencia=0;
				posicion++;
				letra++;
			}

			for(int i=0; i<MostrarTamanioTotal(); i++)
				for(int j=0; j<TAM_ABECEDARIO; j++)
					if(cadena[i] == moda[j].caracter)
						moda[j].frecuencia++;

			for(int i=0; i<TAM_ABECEDARIO; i++)
				if(moda[posicion_moda].frecuencia < moda[i].frecuencia)
					posicion_moda = i;

			return moda[posicion_moda];
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
	cout << "\n\nPress 'Enter' to indiceinue: ... ";
	while ( getchar() != '\n');
}

////////////////////////////////////////////////////////////////////////////
// MAIN DE LA APLICACION
////////////////////////////////////////////////////////////////////////////
int main(){
	//DECLARACION DE VARIABLES
	SecuenciaCaracteres cadena_caracteres;

	//ENTRADA DE DATOS
	cout << "introduce la cadena de caracteres, recuerda que para finalizar tienes que introducir # " << endl << flush;
	cadena_caracteres.InsertarCadena();

	//SALIDA DE DATOS
	cout << "la moda es: " << cadena_caracteres.Moda().caracter << " con una frecuencia de: " << cadena_caracteres.Moda().frecuencia << endl;
	Pausa();
}