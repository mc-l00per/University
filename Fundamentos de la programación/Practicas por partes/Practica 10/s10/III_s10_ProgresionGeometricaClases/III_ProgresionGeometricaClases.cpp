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
   Definid una clase para representar una progresi�n geom�trica.

   a) Dise�ad la clase pensando cu�les ser�an los datos miembro esenciales que definen
      una progresi�n geom�trica, as� como el constructor de la clase.
   b) Definid los m�todos SumaHastaInfinito, SumaHasta, MultiplicaHasta.
   c) Cread un programa principal que llame a los anteriores m�todos.
*/


#include <iostream>
#include <cmath>
using namespace std;
	/*
	Un objeto del concepto (clase) "Progresi�n geom�trica" queda completamente determinado por el
	primer t�rmino y la raz�n. Esos ser�n sus �nicos datos miembro.
   Los pasamos como par�metros al constructor para tener el objeto en un estado v�lido
   en el momento de su definici�n. 

	�Qu� funcionalidad -m�todos- podemos definir para esta clase?
	- Sumar hasta un tope todos los t�rminos de la progresi�n
	- Obtener el t�rmino n-�simo de la progresi�n
	- .....

	En el dise�o de esta clase se ha decidido que, una vez creado el objeto,
	no se pueda cambiar ni el primer t�rmino ni la raz�n de la progresi�n.
	En caso contrario, habr�a que a�adir los m�todos correspondientes
		SetRazon
		SetPrimerTermino
	*/
   /*
   Este ejercicio muestra la facilidad de uso de las clases.
   Con funciones, tendr�amos que crear las funciones siguientes:
			double SumaHasta(double primer_termino_progresion, double razon_progresion, int k)
			double Termino(double primer_termino_progresion, double razon_progresion, int k)
			double ProductoHasta(double primer_termino_progresion, double razon_progresion, int k)
			double SumaHastaInfinito(double primer_termino_progresion, double razon_progresion)
   Y cada vez que necesit�semos calcular algo, tendr�amos que volver a pasar los dos par�metros
   iniciales primer_termino_progresion y razon_progresion
   
   Con clases, le asignaremos unos valores de primer t�rmino y raz�n
   en el constructor:
      ProgresionGeometrica prog(5, 3);
   y con esos valores vamos llamando a los m�todo:
      cout << prog.Termino(4);
      cout << prog.Termino(5);
      cout << prog.SumaHasta(8);
      cout << prog.SumaHastaInfinito();
      ......
   */

/*
   ProgresionGeometrica
      - double primer_termino
      - double razon
      + ProgresionGeometrica(double primer_termino_progresion, 
                             double razon_progresion)
      + double PrimerTermino()
      + double Razon()
      + double Termino(int k)
      + double SumaHasta(int k)
      + double SumaHastaInfinito()
      + double ProductoHasta(int k)      
*/

class ProgresionGeometrica{
private:
   double primer_termino;
   double razon;
public:
   ProgresionGeometrica(double primer_termino_progresion, double razon_progresion){
      primer_termino = primer_termino_progresion;
      razon = razon_progresion;
   }

   double PrimerTermino(){
      return primer_termino;
   }

   double Razon(){
      return razon;
   }

	// Precondici�n: k > 0. Tambi�n podr�amos haber usado un tipo unsigned int
   double Termino(int k){
      /*
      Para calcular el t�rmino k-�simo, 
      o bien usamos directamente la f�rmula:
         return primer_termino * pow(razon, k-1);
      o bien lo calculamos con un bucle.
      Ambas implementaciones ser�an correctas.
      */
		double termino = primer_termino;

		for (int i=2; i<=k; i++)
			termino = termino * razon;

		return termino;
   }
  
