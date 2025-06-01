
#include <iostream>
#include <stdio.h>



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
    
    
    Lista borrarUltimo(Lista L)  // Punto 02-I - Borra el ultimo Nodo de la lista

{  
    if (L == NULL) 
    {
      
        return L; // si la lista esta vacia

    }

    struct nodo *aux2 = L;
    
    if (aux2->sig == NULL) 
    {
        free(L);
        return NULL; // si la lista tiene un elemento
        
    }
    
    struct nodo *aux = L;
    while (aux->sig->sig != NULL) // si la lista tiene mas de un elemento
    {
        aux = aux->sig;
    }
          
    free(aux->sig);
    aux->sig = NULL;
    return L;           
           
}


// Punto 3 - como usuario funcion iguales


int iguales(struct nodo *lista1, struct nodo *lista2 ){

  if ( primerElemento(lista1) == primerElemento(lista2)){

   return 1;


  }else{


  return 0;

  }


}
    
    
    