/**
 * ////////////////////////////////////////////////////////////////////////////
 * //
 * // Fundamentos de Programación
 * // ETS Informática y Telecomunicaciones
 * // Universidad de Granada
 * // Departamento de Ciencias de la Computación e Inteligencia Artificial
 * // Autor: Juan Carlos Cubero
 * // Version: 1.2 ==> Autor: Antonio Rodríguez Alaminos
 * //
 * ////////////////////////////////////////////////////////////////////////////
 *
 */

/**
 * Dependencias necesarias para que el programa funciones correctamente
 */
#include <iostream>
#include <unistd.h>  //para poder utilizar el usleep y otros comandos

using namespace std;

/**
 * Clase secuencia de reales, cotiene toda la informacion para poder trabajar con ellos
 * @see SecuenciaReales
 */
class SecuenciaReales{

   private:
      static  const  int  TAMANIO  =  50;
      double  vector_privado[TAMANIO];
      int  total_utilizados;

   public:
      /**
       * Constructor por defecto
       * @see SecienciaReales
       */
      SecuenciaReales() :total_utilizados(0) {

      }
      /**
       * Muestra el tamaño real de la secuencia de caracteres
       * @see TotalUtilizados
       * @return El tamaño real utilizado por la secuencia
       */
      int TotalUtilizados(){
         return  total_utilizados;
      }
      /**
       * Añadir un real nuevo
       * @see Aniade
       */
      void  Aniade(double  nuevo){
         if (total_utilizados  <  TAMANIO)
         {
            vector_privado[total_utilizados]  =  nuevo;
            total_utilizados++;
         }
      }
      /**
       * Muestra el elemento de una posicion
       * @see Elemento
       * @param indice Posicion del elemento que queremos mostrar
       * @return Valor que contiene la secuencia de reales en la posicion indicada
       */
      double Elemento(int  indice){
         return  vector_privado[indice];
      }
      /**
       * Modificaar un valor de la secuencia de reales dependiendo de la posicion deseada
       * @see Modifica
       * @param indice_componente Posicion donde se encuentra el valor que queremos modificar
       * @param nuevo Valor que deseamos almacenar
       */
      void Modifica(int indice_componente, double nuevo){
         if (indice_componente >= 0  &&  indice_componente < total_utilizados)
            vector_privado[indice_componente] = nuevo;
      }
      /**
       * Eliminar todos los datos de la secuencia
       * @see EliminarTodos
       */
      void EliminaTodos(){
         total_utilizados = 0;
      }
      /**
       * Obtener el primero que es igual que el valor buscado
       * @see PrimeraOcurrenciaEntre
       * @param pos_izd Posicion de la izquierda
       * @param pos_dcha Posicion de la derecha
       * @param buscando el valor que estamos buscando
       * @return i posicion del valor que estamos buscando
       */
      int PrimeraOcurrenciaEntre(int pos_izda, int pos_dcha, double buscado){
         int i = pos_izda;
         bool encontrado = false;

         while (i <= pos_dcha  &&  !encontrado)
            if (vector_privado[i] == buscado)
               encontrado = true;
            else
               i++;

         if (encontrado)
            return i;
         else
            return -1;
      }
      /**
       * Busca una ocurencia pasando como parametro con quien comparar
       * @see PrimeraOcurrencia
       * @param buscando Parametro que estamos buscando
       * @retrun El primer valor que coincide con el que estamos buscando
       */
      int PrimeraOcurrencia (double buscado){
         return PrimeraOcurrenciaEntre(0, total_utilizados - 1, buscado);
      }
      /**
       * Ordena el vector por orden de insercion
       * @see Ordena_por_Insercion
       */
      void Ordena_por_Insercion(){
         int izda, i;
         int a_desplazar;

         for (izda = 1; izda < total_utilizados; izda++){
            a_desplazar = vector_privado[izda];

            for (i = izda; i>0 && a_desplazar < vector_privado[i-1]; i--)
               vector_privado[i] = vector_privado[i-1];

            vector_privado[i] = a_desplazar;
         }
      }
};

/////////////////////////////////////////////////////////////////////////

/**
 * Para obligar a que una matriz sea cuadrada,
 * lo podemos hacer de varias formas. Por ejemplo:
 *  
 *	a) En el constructor de la matriz pasamos el número de columnas que
 *     tendrán todas las filas de la amtriz.
 *     
 *	b) En el constructor de la matriz pasamos una primera fila.
 *    La longitud actual de dicha fila será el valor que
 *    determine el número de columnas de todas las filas. 
 *     
 *	Para permitir ambas formas, sobrecargamos el constructor.
 *	
 *	En cualquier caso, es importante destacar que la matriz no
 *	estará en un estado válido hasta que se hayan añadido
 *	todas las filas, ya que es una matriz cuadrada.
 *	Para paliar este problema, añadimos un método EsCuadrada
 *	que nos dice si la matriz es cuadrada en un momento determinado.
 */

/////////////////////////////////////////////////////////////////////////

/**
 * Matriz con los datos de los reales cuadrados
 * @see MatrizCuadradaReales
 */
class MatrizCuadradaReales{

   private:
      static const int MAX_FILAS_COLUMNAS = 40;
      double matriz_privada[MAX_FILAS_COLUMNAS][MAX_FILAS_COLUMNAS];
      int util_fil_col = 0;
      int indice_ultima_fila_aniadida = -1;
      /**
       * Añade los valores a una fila
       * @see AsignaFila
       * @param fila la fila que queremos ingresar
       * @param indice_fila posicion de la fila que queremos añadir
       */
      void AsignaFila (SecuenciaReales fila, int indice_fila){
         for (int i=0; i < util_fil_col; i++)
            matriz_privada[indice_fila][i] = fila.Elemento(i);
      }

