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


// ---- FUNCION PRINCIPAL ------

int main(){

  Lista H, P; // defino variables de tipo Lista
  
  int cantidad, pert,cantidad2;
  item pri_elemento, x,y;
  
  x=122;
  y=123;

  // creo una lista vacia
  
  H = crearLista();
  P = crearLista();
  
  
  // inserto tres datos a la lista 1 , 3 y 10
  H = insertar(H,22);
  H = insertar(H,123);
  H = insertar(H,10);
  
  // inserto tres datos a la lista 1 , 3 y 10
  P = insertar(P,22);
  P = insertar(P,123);
  P = insertar(P,10);




  //
 
  printf("01-03 - Controlo Funcion crearLista, insertar y esListavacia");


  if (!esListaVacia(H)){
  
      printf("\nLa lista no esta vacia");
      

      }else {
  
      printf("\nLa lista esta vacia");
     
  
     }
  
  
  
  printf("\n\n04 - Controlo Funcion mostrar H ");

  mostrar(H); // muestra la lista
  
  printf("\n\n05 - Controlo Funcion longitud H");

  cantidad = longitud(H);

  printf("\nLa lista H tiene %i",cantidad);
  
  printf("\n\n05 - Controlo Funcion longitud P");

  cantidad = longitud(P);
  
  printf("\nLa lista P tiene %d",cantidad);
  
  printf("\n\n06 - Controlo Funcion Primer elemento  H");

  pri_elemento = primerElemento(H);
  
  printf("\nEl primer elemento de la lista H es :  %d",pri_elemento);
 
  printf("\n\n06 - Controlo Funcion Primer elemento P");

  pri_elemento = primerElemento(P);
  
  printf("\nEl primer elemento de la lista P es :  %d",pri_elemento);

  printf("\n\n07 - controlo funcion iguales");

 if (!iguales(H,P)){

      printf("\nLa lista no son iguales");
      
 }else{

     printf("\nLa lista son iguales");

 }

 printf("\n\n08 - controlo funcion Borrar H");

  H = borrar(H);
  H = borrar(H);
  
  cantidad = longitud(H);
  
  printf("\nLa lista tiene %d",cantidad);
  
  
  mostrar(H);
   
  printf("\n\n09 - controlo funcion pertenece cuando no esta");

  pert = pertenece(H,x);
  
  if (!pert){
  
  printf("\n El elemento %d no esta en la lista \n",x);
  
  }else{
  
  printf("\n El elemento %d esta en la lista \n",x);
 

  }
  
  printf("\n\n09 - controlo funcion pertenece cuando esta");

  pert = pertenece(P,y);

  if (!pert){
  
    printf("\n El elemento %d no esta en la lista \n",y);
    
    }else{
    
    printf("\n El elemento %d esta en la lista \n",y);
    
  
    }

    printf("\n04 - Controlo Funcion mostrar");

    mostrar(P);
    

    printf("\n\n10 - controlo funcion borrarUltimo");

    P = borrarUltimo(P);
  
    cantidad2 = longitud(P);
    
    printf("\nLa lista tiene %d",cantidad2);
    
  
    mostrar(P);



  return 0;
  
  }
  

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

              while (L!=NULL) {

              item var = L->dato;
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

 int tamaño = longitud(L);


         if (L == NULL) // si la lista  esta vacia
          { 
    
             printf("La lista esta vacia, no se pueden borrar nodos.\n"); //si esta vacia no puedo borrar un nodo
             return L;

          } else 
              { 
      
                   if (tamaño = 1 )
                   {

                        nodo *aux = L;
                        L = L->sig;
                        delete aux;
                        return L;

                   }else 
                      {

                              nodo *aux2 = L; //creo un puntero aux del tipo Nodo y lo apunto a la cabecera de mi lista L

                              for (int i = 1; i = tamaño; i++)
                              {
                                  aux2 = aux2->sig;

                              }
              
                              delete aux2;
                              return L;


                       }

            


          

              }

} 
           

// Punto 3 - como usuario funcion iguales


bool iguales(struct nodo *lista1, struct nodo *lista2 )
{

    int tamañoA = longitud(lista1);
    int tamañoB = longitud(lista2);

     if (tamañoA != tamañoB) {

        return false; // las listas tienen diferente tamaño

      }

          for (int i = 0; i < tamañoA; i++)
          {
                bool iguales = false;
  
                 for (int j = 0; j < tamañoB; j++)
                  {

                     if (primerElemento(lista1) == primerElemento(lista2))
                       {
  
                         iguales = true;
              
                        }


                  }
            
                    if (!iguales)
                     {

                       return false; // si en una busqueda no se encuentra un elemento igual las listas no son iguales

                     }
           

          }

          return true; // si se encontro en todos las busquedas elementos iguales las listsa son iguales

}


