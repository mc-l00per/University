/**
 * ////////////////////////////////////////////////////////////////////////////
 * //
 * // Fundamentos de Programación
 * // ETS Informática y Telecomunicaciones
 * // Universidad de Granada
 * // Departamento de Ciencias de la Computación e Inteligencia Artificial
 * // Autor: Juan Carlos Cubero
 * // Version: 1.2 ==> Autor: Antonio Rodríguez Alaminos
 * ////////////////////////////////////////////////////////////////////////////
 *
 * Cuadrado, Punto, Segmento y Circunferencia
 *
 *
 * Recuperad las implementaciones de las clases Punto2D , SegmentoDirigido ,
 * Circunferencia y Cuadrado , disponibles en el fichero
 * FigurasGeometricas.cpp disponible en decsai . Las tres primeras se han
 * visto en clase de teoría. Con respecto al cuadrado, éste viene determinado por el
 * punto correspondiente a la esquina inferior izquierda y por la longitud de cualquiera de
 * sus lados (estos serán sus datos miembros). Supondremos que sólo representamos
 * cuadrados cuya base es paralela al eje de las abscisas.
 *
 * Definid sobre la clase Cuadrado los siguientes métodos:
 *
 * • Métodos para calcular el área y el perímetro del cuadrado.
 * • Obtener el punto central interior al cuadrado:
 * Punto2D Centro()
 * Para calcular las coordenadas basta sumar la mitad de la longitud del cuadrado
 * a las coordenadas de la esquina inferior izquierda.
 * • Obtener la circunferencia inscrita al cuadrado (la que está por dentro):
 * Circunferencia CircunferenciaInscrita()
 * Esta circunferencia es la que tiene como centro el centro del cuadrado y como
 * radio la mitad de la longitud del cuadrado.
 * • Obtener la circunferencia circunscrita al cuadrado (la que está por fuera):
 * Circunferencia CircunferenciaCircunscrita()
 * Esta circunferencia es la que tiene como centro el centro del cuadrado y como
 * radio, la longitud del segmento que une el centro con la esquina inferior izquier-
 * da. Obtened la longitud creando el objeto de la clase SegmentoDirigido y a
 * continuación llamad al método Longitud.
 *
 * Complete el programa principal de prueba que se encuentra en el fichero
 * FigurasGeometricas.cpp
 */

#include <iostream>
#include <cmath>
#include <unistd.h> 	//para poder utilizar el usleep y otros comandos
using namespace std;

//variables globales
const double PI = 3.1415927;

//funciones globales
/**
 * Comprueva sin son iguales
 * @see SonIguales
 * @param uno un valor
 * @param otro el otro valor
 * @return true si no son iguales false en caso contrario
 */
bool SonIguales(double uno, double otro){
    return abs(uno-otro) <= 1e-6;
}

/////////////////////////////////////////////////////////////////////////

/**
 * Clase con las opciones del menu de presentacion
 * @see Menu
 */
class Menu{
	public:
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
				<< "         ()__)      |       EJERCCICIO: 06        |       (__()" << endl
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
		 * Pausa del sistema, mas intro para continuar
		 * @see Pausa
		 */
		void Pausa(){
			cin.ignore(256,'\n');
			cout << "\n\nPress 'Enter' to indiceinue: ... ";
			while ( getchar() != '\n');
		}
};

/////////////////////////////////////////////////////////////////////////

/**
 * Clase con las propriedades de un punto en 2D
 * @see Punto2D
 */