   public:
      /**
       * Constructor por defecto
       * @see MatrizCuadradaReales
       * @param primera_fila fila que queremos añadir
       */
      MatrizCuadradaReales(SecuenciaReales primera_fila) :util_fil_col(primera_fila.TotalUtilizados()) {
         AniadeFila(primera_fila);
         indice_ultima_fila_aniadida = 0;
      }
      /**
       * Añadir los datos de matri cuadrada reales
       * @see MatrizCuadradaReales
       * @param numero_columnas Numero de columnas total utilizadas
       */
   	MatrizCuadradaReales(int numero_columnas) :util_fil_col(numero_columnas) {
      }
      /**
       * Mostrar el elemnto de la posicion deseada
       * @see Elemento
       * @param fil fila donde se encuentra el objeto que queremos mostrar
       * @paraam col Columna donde se encuentra el valor que queremos mostrar
       * @retrun Muestra el valor de la posicion que acabamos de pasarle
      */
      double Elemento (int fil, int col){
         return matriz_privada[fil][col];
      }
      /**
       * Numero de filas y columnas
       * @see NumeroFilas_y_Columnas
       * @return el total de filas y columnas utilizadas
       */
      int NumeroFilas_y_Columnas(){
         return util_fil_col;
      }
      /**
       * Muestra si la matriz es una matriz cuadrada
       * @see EsCuadrada
       * @param true si es cuadrada false en caso contrario
       */
      bool EsCuadrada(){
         return util_fil_col == indice_ultima_fila_aniadida + 1;
      }
      /**
       * Añade los elementos de una fila
       * @see AniadeFila
       * @param nueva_fila la fila que queremos introducir
       */
      void AniadeFila(SecuenciaReales nueva_fila){
         if (indice_ultima_fila_aniadida < MAX_FILAS_COLUMNAS){
            if (nueva_fila.TotalUtilizados() == util_fil_col){
               indice_ultima_fila_aniadida++;
               AsignaFila(nueva_fila, indice_ultima_fila_aniadida);
            }
         }
      }
      /**
       * Devuelve una fila
       * @see Fila
       * @param indice_fila el indice de la fila que queremos copiar
       * @return fila que queremos obtener
       */
      SecuenciaReales Fila(int indice_fila){
         SecuenciaReales fila;
         
         for (int i=0; i < util_fil_col; i++){
            fila.Aniade(matriz_privada[indice_fila][i]);
         }
         return fila;
      }
      void AniadeElemento(int fil, int col, double valor){
        matriz_privada[fil][col] = valor;
      }
      /**
       * Obtener la matriz suabizada
       * @see SuavizadaPromedio
       * @return la matriz suabizada
       */
      MatrizCuadradaReales SuavizadaPromedio(){
         /*
            Algoritmo Suavizada Promedio

            Recorrer todas las filas -i- de la matriz original
               Asignar el mismo elemento de la diagonal principal

               Recorrer las columnas -j- desde la última hasta i
                  Ir acumulando en una variable suma
                  el sumatorio de los m[i][j]
                  Asignar media correspondiente a la componente ij y a la ji
         */

         //......
        double suma, contador;
        MatrizCuadradaReales suavizada(util_fil_col);

        for(int i=0, j=1; i<NumeroFilas_y_Columnas(); i++, j++){
          for(int x=j; x<NumeroFilas_y_Columnas(); x++){ 
            suma = 0;
            contador = 0;
            for(int z=x; z<NumeroFilas_y_Columnas(); z++){
              suma += Elemento(i,z);
              contador++;
            }
            suavizada.AniadeElemento(i,x,suma/contador);
            suavizada.AniadeElemento(x,i,suma/contador);
          }
        }

        //primero introducimos los datos de la  diagonal que son iguales
        for(int i=0; i<util_fil_col; i++){
          suavizada.AniadeElemento(i,i, Elemento(i,i));
        }

        return suavizada;
      }
};

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

int main(){
   int util_filas_matriz, util_filas_suavizada;
   double valor;
   SecuenciaReales fila;
   Menu menu;

   menu.Inicio();
   // No etiquetamos las entradas porque suponemos que leemos de un fichero
   // Supondremos que util_filas > 0

   cin >> util_filas_matriz;
   
   MatrizCuadradaReales matriz(util_filas_matriz);

   for (int i=0; i<util_filas_matriz; i++){
      for (int j=0; j<util_filas_matriz; j++){
         cin >> valor;
         fila.Aniade(valor);
      }
      
      matriz.AniadeFila(fila);
      fila.EliminaTodos();
   }

   if (matriz.EsCuadrada()){
      //<Crear aquí la matriz suavizada>
      //.......
      MatrizCuadradaReales suavizada(matriz.NumeroFilas_y_Columnas());
      suavizada = matriz.SuavizadaPromedio();
      util_filas_suavizada = suavizada.NumeroFilas_y_Columnas();
   
      cout << "\n\n";
      cout << "Matriz suavizada:\n";

      for (int i=0; i<util_filas_suavizada; i++){
         cout << "\n";

         for (int j=0; j<util_filas_suavizada; j++)
            cout << suavizada.Elemento(i,j) << '\t';
      }
   }
  
   cout << "\n\n";
   menu.Pausa();
   menu.Fin();
   // Entrada:
   // 4   9 7 4 5    2 18 2 12    7 9 1 5   0 1 2 3
   
   // Salida:
   /*
   9       5.33333 4.5     5
   5.33333 18      7       12
   4.5     7       1       5
   5       12      5       3
   */
}
 