   /*
      Si opt�semos por eliminar la precondici�n, podr�amos devolver un valor
      especial en el caso de que nos pasasen un valor de k err�neo.
      Por ejemplo, devolver indeterminaci�n.
      
      Las dos soluciones -comprobar la precondici�n o no comprobarla-
      ser�an correctas. Si tenemos previsto llamar intensivamente a
      este m�todo podr�amos optar por no comprobar la precondici�n.
   */
   /*
   double Termino(int k){
      double termino = primer_termino;
      
      if (k > 0){
   		for (int i=2; i<=k; i++)
   			termino = termino * razon;
      }    
      else{
         double indet = 0.0;
			termino = indet / indet;     // Indeterminaci�n
      }  
      
		return termino;
   }
   */


	// Precondici�n: k > 0	
	double SumaHasta(int k){
		double suma;

		suma = primer_termino;

		for (int i = 2; i <= k; i++)
			suma = suma + Termino(i);

		return suma;
	}

	// Versi�n de SumaHasta aplicando directamente la f�rmula correspondiente:
	/*
	// Precondici�n: k > 0
   double SumaHasta(int k){
      return primer_termino * (pow(razon,k) - 1) / (razon - 1);
   }
	*/
	

   double SumaHastaInfinito(){
      double suma;
      int denominador = 0;

      if (fabs(razon) <= 1)
         suma = primer_termino / (1 - razon);
      else
         suma = 1.0 / denominador;    //  Devuelve infinito

      return suma;
   }

	// F�rmula de ProductoHasta(h) = sqrt(pow(a_1 * a_k , k))
	// �Pasamos como par�metro el valor de a_k al m�todo ProductoHasta?
	//		double ProductoHasta(int k, double ak)
	// La respuesta es que NO.
	// Si lo hici�semos, el correcto funcionamiento de ProductoHasta DEPENDER�A
	// de que en la llamada, le pasen el correcto valor de a_k 
	// Cada m�todo debe ser responsable de realizar sus c�mputos correctamente
	// y no delegar en la llamada a que en ella se realicen otras acciones
	// necesarias iniciales para que funcione correctamente.

	// Precondici�n: k > 0
   double ProductoHasta(int k){
      return sqrt( pow(primer_termino * Termino(k) , k));
   }
};



/*
	AMPLIACI�N:

	El c�mputo de Termino(k) se ha realizado de la forma siguiente:
	
	O bien aplicando la f�rmula directamente con pow:

		double Termino(int k){
			return primer_termino * pow(razon, k-1);
		}
	
	O bien realizando los c�mputos en un bucle:

		double Termino(int k){
			double termino = primer_termino;

			for (int i=2; i<=k; i++)
				termino = termino * razon;

			return termino;
	   }

	Si desde el main queremos, por ejemplo, imprimir los 20 primeros valores:

	int main(){
		ProgresionGeometrica progresion(2,5);
			for (int i=0; i<20; i++)
				cout << progresion.Termino(i);
	
	Cada llamada a progresion.Termino(i) implica volver a hacer las mismas operaciones una y otra vez.
	Por lo tanto, hubiese sido m�s eficiente haber usado la expresi�n   
      termino_k = termino_(k-1) * r
   que calcular el t�rmino k-�simo en funci�n del t�rmino (k-1)-�simo
	
	�C�mo lo hacemos?
	La forma m�s sencilla es proporcionar otro m�todo llamado Next() de forma que
	cada vez que se llame, devuelva el siguiente t�rmino al generado la �ltima vez con el propio Next()
	Ser�a como un "iterador" que va recorriendo los elementos de la progresi�n geom�trica.

	Habr�a dos formas de implementar este m�todo:

	1. A�adiendo un dato miembro:
			double ultimo_termino_calculado;
		El m�todo Next quedar�a:

		double Next(){
			ultimo_termino_calculado = ultimo_termino_calculado * razon;

			return ultimo_termino_calculado;
		}

	2. Mejor a�n, para no tener que a�adir otro dato miembro, podr�amos
	   usar una variable est�tica. 
		Las variables est�ticas son variables locales a una funci�n (o m�todo)
		cuyo contenido se mantiene entre distintas llamadas a dicha funci�n (o m�todo)

			double Next(){
				static double ultimo_termino_calculado = primer_termino;

				ultimo_termino_calculado = ultimo_termino_calculado * razon;

				return termino;
			}
	
	Nota. 
		La clase ofrecer�a un m�todo
			Termino(k)
		para devolver el t�rmino k-�simo directamente
		y otro m�todo
			Next()
		para devolver el siguiente al generado en la llamada anterior a Next()
		Debe quedar claro en la documentaci�n que la llamada a Termino(k)
		no influye en la salida que da el m�todo Next() cada vez que se llama,
      es decir, que se invocan de forma independiente.
*/
class ProgresionGeometrica_Optimizada_AMPLIACION{
private:
   double primer_termino;
   double razon;
public:
   ProgresionGeometrica_Optimizada_AMPLIACION(double primer_termino_progresion, double razon_progresion){
      primer_termino = primer_termino_progresion;
      razon = razon_progresion;
   }