class Punto2D{
	private:
	   	double abscisa  = 0.0;
	   	double ordenada = 0.0;
	public:
		/**
		 * Constructor por defecto
		 * @see Punto2D
		 * @param abscisaPunto valor de la abscisa
		 * @param ordenadaPunto valor de la ordenada
		 */
	   	Punto2D(double abscisaPunto, double ordenadaPunto){
	      	SetCoordenadas(abscisaPunto, ordenadaPunto);
	   	}
	   	/**
	   	 * Muestra la abscisa del punto2d
	   	 * @see Abscisa
	   	 * @return valor de la abscisa
	   	 */
	   	double Abscisa(){
	      	return abscisa;
	   	}
	   	/**
	   	 * Muestra la ordenada del punto2d
	   	 * @see Ordenada
	   	 * @return valor de la ordenada
	   	 */
	   	double Ordenada(){
	      	return ordenada;
	   	}
	   	/**
	   	 * Ingresa los valores de las coordenadas
	   	 * @see SetCoordenadas
	   	 * @param abscisaPunto valor de la abscisa
	   	 * @param ordenadaPunto valor de la ordenada
	   	 */
	   	void SetCoordenadas(double abscisaPunto, double ordenadaPunto){
	      	if (!SonIguales(abscisaPunto, ordenadaPunto)){
	         	abscisa = abscisaPunto;
	         	ordenada = ordenadaPunto;
	      	}
	   	}
	   	/**
	   	 * Compara dos puntos2d
	   	 * @see EsIgual_a
	   	 * @param otro_punto el otro punto con el que queremos comparar
	   	 * @return true sin son iguales false en caso contrario
	   	 */
	   	bool EsIgual_a (Punto2D otro_punto){
	      	return (SonIguales(abscisa, otro_punto.abscisa) && SonIguales(ordenada, otro_punto.ordenada));
	   	}
};

/////////////////////////////////////////////////////////////////////////

/**
 * Clase con las propiedades de un segmento dirigido
 * @see SegmentoDirigido
 */
class SegmentoDirigido{
	private:
		double x_1 = 0.0,
	        y_1 = 0.0,
	        x_2 = 0.0,
	        y_2 = 0.0;
	   	/**
	   	 * Comprueba si las coordenadas introducidas son correctas
	   	 * @see SonCorrectos
	   	 * @param origen_abscisa punto de origen de la abscisa
	   	 * @param final_abscisa punto final de la abscisa
	   	 * @param origen_ordenada punto de origen de la ordenada
	   	 * @param final_ordenada punto final de la ordenada
	   	 * @return true si son correctos false en  caso contrario
	   	 */
	   	bool SonCorrectos(double origen_abscisa, double origen_ordenada, double final_abscisa,  double final_ordenada){
	 	    return !(origen_abscisa == final_abscisa && origen_ordenada == final_ordenada);
	    }   
	public:
		/**
		 * Constructor por defecto
		 * @see SegmentoDirigido
		 * @param origen_abscisa punto de origen de la abscisa
	   	 * @param final_abscisa punto final de la abscisa
	   	 * @param origen_ordenada punto de origen de la ordenada
	   	 * @param final_ordenada punto final de la ordenada
	   	 */
	    SegmentoDirigido(double origen_abscisa, double origen_ordenada, double final_abscisa, double final_ordenada){
	    	SetCoordenadas(origen_abscisa, origen_ordenada, final_abscisa, final_ordenada);
	   	}
	   	/**
	   	 * Almacenas las coordenadas del segmento
	   	 * @see SetCoordenadas
	   	 * @param origen_abscisa punto de origen de la abscisa
	   	 * @param final_abscisa punto final de la abscisa
	   	 * @param origen_ordenada punto de origen de la ordenada
	   	 * @param final_ordenada punto final de la ordenada
	   	 */
	   	void SetCoordenadas(double origen_abscisa, double origen_ordenada, double final_abscisa,  double final_ordenada){
	      	if (SonCorrectos(origen_abscisa, origen_ordenada, final_abscisa, final_ordenada)){
	         	x_1 = origen_abscisa;
	         	y_1 = origen_ordenada;
	         	x_2 = final_abscisa;
	         	y_2 = final_ordenada;
	      	}
	   	}
	   	/**
	   	 * Muestra el origen de la abscisa
	   	 * @see OrigenAbscisa
	   	 * @return valor del origen de la abscisa
	   	 */
	   	double OrigenAbscisa(){
	      	return x_1;
	   	}
	   	/**
	   	 * Muestra el origen de la ordenada
	   	 * @see OrigenOrdenada
	   	 * @return valor del origen de la ordenada
	   	 */
	   	double OrigenOrdenada(){
	      	return y_1;
	   	}
	   	/**
	   	 * Muestra el final de la abscisa
	   	 * @see FinalAbscisa
	   	 * @return valor del final de la abscisa
	   	 */
	   	double FinalAbscisa(){
	      	return x_2;
	   	}
	   	/**
	   	 * Muestra el final de la ordenada
	   	 * @see FinalOrdenada
	   	 * @return valor del final de la ordenada
	   	 */
	   	double FinalOrdenada(){
	      	return y_2;
	   	}
	   	/**
	   	 * Calcula la longitud del segmento dirigido
	   	 * @see Longitud
	   	 * @return longitud del segmento
	   	 */
	   	double Longitud(){
	      	return sqrt((x_2 - x_1)*(x_2 - x_1) + (y_2 - y_1)*(y_2 - y_1));
	   	}
	   	/**
	   	 * Traslada el segmento x unidades horizontalmente
	   	 * @see TransladaHorizontal
	   	 * @param unidades unidades que deseamos desplazar el segmento
	   	 */
	   	void TrasladaHorizontal(double unidades){
	      	x_1 = x_1 + unidades;
	      	x_2 = x_2 + unidades;
	   	}
	   	/**
	   	 * Traslada el segmento x unidades verticalmente
	   	 * @see TrasladaVertical
	   	 * @param unidades unidades que deseamos desplazar el segmento
	   	 */
	   	void TrasladaVertical(double unidades){
	      	y_1 = y_1 + unidades;
	      	y_2 = y_2 + unidades;
	   	}
};

