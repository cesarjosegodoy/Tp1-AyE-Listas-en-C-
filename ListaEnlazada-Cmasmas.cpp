#include <stdio.h>
#include <Conio.h>
#include <stdlib.h>

// TP01

        // Punto 01 - Tipificacion de Lista Enlasada ****20/03/2025****



typedef int item; // se usara item como sinonimo del tipo de variable int

struct nodo {              // Nodo
    item dato;             //campo dato
    struct nodo* sig;      //campo siguiente
};

typedef struct nodo* Lista; // se usara Lista como sinonimo de ( struct nodo* )





        // Punto 02-A - Crea una Lista Vacia

Lista crearLista(){

    return NULL;

}


        // Punto 02-B - Funcion que retorna 1 si es verdadero o sea la lista esta vacia 

int esListaVacia(Lista L){

      if (L==NULL) {

          return 1;    // Lista Vacia

      }else {

          return 0;   // La lista tiene Elementos

      }

}

       //Punto 02-C - Muestra por pantalla el contenido de la lista

void mostrar (Lista L){

  printf("\nLa lista es : ");
  
        while(esListaVacia(L) != 0) {  // 1 = lista Vacia   1!=0   entra 
  
            printf("\n  - %d" , L->dato);  
  
            L=L->sig;
  
        }
  
}


       //Punto 02-D - Retorna el valor del primer elemento de la lista

item primerElemento (Lista L){

  item indefinido = -999999; 
  item pElemento ;
  
         if (L == NULL) {
   
             pElemento = indefinido;
             return pElemento;

         }else {
  
             pElemento = L->dato;
             return pElemento;
  
        }
  
  }


        // Punto 02-E - Funcion que inserta un valor al comienzo de la lista


Lista insertar(Lista L, item X){

        Lista nuevo; // lista nueva
        nuevo = malloc(sizeof(Lista)) ;//crea dinamicamente un nuevo nodo-new struct nodo
        nuevo->dato = X; // se agrega el dato X al nodo
        nuevo->sig = L; // apunta al primner nodo de la lista
        L = nuevo;   // la cabecera apunta al nuevo nodo
        return L; // retorna la lista modificada

}



        // Punto 02-F - Funcion que borra un valor de la lista



Lista borrar(Lista L){


         if (L == NULL) {

         return L;

         }else {

             item *aux;
             aux = L;
             L = L->sig;
             free(aux);
             return L;

        }
         
}


        // Punto 02-G  - Cuenta la cantidad de elementos que tiene la lista



int longitud(Lista L){

int cont = 0;
item var;

        if (L == NULL) {
        
        return cont;

        }else{

              while (L!=NULL) {

              var = L->dato;
              L=L->sig;
              cont++;

             }

         return cont;

        }

}

       // Punto 02-H - Pertenece determina si un valor esta en la lista


int pertenece (Lista L, item x){

item per;

        if (esListaVacia(L) == 1){

              return 0; // si la lista esta vacia retorna el valor 0

              }else {

                     while (L!= NULL) {

                     per = L->dato;

                        if (per == x){

                          return 1; // si el dato es encontrado retorna el valor 1

                        }else{
   
                          L=L->sig;

                        }

                   
                     }

                     return 0; // si el dato no es encontrado retorna el valor 0
         }

}


Lista posicionK(Lista L, item dato_buscar){

Lista actual;

for (actual = L ; actual != NULL; actual = actual->sig){

  if (dato_buscar == actual->dato){

       return actual;
  }


  

}

actual = actual->dato = -9999;
return actual;

}


// punto 2-i - Funcion que inserta un valor dado en la posicion k



Lista insertarK(Lista L, item k, item x){

int longi = longitud(L);

printf("Longitud de la lista es: %d\n",longi);
printf("Valor de K es : %d \n",k);
printf("Valor de x es : %d \n",x);

if (k <= 0 || esListaVacia(L) ){

L = insertar(L,x);
mostrar(L);
return L;

}else if (k <= longi){
  
          Lista nuevo; // lista nueva
          nuevo = malloc(sizeof(Lista)) ;//crea dinamicamente un nuevo nodo-new struct nodo
          nuevo->dato = x; // se agrega el dato X al nodo

          printf("Es menor igual a Longi\n");

        if (k ==1){

          nuevo->sig = L;
          printf("Es igual a 1\n");
          return nuevo;
          
          }
 
        if (k>1 && k<=longi){

         Lista temp = L;
          for(int i = 1; i< (k -1); i++ ){

              temp = temp->sig;

          }
          
          nuevo->sig = temp->sig;
          temp->sig = nuevo;

          printf("es mayor que 1 y menor que longi\n");

          return L;


        }


      }

  if (k>longi){

      Lista nuevo; // lista nueva
      nuevo = malloc(sizeof(Lista)) ;//crea dinamicamente un nuevo nodo-new struct nodo
      nuevo->dato = x; // se agrega el dato X al nodo
      Lista temp = L;
          for(int i = 1; i< longi; i++ ){

              temp = temp->sig;

          }
          nuevo->sig = temp->sig;
          temp->sig = nuevo;

          printf("es mayor que 1 y menor que longi\n");

          return L;

  }

 return L;

}





// funcion principal



int main(){

Lista H, P,C;

int boleano, cantidad, pert;
item pri_elemento, x;

x=122;

// creo una lista vacia

H = crearLista();
P = crearLista();
C = crearLista();


// inserto tres datos a la lista 1 , 3 y 10
H = insertar(H,22);
H = insertar(H,123);
H = insertar(H,10);

//
boleano = esListaVacia(H);

if (boleano == 0){

printf("\nLa lista esta vacia");

}else {

printf("\nLa lista no esta vacia");

}


C = posicionK(H,x);

printf("\n\n Buscar %d :::: %p",C->dato,C);


// muestra la lista

mostrar(H);

printf("\n\nLa lista tiene %i",cantidad);

cantidad = longitud(H);

printf("\n\nLa lista tiene %d",cantidad);


pri_elemento = primerElemento(H);

printf("\n\nEl primer elemento de la lista es :  %d",pri_elemento);


H = borrar(H);


cantidad = longitud(H);

printf("\n\nLa lista tiene %d",cantidad);

mostrar(H);

H = borrar(H);


cantidad = longitud(H);

printf("\n\nLa lista tiene %d",cantidad);

mostrar(H);

pert = pertenece(H,x);

if (pert == 1){

printf("\n\n El elemento %d esta en la lista \n",x);

}else{

printf("\n\n El elemento %d NO esta en la lista \n",x);

}


return 0;

}
