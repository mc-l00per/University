//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

/*
Recupere la soluci�n del ejercicio 6 de esta relaci�n de problemas (c�mputo del sa-
lario en funci�n de las horas trabajadas) Defina una clase Nomina para gestionar el
c�mputo del salario final. Suponga que el porcentaje de incremento en la cuant�a de
las horas extras (50%) y el n�mero de horas que no se tarifan como extra (40) son
valores que podr�an cambiar, aunque no de forma continua. El n�mero de horas tra-
bajadas y la cuant�a a la que se paga cada hora extraordinaria, s� son cantidades que
var�an de un trabajador a otro.
*/

/*
A un trabajador le pagan seg�n sus horas trabajadas y la tarifa est� a un valor por
hora. Si la cantidad de horas trabajadas es mayor de 40 horas, la tarifa por hora se
incrementa en un 50% para las horas extras (las que haya por encima de 40). Construir
una funci�n que dado el n�mero total de horas trabajadas y el precio por hora,
devuelva el salario del trabajador.
*/

#include <iostream>
using namespace std;

double AplicaPorcentaje (double cantidad, int porcentaje){
   return cantidad + cantidad * porcentaje / 100.0;
}

/*
   Asociaremos cada objeto de la clase Nomina con unos valores concretos
   de BASE_HORAS_EXTRA y PORCENTAJE_AUMENTO_HORAS_EXTRA.
   �stos ser�n los datos miembro.
   
   Una vez fijados esos valores en el constructor, llamamos
   al m�todo Salario con distintos valores de  
   horas_trabajadas y salario_por_hora (par�metros al m�todo)
   
   Si otra delegaci�n de la empresa considerase otros valores de
   BASE_HORAS_EXTRA y PORCENTAJE_AUMENTO_HORAS_EXTRA,
   bastar�a crear otro objeto asociado a dicha delegaci�n y pasar�amos
   en el constructor los valores pertinentes.
   
   Hemos considerado que el n�mero de horas trabajadas y a lo que se paga
   cada una de ellas son datos que suelen variar bastante. Por eso, se han
   pasado como par�metros al m�todo Salario. Si a lo que se paga cada hora
   fuese un dato fijo por delegaci�n, tambi�n lo pondr�amos como dato miembro.
   
   En definitiva:
      - Los datos miembro est�n asociados a propiedades o valores que
         no suelen cambiar mucho durante la vida del objeto
      - Los par�metros de los m�todos est�n asociados a valores que suelen
         variar bastante de una ejecuci�n a otra del m�todo.
   
   Nomina
      - const int BASE_HORAS_EXTRA
      - const int PORCENTAJE_AUMENTO_HORAS_EXTRA
      + Nomina(int base_horas_extra, int porcentaje_aumento_horas_extra)
      + int BaseHorasExtra()
      + int PorcentajeAumentoHorasExtra()
      + double Salario(double horas_trabajadas, double salario_por_hora)
*/

class Nomina{
private:
   const int BASE_HORAS_EXTRA;
   const int PORCENTAJE_AUMENTO_HORAS_EXTRA;
public:
   Nomina(int base_horas_extra, int porcentaje_aumento_horas_extra)
      :BASE_HORAS_EXTRA(base_horas_extra) , 
       PORCENTAJE_AUMENTO_HORAS_EXTRA(porcentaje_aumento_horas_extra)
   {      
   }
   
   int BaseHorasExtra(){   
      return BASE_HORAS_EXTRA;
   }

   int PorcentajeAumentoHorasExtra(){   
      return PORCENTAJE_AUMENTO_HORAS_EXTRA;
   }
   
   double Salario(double horas_trabajadas, double salario_por_hora){
      double salario;     

      if (horas_trabajadas > BaseHorasExtra()){
         salario = BaseHorasExtra() * salario_por_hora +
                   AplicaPorcentaje( (horas_trabajadas - BaseHorasExtra()) * 
                                      salario_por_hora , 
                                      PorcentajeAumentoHorasExtra());                
      }
      else
         salario = horas_trabajadas * salario_por_hora;
      
      return salario;   
   }
};


int main(){
   double horas_de_trabajo, a_pagar_por_hora, salario_final;
   double porcentaje_aumento_horas_extra, base_horas_extra;
   
   cout << "C�mputo del salario en funci�n de las horas trabajadas. \n\n";
   
   cout << "\nIntroduzca el porcentaje de aumento en el pago de las horas extra: ";
   cin >> porcentaje_aumento_horas_extra;
   cout << "\nIntroduzca el n�mero de horas a partir del cual se considera que son horas extra: ";
   cin >> base_horas_extra;
   
   Nomina nomina(base_horas_extra, porcentaje_aumento_horas_extra);
   
   // Podr�amos tener otros objetos n�mina:
   // Nomina nomina_Jaen (30, 65);
   // Nomina nomina_Granada (50, 25);
   // ......
   
   cout << "\n\nIntroduzca n�mero de horas trabajas: ";
   cin >> horas_de_trabajo;
   cout << "\nIntroduzca el salario por hora: ";
   cin >> a_pagar_por_hora;
   
   salario_final = nomina.Salario(horas_de_trabajo, a_pagar_por_hora);
   
   cout << "\n\nSalario Final: " << salario_final;
}