/////////////////////////////////////////////////////////////////////////

/**
 * Clase con las propiedades de una circuferencia
 * @see Circuferencia
 */
class Circunferencia{
	private:
		double centro_x = 0.0;
		double centro_y = 0.0;
		double radio    = 0.0;
		/**
		 * Comprueba que el valor del radio sea correcto
		 * @see EsCorrectoRadio 
		 * @return true si es correcto false en caso contrario
		 */
		bool EsCorrectoRadio(double longitud_radio){
		  	return longitud_radio > 0; 
		}
	public:
		/**
		 * Constructor por defecto
		 * @see Circuferencia
		 * @param abscisa_centro centro de la abscisa
		 * @param ordenada_centro centro de la ordenada
		 * @param longitud_radio la longitud que tendra el radio
		 */
		Circunferencia(double abscisa_centro, double ordenada_centro, double longitud_radio){
		  	SetCentro(abscisa_centro, ordenada_centro);
		  	SetRadio(longitud_radio);
		}
		/**
		 * Introduce el valor del radio
		 * @see SetRadio
		 * @param longitud_radio la longitud que va a introducir en el radio
		 */
		void SetRadio(double longitud_radio){
		  	if (EsCorrectoRadio(longitud_radio))
		     	radio = longitud_radio;
		}
		/**
		 * Introduce el centro de la circuferencia
		 * @see SetCentro
		 * @param abscisa_centro centro de la abscisa que se almacena
		 * @param ordenada_centro centro de la ordenada que se almacena
		 */
		void SetCentro(double abscisa_centro, double ordenada_centro){
		  	centro_x = abscisa_centro;
		  	centro_y = ordenada_centro;
		}
		/**
		 * Mostrar el centro de la abscisa
		 * @see AbscisaCentro
		 * @return valor del centro de la abscisa
		 */
		double AbscisaCentro(){
		  	return centro_x;
		}
		/**
		 * Mostrar el centro de la ordenada
		 * @see OrdenadaCentro
		 * @retrun valor del centro de la ordenada
		 */
		double OrdenadaCentro(){
		  	return centro_y;
		}
		/**
		 * Muestra el radio de la circuferencia
		 * @see Radio
		 * @return valor del radio de la circuferencia
		 */
		double Radio(){
		  	return radio;
		}
		/**
		 * Calcula la longitud de la circuferencia
		 * @see Longitud
		 * @return valor de la longitud de la circuferencia
		 */
		double Longitud(){
		  	return 2*PI*radio;
		}
		/**
		 * Calcula el area de la circuferencia
		 * @see Area
		 * @return valor del area de la circuferencia
		 */
		double Area(){
		  	return PI*radio*radio;
		}
		/**
		 * Translada la circuferencia a una nueva posicion
		 * @see Traslada
		 * @param en_horizontal posicion centro_x nueva
		 * @param en_vertical posicion centro_y nueva
		 */
		void Traslada(double en_horizontal, double en_vertical){
		  	centro_x = centro_x + en_horizontal;
		  	centro_y = centro_y + en_vertical;
		}
};

