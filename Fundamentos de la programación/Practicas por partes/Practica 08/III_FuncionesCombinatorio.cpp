////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

/*
   Cómputo del factorial y combinatorio con funciones
*/

#include <iostream>
using namespace std;


// Precondición: 0 <= n <= 20
long long Factorial(int n){
   long long factorial;
	int  multiplicando;

	factorial = 1;

	for (multiplicando = 2; multiplicando <=n ; multiplicando++)
		factorial = factorial * multiplicando;

	return factorial;
}

/*
		El combinatorio de n sobre m nos da las formas posibles de elegir m elementos
		de un total de n, sin repetición y sin importar el orden.
		El ejemplo típico es la lotería primitiva.
*/
// Prec: 0<= n, m <= 20
int Combinatorio(int n, int m){
	long long numerador, denominador;
	int combinatorio;
	
	numerador	= Factorial(n);
	denominador = Factorial(m) * Factorial(n - m);
	combinatorio = numerador /denominador;

	return combinatorio;	
	

   /*
	// Versión eficiente:
	
	/*
		Precondición: 
			0 <= m <= 20 (suponiendo int de 32 bits)
			n y m han de ser tales que la multiplicación de los m
			números menores que n (incluido n) no se salga del rango de un long long
	*/
	
	numerador = denominador = 1;
	
	for (int i = 1 ; i <= m ; i++){
       denominador = denominador * i;
       numerador = numerador * (n - m + i);
   }

	combinatorio = numerador / denominador;

   return combinatorio;
   */
}

int main(){
	int total_a_elegir, elegidos;
	int combinatorio;

	cout << "\n\nIntroduzca total de elementos: ";
	cin >> total_a_elegir;
	cout << "\nIntroduzca cuántos va a elegir del total: ";
	cin >> elegidos;

   combinatorio = Combinatorio(total_a_elegir, elegidos);

	cout << "\nCombinaciones de " << total_a_elegir << " elementos ";
	cout << "tomados de " << elegidos << " en " << elegidos;
	cout << " = " << combinatorio;

   cout << "\n\n";
	system("pause");
}
 
