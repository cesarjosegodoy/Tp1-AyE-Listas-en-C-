#include <iostream>
#include <stdio.h>


// TP01

        // Punto 01 - Tipificacion de Lista Enlasada ****31/05/2025****


typedef int item; // se usara item como sinonimo del tipo de variable int
const int indefinido = -999999;
struct nodo {              // Nodo
    item dato;             //campo dato
    struct nodo* sig;      //campo siguiente
};

typedef struct nodo* Lista; // se usara Lista como sinonimo de ( struct nodo* )


Lista crearLista();
bool esListaVacia(Lista L);
void mostrar (Lista L);
item primerElemento (Lista L);
Lista insertar(Lista L, item X);
Lista borrar(Lista L);
int longitud(Lista L);
bool pertenece (Lista L, item x);
Lista borrarUltimo(Lista L);
bool iguales(struct nodo *lista1, struct nodo *lista2 );



// ----- DEFINO LAS FUNCIONES DE LA LISTA ENLAZADA ------------
    
Lista crearLista(){  // Punto 02-A - Crea una Lista Vacia

    return NULL;

}

bool esListaVacia(Lista L){ // Punto 02-B - Funcion que retorna 1 si es verdadero o sea la lista esta vacia 

      if (L==NULL) {

          return true;    // Lista Vacia

      }else {

          return false;   // La lista tiene Elementos

      }

}

void mostrar (Lista L){    //Punto 02-C - Muestra por pantalla el contenido de la lista

  printf("\nLa lista es : ");
  
        while(!esListaVacia(L)) {  // Mientras no es Lista vacia 
  
            printf("\n  - %d" , L->dato);   //muestro el item del nodo
  
            L=L->sig; //apunto la cabecera de la lista al siguente nodo
  
        }
  
}

item primerElemento (Lista L){ //Punto 02-D - Retorna el valor del primer elemento de la lista

  item pElemento ;
  
         if (L == NULL) {
             printf("La lista esta vacia y no se puede mostrar ningun dato.\n");
             pElemento = indefinido;
             return pElemento;

         }else {
  
             pElemento = L->dato;
             return pElemento;
  
        }
  
  }


        
Lista insertar(Lista L, item X){ // Punto 02-E - Funcion que inserta un valor al comienzo de la lista


        Lista nuevo = new nodo; //crea dinamicamente un nuevo nodo-new struct nodo
        nuevo->dato = X; // se agrega el dato X al nodo
        nuevo->sig = L; // apunta al primner nodo de la lista
        L = nuevo;   // la cabecera apunta al nuevo nodo
        return L; // retorna la lista modificada

}

Lista borrar(Lista L){      // Punto 02-F - Funcion que borra un valor de la lista


         if (L == NULL) {

         return L;

         }else {

             nodo *aux = L;
             L = L->sig;
             delete aux;
             return L;

        }
         
}
    
int longitud(Lista L){  // Punto 02-G  - Cuenta la cantidad de elementos que tiene la lista

int cont = 0;

        if (L == NULL) {
        
        return cont;

        }else{

              while (!esListaVacia(L)) {

               
              L=L->sig;
              cont++;

             }

         return cont;

        }

}

bool pertenece (Lista L, item x){      // Punto 02-H - Pertenece determina si un valor esta en la lista

item per;

        if (esListaVacia(L))
        {
          return false; // si la lista esta vacia 
        }else {
                while (L!= NULL) {
                 per = L->dato;
                  if (per == x){
                    return true; // si el dato es encontrado retorna el valor 1
                    }else{
                    L=L->sig;
                    }
                   
              }

               return false; // si el dato no es encontrado retorna el valor 0
         }
}


        
        
Lista borrarUltimo(Lista L)  // Punto 02-I - Borra el ultimo Nodo de la lista

{  


        if (L == NULL) // si la lista  esta vacia
            { 
    
                printf("La lista esta vacia, no se pueden borrar nodos.\n"); //si esta vacia no puedo borrar un nodo
                return L;

             } 
             
        if (L->sig == NULL) // si la lista tiene un solo elemento
            { 

           delete L;
           L = NULL;
           return L;

            }

            // buscar el penultimo nodo

             nodo *aux = L;
            
        while (aux->sig->sig != NULL) 
          {

            aux =aux->sig;
              
          }
         
        // borrar el ultimo nodo

        delete aux->sig;
        aux->sig = NULL;
        return L;


}


           