/////////////////////////////////////////////////////////////////////////

/**
 * Clase con las propiedades de un cuadrado
 * @see Cuadrado
 */
class Cuadrado{
	private:
	   	double esquina_abscisa;
	   	double esquina_ordenada;
	   	double longitud;
	   	/**
	   	 * Comprueba que la longitud sea correcta
	   	 * @see EsCorrectaLongitud
	   	 * @return true cuando es correcta false cuando no lo es
	   	 */
	   	bool EsCorrectaLongitud(double longitud){
	      	return longitud > 0; 
	   	}
	public:
		/**
		 * Constructor por defecto de la clase
		 * @see Cuadrado
		 * @param esquina_abscisa_cuadrado posicion de x de la esquina inferior
		 * @param esquina_ordenada_cuadrado posicion de y en la esquina inferior
		 * @param longitud_cuadrado longitud del segmento del cuadrado
		 */
	   	Cuadrado(double esquina_abscisa_cuadrado, double esquina_ordenada_cuadrado, double longitud_cuadrado){
	   		SetLongitud(longitud_cuadrado);
	      	SetEsquinaInfIzq(esquina_abscisa_cuadrado, esquina_ordenada_cuadrado);
	   	}
	   	/**
	   	 * Introduce el valor de la longitud del segmento
	   	 * @see SetLongitud
	   	 * @param longitud_cuadrado longitud que queremos almacenar
	   	 */
		void SetLongitud(double longitud_cuadrado){
		  	if (EsCorrectaLongitud(longitud_cuadrado))
		     	longitud = longitud_cuadrado;
		}
		/**
		 * Almacenar las coordenadas de la esquina izquierda inferior del cuadrado
		 * @see SetEsquinaInfIzq
		 * @param esquina_abscisa_cuadrado posicion x de la esquina
		 * @param esquina_ordenada_cuadrado posicion y de la esquina
		 */
		void SetEsquinaInfIzq(double esquina_abscisa_cuadrado, double esquina_ordenada_cuadrado){
		  	esquina_abscisa = esquina_abscisa_cuadrado;
		  	esquina_ordenada = esquina_ordenada_cuadrado;
		}
		/**
		 * Mostrar el valor que contiene la esquina de x
		 * @see AbscisaEsquina
		 * @return valor de la esquina para la abscina
		 */
		double AbscisaEsquina(){
		  	return esquina_abscisa;
		}
		/**
		 * Mostrar el valor que contiene la esquina de y
		 * @see OrdenadaEsquina
		 * @return valor de esta esquina
		 */
		double OrdenadaEsquina(){
		  	return esquina_ordenada;
		}
		/**
		 * Muestra la longitud del lado
		 * @see Longitud
		 * @return el valor de la longitud del segmento del cuadrado
		 */
		double Longitud(){
		  	return longitud;
		}
		/**
		 * Calcula el area del cuadrado
		 * @see Area
		 * @return valor del area del cuadrado
		 */
		double Area(){
		  	return longitud * longitud;
		}
		/**
		 * Calcula el perimetro del cuadrado
		 * @see Perimetro
		 * @return valor del perimetro
		 */
		double Perimetro(){
		  	return longitud * 4;
		}
		/**
		 * Obtener el primer lado del cuadrado
		 * @see Lado1
		 * @return el segmento obtenido para el lado 1
		 */
		SegmentoDirigido Lado1(){
		  	SegmentoDirigido lado(esquina_abscisa, esquina_ordenada, esquina_abscisa + longitud, esquina_ordenada);
		  	return lado;
	   	}
	   	/**
		 * Obtener el segundo lado del cuadrado
		 * @see Lado2
		 * @return el segmento obtenido para el lado 2
		 */
	   	SegmentoDirigido Lado2(){
	      	SegmentoDirigido lado(esquina_abscisa + longitud, esquina_ordenada, esquina_abscisa + longitud, esquina_ordenada + longitud);
	      	return lado;
	   	}
	   	/**
		 * Obtener el tercero lado del cuadrado
		 * @see Lado3
		 * @return el segmento obtenido para el lado 3
		 */
	   	SegmentoDirigido Lado3(){
	      	SegmentoDirigido lado(esquina_abscisa + longitud, esquina_ordenada + longitud, esquina_abscisa, esquina_ordenada + longitud);
	      	return lado;
	   	}
	   	/**
		 * Obtener el cuarto lado del cuadrado
		 * @see Lado4
		 * @return el segmento obtenido para el lado 4
		 */
	   	SegmentoDirigido Lado4(){
	      	SegmentoDirigido lado(esquina_abscisa, esquina_ordenada + longitud, esquina_abscisa, esquina_ordenada);
	      	return lado;
	   	}
	   	/**
	   	 * Obtener el punto central del cuadrado
	   	 * @see Centro
	   	 * @return coordenadas del punto central
	   	 */
	   	Punto2D Centro(){
	      	Punto2D centro(esquina_abscisa+(longitud/2), esquina_ordenada+(longitud/2));
	      	return centro;
	   	}
	   	/**
	   	 * Obtener la circuferencia inscrita en el cuadrado
	   	 * @see CircunferenciaInscrita
	   	 * @return la circuferencia instrita
	   	 */
	   	Circunferencia CircunferenciaInscrita(){
	      	Punto2D centro = Centro();
	      	SegmentoDirigido radio(centro.Abscisa(), centro.Ordenada(), esquina_abscisa+longitud/2, esquina_ordenada);
	      	Circunferencia circuferencia_inscrita(centro.Abscisa(), centro.Ordenada(), radio.Longitud());
	      	return circuferencia_inscrita;
	   	}
	   	/**
	   	 * Obtener la circuferencia circunscrita en el cuadrado
	   	 * @see CircunferenciaCircunscrita
	   	 * @return circuferencia circunscrita
	   	 */
	   	Circunferencia CircunferenciaCircunscrita(){
	      	Punto2D centro = Centro();
	      	SegmentoDirigido radio(centro.Abscisa(), centro.Ordenada(), esquina_abscisa, esquina_ordenada);
	      	Circunferencia circuferencia_circunstrita(centro.Abscisa(), centro.Ordenada(), radio.Longitud());
	      	return circuferencia_circunstrita;
	   	}
	   	/**
	   	 * Comprobar si tienen un mayor area
	   	 * @see MayorArea_que
	   	 * @param otro_cuadrado el otro cuadrado que queremos comparar
	   	 * @return true si es mayor false en caso de ser menor
	   	 */
	   	bool MayorArea_que(Cuadrado otro_cuadrado){
	      	return Area() > otro_cuadrado.Area();
	   	}
	   	/**
	   	 * Comprueba si el cuadrado A contiene al cuadrado B
	   	 * @see Contiene
	   	 * @param otro el otro cuadrado que queremos comparar
	   	 * @return true si lo contiene false en caso contrario
	   	 */
	   	bool Contiene(Cuadrado otro){
	      	if(!MayorArea_que(otro))
	      		return false;
	      	else if(esquina_abscisa > otro.AbscisaEsquina() || esquina_ordenada > otro.OrdenadaEsquina())
	      		return false;
	      	else if(esquina_abscisa + longitud > otro.AbscisaEsquina() + otro.Longitud() || esquina_ordenada > otro.OrdenadaEsquina())
	      		return false;
	      	else if(esquina_abscisa + longitud > otro.AbscisaEsquina() + otro.Longitud() || esquina_ordenada + longitud > otro.OrdenadaEsquina() + otro.Longitud())
	      		return false;
	      	else if(esquina_abscisa > otro.AbscisaEsquina() + otro.Longitud() || esquina_ordenada + longitud > otro.OrdenadaEsquina() + otro.Longitud())
	      		return false;
	      	else
	      		return true;
	   	}
};

