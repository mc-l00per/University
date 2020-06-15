////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

/*
   Gaussiana con una clase
*/

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1415927;


//	Potencia de un n�mero elevado a un entero.
double Potencia(double la_base, int el_exponente){
	double potencia;
	int exponente_positivo;

	if (la_base == 0 && el_exponente == 0)
		potencia = sqrt (-1.0);						   // Devuelve NaN (Indeterminaci�n)
	else{
		exponente_positivo = abs(el_exponente);
		potencia = 1;								   

		for (int i = 1; i <= exponente_positivo; i++)
			potencia = potencia * la_base;
	}

	if (el_exponente < 0)
		potencia = 1/potencia;

	return potencia;
}

// La funci�n gaussiana es la conocida distribuci�n Normal en Estad�stica
// Viene definida por dos par�metros: esperanza y desviaci�n. �stos ser�n sus datos miembro

/*
   Gaussiana
      - double esperanza
      - double desviacion
      + Gaussiana(double esperanza_gaussiana, double desviacion_gaussiana)
      + double Esperanza()
      + double Desviacion()
      + double Evalua(double abscisa)
      + double AreaHasta(double x)      
*/

class Gaussiana{
private:
	double esperanza;
	double desviacion;

public:
	Gaussiana(double esperanza_gaussiana, double desviacion_gaussiana){
		esperanza = esperanza_gaussiana;
		desviacion = desviacion_gaussiana; 
	}

	double Evalua(double x){
		return exp(- (pow((x - esperanza)/desviacion , 2)) / 2) /
	          (desviacion * sqrt(2*PI));
	}

	// AreaHasta = �rea desde -infinito hasta x. 
	// Tambi�n conocida como CDF (cumulative distribution function)
	double AreaHasta(double x){
		// Aproximaci�n dada por Zelen & Severo (1964)  
		// -ver Wikipedia (Normal distribution) para otras aproximaciones-	
		
		// Los coeficientes b s�lo se necesitan dentro del m�todo AreaHasta,
		// por lo que ser�n locales a �l. No tiene sentido declararlos
		// fuera (ni como constantes globales, ni como datos miembro)
		// Tampoco ser�a correcto pasarlos como par�metros ya que entonces en CADA llamada habr�a
		// que pasar dichos valores y por tanto se podr�a pasar por error un valor incorrecto

		const double b0 = 0.2316419, b1 = 0.319381530, b2 = -0.356563782, b3 = 1.781477937, b4 = -1.821255978, b5 = 1.330274429;
		double area_hasta;
		double t;

		t = 1 / (1 + b0*x);
		area_hasta = 1 - Evalua(x) * (b1*t + b2*t*t + b3*t*t*t + b4*t*t*t*t + b5*t*t*t*t*t);

		return area_hasta;
	}

	double Esperanza(){
		return esperanza;
	}
	double Desviacion(){
		return desviacion;
	}
};


int main(){
   double abscisa, ordenada;
	double esperanza, desviacion;
	double area;
	int numero_puntos;

	cout << "\nIntroduzca el valor del par�metro 'esperanza' : ";
	cin >> esperanza;
	cout << "\nIntroduzca el valor del par�metro 'desviacion' : ";
	cin >> desviacion;	
	cout << "\nIntroduzca el n�mero de puntos que va a considerar: ";
	cin >> numero_puntos;
	cout << "\nIntroduzca los " << numero_puntos << " valores de la abscisa: ";
	
   // Importante: El objeto se crea una s�la vez, 
   // antes de entrar al siguiente bucle
   
   Gaussiana funcion_densidad_normal(esperanza, desviacion); 
   	
   	
	for (int i=0; i<numero_puntos; i++){
	   cout << "\n\n";
	   cin >> abscisa;	
	   
      ordenada  = funcion_densidad_normal.Evalua(abscisa);
      area	    = funcion_densidad_normal.AreaHasta(abscisa);
      
      cout << "\ngaussiana(" << abscisa << ")= " << ordenada;
      cout << "\nCDF(" << abscisa << ")= " << area;
   }
   
	cout << "\n\n";
}