   double PrimerTermino(){
      return primer_termino;
   }

   double Razon(){
      return razon;
   }
   
   // Devuelve el siguiente t�rmino de la progresi�n.
	double Next(){
		static double termino = primer_termino;

		termino = termino * razon;

		return termino;
	}
	
	// AMPLIACI�N (2)
	// En la versi�n anterior, cuando se ha creado el objeto progresi�n,
	// la primera llamada a Next devuelve el siguiente al primer t�rmino
	// Esto es correcto. En cualquier caso, si hubi�semos querido que
	// la primera llamada a Next devuelva el primer elemento de la progresi�n
	// tendr�amos que haberlo programado como sigue:
	
   //	double Next(){
   //	   static bool primera_vez = true;
   //		static double termino = primer_termino;
   //
   //      if (primera_vez)
   //         primera_vez = false;
   //      else
   //         termino = termino * razon;
   //
   //		return termino;
   //	}
	
	// Precondici�n: k > 0
   double Termino(int k){
		return primer_termino * pow(razon, k-1);
   }

	// Otra versi�n de SumaHasta
	/*
		double SumaHasta(int k){
			double suma;

			suma = primer_termino;

			for (int i = 2; i <= k; i++)
				suma = suma + Termino(i);

			return suma;
		}
	*/

		
	// Precondici�n: k > 0
   double SumaHasta(int k){
      return primer_termino * (pow(razon,k) - 1) / (razon - 1);
   }

   double SumaHastaInfinito(){
      double suma;
      int denominador = 0;

      if (abs(razon) <= 1)
         suma = primer_termino / (1 - razon);
      else
         suma = 1.0 / denominador;    //  Devuelve infinito

      return suma;
   }

	// Precondici�n: k > 0
   double ProductoHasta(int k){
      return sqrt( pow(primer_termino * Termino(k) , k));
   }
};


int main(){
   double primer_termino, razon;
   int tope;

   cout << "\nIntroduzca el primer t�rmino de la progresi�n ";
   cin >> primer_termino;
   cout << "\nIntroduzca la raz�n de la progresi�n ";
   cin >> razon;

   ProgresionGeometrica progresion(primer_termino, razon);
   
   cout << "\nIntroduzca el �ndice del �ltimo t�rmino ";
   cin >> tope;   
   
   cout << "\nSuma hasta " << tope << " = "  << progresion.SumaHasta(tope);
   cout << "\nSuma hasta infinito" << " = "  << progresion.SumaHastaInfinito();
   cout << "\nProducto hasta " << tope << " = " << progresion.ProductoHasta(tope);
   cout << "\n\nLos " << tope << " primeros t�rminos de la serie son\n";

   for (int i = 1; i <= tope; i++)
      cout << progresion.Termino(i) << "\n";

   //////////////////////////////////////////////////////////////////////////////////
   
	ProgresionGeometrica_Optimizada_AMPLIACION progresion_optima(primer_termino, razon);

	cout << "\n\n" << progresion_optima.PrimerTermino(); 

	for (int i = 2; i <= tope; i++)
      cout << "\n" << progresion_optima.Next();
	

   cout << "\n\n";
   system("pause");
}