/////////////////////////////////////////////////////////////////////////

int main(){
	Menu menu;
	menu.Inicio();

	double esquina_x, esquina_y, long_cuadrado;

	cout << "Introduzca la abscisa de la esquina inferior izquierda del cuadrado ";
	cin >> esquina_x;
	cout << "\nIntroduzca la ordenada de la esquina inferior izquierda del cuadrado  ";
	cin >> esquina_y;
	cout << "\nIntroduzca la longitud del cuadrado ";
	cin >> long_cuadrado;

	// Creamos el objeto cuadrado_A como un cuadrado con los datos anteriores

	Cuadrado cuadrado_A(esquina_x, esquina_y, long_cuadrado);      // Constructor usual con parámetros

	// Creamos las circunferencias inscritas y circunscritas a cuadrado_A
	// Las llamamos circunf_interior_cuadrado y circunf_exterior_cuadrado
	// Calculamos e imprimimos sus longitudes,
	// así como las áreas de los correspondientes círculos
	// Imprimimos el área de cuadrado_A

	Circunferencia circunf_interior_cuadrado = cuadrado_A.CircunferenciaInscrita();
	Circunferencia circunf_exterior_cuadrado = cuadrado_A.CircunferenciaCircunscrita();

	cout << "\nCuadrado: ";
	cout << "\nÁrea:     " << cuadrado_A.Area();
	cout << "\n\nCircunferencia interior:";
	cout << "\nLongitud:     " << circunf_interior_cuadrado.Longitud();
	cout << "\nÁrea circulo: " << circunf_interior_cuadrado.Area();

	cout << "\n\nCircunferencia exterior:";
	cout << "\nLongitud:     " << circunf_exterior_cuadrado.Longitud();
	cout << "\nÁrea circulo: " << circunf_exterior_cuadrado.Area();


	// Creamos cuadrado_B a partr de los datos introducidos para el primero
	// Imprimimos las coordenas del punto central

	Cuadrado cuadrado_B(esquina_x + 1, esquina_y + 1, long_cuadrado - 2);   // Constructor usual con parámetros

	// Obtenemos el punto central de cuadrado_B

	Punto2D centro = cuadrado_B.Centro();

	cout << "\n\nSegundo cuadrado.";
	cout << "\nCoordenadas del punto central: ";
	cout << centro.Abscisa() << " , " << centro.Ordenada();

	// Comprobamos si cuadrado_B contiene a cuadrado_A

	if (cuadrado_B.Contiene(cuadrado_A))
	  	cout << "\nCuadrado B contiene a cuadrado A";
	else
	  	cout << "\nCuadrado B no contiene a cuadrado A";

	cout << "\n\n";

	menu.Pausa();
	menu.Fin();

	// Entrada:
	// 3 2   7
	// Área: 49
	// Interior: Longitud: 21.9911, Área: 38.4845
	// Exterior: Longitud: 31.1002, Área: 76.969
	// Centro del segundo: 6.5, 5.5
	// B no contiene a A
}
