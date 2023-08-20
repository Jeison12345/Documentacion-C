#include<stdio.h>

//Creamos una fabrica de funciones (o plantilla) usando la instruccion #define:
#define FUNCTION(name, a) int fun_##name(int x) {return(a) * x;}
/*Podemos notar que la macro FUNCTION esta tomando dos argumentos
name: es el nombre que se usara para crear la función
a: es un valor que se utilizará en el cuerpo de la función para realizar un cálculo
La macro crea una función llamada 'fun_##name, donde nombre es reemplazado por el 
valor del argumento nombre. El cuerpo de la función multiplica el valor de entrada 
x por el valor a*/

FUNCTION(quadruple, 4)
FUNCTION(double, 2)

#undef FUNCTION /*Aquí anulamos la definicion anterior de la macro, por lo tanto ya no 
                se comportará como una macro que genera funciones*/
#define FUNCTION 34 /*Se redefine la macro con un valor numérico, por lo tanto ya no se
                    utilizará para generar funciones, sino que se asignara a 34*/
#define OUTPUT(a) puts(#a) /*Se define una nueva macro que toma un argumento a y lo imprime
                            usando la funcion puts. EL #a convierte el argumento en una cadena*/

int main(){
  printf("Cuadruple(13): %d\n", fun_quadruple(13));
  printf("Doble(21): %d\n", fun_double(21));
  printf("%d\n", FUNCTION); //Imprime el valor de la macro que ahora es 34
  OUTPUT(billion); //Esto equivale a puts("billion"), lo que imprimira "billion" en la salida.
}
