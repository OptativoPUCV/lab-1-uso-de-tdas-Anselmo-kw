#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();

   for(int k = 1 ; k <= 10 ; k++)
   {
      int* dato = (int*) malloc(sizeof(int));
      *dato = k;
      pushBack(L, dato);
   }

   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   int suma = 0;
   int* dato = first(L);
   while(dato != NULL)
   {
      suma += *dato; //puntero es cmo acceder al dato que apunta el dato
      dato = next(L);
   }

   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
   int* dato = first(L);
   while(dato != NULL)
   {
      if(*dato == elem){ //puntero es cmo acceder al dato que apunta el dato
         popCurrent(L);
      }
      dato = next(L);
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   
   Stack* pilaAux = create_stack();
   
   void* dato = top(P1);

   while(dato != NULL) 
   {
      push(pilaAux, dato);
      pop(P1);
      dato = top(P1);
   }

   void* dato2 = top(pilaAux);
   while(dato2 != NULL)
   {
      push(P1, dato2);
      push(P2, dato2);
      pop(pilaAux);
      dato2 = top(pilaAux);
   }
   
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/
// ((())) = 
int parentesisBalanceados(char *cadena) {
   //debo usar TDA pila u_u//
   int tamano = strlen(cadena);
   if(tamano % 2 == 1)
      return 0;
   
   int mitad = tamano / 2;
   /* tabla ascii
   ( = 40 / ) = 41
   [ = 91 / ] = 93
   { = 123 / } = 125
   */
   
   Stack* pilaAbre = create_stack();
   Stack* pilaCierra = create_stack();
   
   for(int i = 0 , k = tamano - 1 ; i < mitad ; i++, k--)
   {
      push(pilaAbre, &cadena[i]);
      push(pilaCierra, &cadena[k]);
   }
   
   //comparar
   void* abre = top(pilaAbre); //son solo voids
   void* cierra = top(pilaCierra);

   while(abre != NULL)
   {
      if(*(char*)cierra - *(char*)abre !=1) //aqui les asigno el dato a restar
      {
         if(*(char*)cierra - *(char*)abre != 2)
            return 0;
      }
      pop(pilaAbre);
      pop(pilaCierra);
      abre = top(pilaAbre);
      cierra = top(pilaCierra);
   }

   return 1;
}