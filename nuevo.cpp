#include <iostream>
#include <stdlib.h>
using namespace std;
 
struct nodo{
       int numero;        
       struct nodo *next;
};
 
typedef struct nodo *NODO;

void Agregar(NODO &lista, int);
void Imprimir(NODO lista);
void Eliminar(NODO &lista, int valor);


int main()
{
    NODO lista = NULL;
    int opcion;     
    int _dato; 
 
    do
    {
    
	cout<<"\n ----------------MENU-----------------------\n\n";
    cout<<" 1. INSERTAR AL FINAL"<<endl;
    cout<<" 2. MOSTRAR LISTA"<<endl;
    cout<<" 3. ELIMINAR ELEMENTO"<<endl;
    cout<<" 4. SALIR"<<endl;
	cout<<"\n -------------------------------------------\n\n";
	cout<<"\n INGRESE OPCION: "<<endl;  
	cin>> opcion;
 
        switch(opcion)
        {
            case 1:
 
                 cout<< "\n NUMERO A INSERTAR: "<<endl; 
				 cin>> _dato;
                 Agregar(lista, _dato );
            break;
 
            case 2:
 
                 cout << "\n\n MOSTRANDO LISTA\n\n"<<endl;
                 Imprimir(lista);
            break;
 
            case 3:
 
                cout<<"\n Valor a eliminar: "<<endl; 
				cin>> _dato;
                Eliminar(lista, _dato);
            break;
            default: return 0;
                    }
    }while(opcion!=8);
}
 
void Agregar(NODO &lista, int valor)
{
    NODO aux2 = new struct nodo;
	NODO aux3 = new struct nodo;
 
    aux3->numero  = valor;
    aux3->next = NULL;
 
    if(lista==NULL)
    {
        lista = aux3;
    }
    else
    {
        aux2 = lista;
        while(aux2->next!=NULL)
        {
            aux2 = aux2->next;
        }
        aux2->next = aux3;
    }
 
}
 
void Imprimir(NODO lista)
{
     int contador = 0;
     while(lista != NULL)
     {
          cout <<' '<< contador+1 <<") " << lista->numero << endl;
          lista = lista->next;
          contador++;
     }
}
 
 
void Eliminar(NODO &lista, int valor)
{
    NODO puntero, pasado;
    puntero = lista;
 
    if(lista!=NULL)
    {
        while(puntero!=NULL)
        {
            if(puntero->numero==valor)
            {
                if(puntero==lista)
                    lista = lista->next;
                else
                    pasado->next = puntero->next;
                delete(puntero);
                return;
            }
            pasado = puntero;
            puntero = puntero->next;
        }
    }
    else
        cout<<"Vacia"<<endl;
}
 
 