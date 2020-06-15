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
   Se quiere construir una clase DepositoSimulacion para simular pr�stamos, ofreciendo
   la funcionalidad descrita en los ejercicios 15 (reinvierte capital e inter�s un
   n�mero de a�os) y 16 (reinvierte capital e inter�s hasta obtener el doble de la cantidad
   inicial) de la relaci�n de problemas II (p�gina RP-II.7). Por tanto, la clase debe
   proporcionar, para un capital y unos intereses dados, m�todos para:
   
   a) Calcular el capital que se obtendr� al cabo de un n�mero de a�os,
   b) Calcular el n�mero de a�os que deben pasar hasta obtener el doble de la cantidad
      inicial.
         
   A la hora de dise�ar la clase, tendremos que analizar cuestiones como:
   
    �Cu�les son sus datos miembro? Parece claro que el capital y el inter�s s� lo
      ser�n ya que cualquier operaci�n que se nos ocurra hacer con un objeto de la
      clase DepositoSimulacion involucra a ambas cantidades. �Pero y el n�mero
      de a�os?
    �Qu� constructor definimos?
    �Queremos modificar el capital y el inter�s una vez creado el objeto?
    �Queremos poder modificarlos de forma independiente?
    �Hay alguna restricci�n a la hora de asignar un valor al capital e inter�s?
    �Es mejor un m�todo para calcular el n�mero de a�os hasta obtener el doble de
      la cantidad inicial, o por el contrario es mejor un m�todo para calcular el n�mero
      de a�os hasta obtener una cantidad espec�fica?
*/

#include <iostream>
using namespace std;

   /*
   DepositoSimulacion
      - double capital
      - double interes
      - bool   EsCorrectoCapital(double un_capital)
      - bool   EsCorrectoInteres(double un_interes)
      + DepositoSimulacion(double capital_deposito, double interes_deposito)
      + double Capital()
      + double Interes()
      + void   SetCapital(double nuevo_capital)
      + void   SetInteres(double nuevo_interes)
      + double TotalObtenidoDespues_de (int anios_totales)
   */
   /*
	   Un m�todo del tipo
		   int NumeroAniosHastaObtenerElDoble()
	   es demasiado espec�fico. �Y si quiero el triple?
	   Es mucho mejor definir el m�todo
		   int NumeroAniosHastaObtener (double cantidad_objetivo)
	   y pasarle como par�metro actual la cantidad a obtener
	   (que podr� ser el doble, el triple, una cantidad exacta, etc)

   */
   int NumeroAniosHastaObtener (double cantidad_objetivo){
      double total;
      int numero_anios;

      total = capital;
      numero_anios = 0;

      while (total < cantidad_objetivo){
         numero_anios = numero_anios + 1;
         total = total + total*interes/100.0;
      }
*/


class DepositoSimulacion{
	/*
	Parece l�gico permitir cambiar el capital y el inter�s una vez creado
	el objeto, para as� poder hacer simulaciones con distintos valores.
	Adem�s, lo l�gico es cambiarlos independientemente, por lo que
	definiremos los m�todos SetCapital y SetInteres
	*/
private:
   double capital = 0.0;
   double interes = 0.0;
   
   bool EsCorrectoCapital(double un_capital){
      return (un_capital >= 0);
   }
   
   bool EsCorrectoInteres(double un_interes){
      return (0 < un_interes  &&  un_interes < 100);
   }
public:
   DepositoSimulacion(double capital_deposito, double interes_deposito)
   {
      SetCapital(capital_deposito);      
      SetInteres(interes_deposito);
   }

   double Capital(){
      return capital;
   }

   double Interes(){
      return interes;
   }

   void SetCapital(double nuevo_capital){
      if (EsCorrectoCapital(nuevo_capital))
         capital = nuevo_capital;
   }

   void SetInteres(double nuevo_interes){
      if (EsCorrectoInteres(nuevo_interes))
         interes = nuevo_interes;
   }

   double TotalObtenidoDespues_de (int anios_totales){
      double total;
      int anio;

      total = capital;

      for(anio = 1; anio <= anios_totales; anio++)
         total = total + total*interes/100.0;

      return total;
   }

   /*
	   Un m�todo del tipo
		   int NumeroAniosHastaObtenerElDoble()
	   es demasiado espec�fico. �Y si quiero el triple?
	   Es mucho mejor definir el m�todo
		   int NumeroAniosHastaObtener (double cantidad_objetivo)
	   y pasarle como par�metro actual la cantidad a obtener
	   (que podr� ser el doble, el triple, una cantidad exacta, etc)

   */
   int NumeroAniosHastaObtener (double cantidad_objetivo){
      double total;
      int numero_anios;

      total = capital;
      numero_anios = 0;

      while (total < cantidad_objetivo){
         numero_anios = numero_anios + 1;
         total = total + total*interes/100.0;
      }
      return numero_anios;
   }
};

int main(){

   double capital_deposito, interes_deposito, capital_a_obtener;
   int anios;

   cout << "Introduzca capital inicial --> ";
   cin >> capital_deposito;
   cout << "\nIntroduzca inter�s (como un %) --> ";
   cin >> interes_deposito;

   DepositoSimulacion deposito(capital_deposito, interes_deposito);

   cout << "\nCual es el n�mero de a�os que mantendr� el dep�sito --> ";
   cin >> anios;

   cout << "\n\nAl t�rmino de " << anios << " a�os, habr� obtenido " <<
            deposito.TotalObtenidoDespues_de(anios) << " euros\n";

   cout << "\nPara obtener el doble del capital inicial han de pasar "
        << deposito.NumeroAniosHastaObtener (2 * deposito.Capital()) << " a�os\n";

   cout << "\nCual es la cantidad que querr�a obtener --> ";
   cin >> capital_a_obtener;

   cout << "\n\nPara obtener " << capital_a_obtener << " euros, han de pasar " <<
           deposito.NumeroAniosHastaObtener(capital_a_obtener) << " a�os\n";

   cout << "\n\n";
   system("pause");
}

