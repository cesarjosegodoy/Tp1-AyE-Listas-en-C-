//============================================================================
// Name        : TP1-2025.cpp
// Author      : Cristina Werenitzky
// Version     :
// Copyright   : Your copyright notice
// Description : Programa de prueba de Lista Enlazada
//============================================================================

#include<stdio.h>
#include<stdlib.h>

#include "Lista.h"


int iguales(struct nodo *lista1, struct nodo *lista2 );

int main(){

// -- PROGRAMA DE PRUEBA DE LISTA CON FUNCIONES QUE RETORNAN LA LISTA MODIFICADA

    printf("\nINICIO DEL PROGRAMA DE PRUEBA DE LISTA CON FUNCIONES QUE RETORNAN LA LISTA MODIFICADA\n");

	printf("\n1.Creo una lista, la inicializo en lista vacia y muestro la lista vacia por pantalla: ");
	Lista L;
	L = crearLista();
    mostrar(L);

    printf("\n2.Pruebo la funcion esListaVacia. Mensaje esperado 'Lista Vacia': ");
    if(esListaVacia(L))
		printf("Lista Vacia\n");
	else
	    printf("Lista NO Vacia\n");

    printf("\n3.Escribo la cantidad de elementos de una lista vacia (= 0): %d \n", longitud(L));

    printf("\n4.Escribo el valor del primer elemento de una lista vacia (= -99999): %d \n", primerElemento(L));

    printf("\n5.Inserto el valor 500 en la lista y muestro la lista por pantalla: ");
	L = insertar(L,500);
    mostrar(L);

	printf("\n6.Pruebo la funci n esListaVacia. Mensaje esperado 'Lista NO Vacia': ");
    if(esListaVacia(L))
		printf("Lista Vacia\n");
	else
		printf("Lista NO Vacia\n");

	printf("\n7.Borro un elemento de la lista y muestro por pantala. Se espera lista vacia: ");
	L = borrar(L);
	mostrar(L);

	printf("\n8.Inserto 5 elementos (10,17,22,45,74) en la lista y muestro la lista por pantalla: ");
	L = insertar(L,10);
	L = insertar(L,17);
	L = insertar(L,22);
	L = insertar(L,45);
	L = insertar(L,74);
    mostrar(L);

    printf("\n9.Escribo la cantidad de elementos de la lista (= 5): %d \n", longitud(L));

    printf("\n10.Escribo el valor del primer elemento de la lista vacia (= 74): %d \n", primerElemento(L));

	printf("\n11.Borro un elemento de la lista y muestro la lista por pantalla: ");
	L = borrar(L);
	mostrar(L);

    printf("\n12.Busco si pertenece el valor 100 en la lista. Mensaje esperado 'NO Pertenece': ");
    if(pertenece(L, 100))
		printf("Pertenece\n");
	else
	    printf("NO Pertenece\n");

    printf("\n13.Busco si pertenece el valor 22 en la lista. Mensaje esperado: 'Pertenece': ");

    if(pertenece(L, 22))
    		printf("Pertenece\n");
    	else
    	    printf("NO Pertenece\n");

    printf("\n14.Borro el ulitmo elemento de una lista vacia y muestro la lista por pantalla antes y despues de borrar:\n ");
    Lista L2 = crearLista();
    printf("\n     Lista ANTES de borrar el ultimo nodo: ");
    mostrar(L2);
    printf("\n     Lista DESPUES de borrar el ultimo nodo: ");
    L2 = borrarUltimo(L2);
    mostrar(L2);

    printf("\n15.Borro el ulitmo elemento de una lista con un único elemento y muestro la lista por pantalla antes y despues de borrar: ");
    L2 = insertar(L2, 99);
    printf("\n     Lista ANTES de borrar el ultimo nodo: ");
    mostrar(L2);
    printf("\n     Lista DESPUES de borrar el ultimo nodo: ");
    L2 = borrarUltimo(L2);
    mostrar(L2);

    printf("\n16.Borro el ulitmo elemento de una lista con varios elementos y muestro la lista por pantalla antes y despues de borrar: ");
    printf("\n     Lista ANTES de borrar el ultimo nodo: ");
    mostrar(L);
    printf("\n     Lista DESPUES de borrar el ultimo nodo: ");
    L = borrarUltimo(L);
    mostrar(L);

    L = insertar(L, 6);
    L = insertar(L, 57);
    L = insertar(L, 23);

	L2 = insertar(L2,17);
	L2 = insertar(L2,67);
	L2 = insertar(L2,45);
	L2 = insertar(L2, 6);
	L2 = insertar(L2, 57);
	L2 = insertar(L2, 23);

    printf("\n17. Muestro las listas ANTES de invocar a la funcion externa iguales: ");
    printf("\n     L: ");
    mostrar(L);
    printf("\n     L2: ");
    mostrar(L2);

    printf("\n18.Controlo si dos listas son iguales(= falso): ");


   if(iguales(&L, &L2)==1)
    	printf(" verdadero\n");
    else
    	printf(" falso\n");

    printf("\n19.Muestro las listas luego de invocar a la funcion externa iguales: ");
    printf("\n     L: ");
    mostrar(L);
    printf("\n     L2: ");
    mostrar(L2);


    printf("\n20.Libero la memoria reservada en forma din mica\n");
    while(!esListaVacia(L))
    	L = borrar(L);

    while(!esListaVacia(L2))
    	L2 = borrar(L2);

    printf("\nFIN DEL PROGRAMA DE PRUEBA DE LISTA CON FUNCIONES QUE RETORNA LA LISTA QUE RETORNAN LA LISTA MODIFICADA\n");

// -----------------------------------------------------------------------------------------------------------------------
    return 0;
}


// Punto 3 - como usuario funcion iguales



int iguales(struct nodo *lista1, struct nodo *lista2 ){

   
    if ( primerElemento(lista1) == primerElemento(lista2)){

     return 1;


    }else{


    return 0;

    }



}