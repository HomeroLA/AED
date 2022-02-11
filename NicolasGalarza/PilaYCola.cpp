/*Desarrolle los siguientes Subprogramas:
a-	Una función que retorne una lista sin orden a partir de la Unión de una pila y una lista.
b-	Un procedimiento que genere una lista ordenada a partir de la INTERSECCION de 2 listas.

Defina usted las estructuras de los nodos de la manera que considere más conveniente y detallar.*/



#include <iostream>
#include <mmcobj.h>


using namespace std;

struct Nodo{
    int dato;
    Nodo *next;
};

void agregarPila(Nodo *&, int );

void mostrarPila(Nodo *);

void agregarLista(Nodo *&, int );

void append(Nodo*& head_ref, int new_data);

void mostrarLista(Nodo *&);
int main() {
    Nodo *pila=new Nodo;
    pila=NULL;
    agregarPila(pila,11);
    agregarPila(pila,12);
    agregarPila(pila,13);
    mostrarPila(pila);

    Nodo *lista=new Nodo;
    /*agregarLista(lista,1);
    agregarLista(lista,3);
    agregarLista(lista,2);
    */

    append(lista,2);
    append(lista,3);
    mostrarLista(lista);


}
void agregarPila(Nodo *&pila, int a){
    Nodo *nuevoNodo=new Nodo;
    nuevoNodo->dato=a;
    nuevoNodo->next=pila;
    pila=nuevoNodo;

}

void mostrarPila(Nodo *pila){
    while(pila!=NULL){
        cout<<pila->dato<<endl;
        pila=pila->next;
    }
};

void agregarLista(Nodo *&Lista, int a){
    Nodo *nuevoNodo=new Nodo;
    nuevoNodo->dato=a;

    Nodo *aux1=Lista;
    Nodo *aux2;

    while((aux1 != NULL)&&(aux1->dato<a)){
        aux2=aux1;
        aux1=aux1->next;

    }

    if(Lista==aux1){
        Lista=nuevoNodo;
    }

    else{
        aux2->next=nuevoNodo;
    }

    nuevoNodo->next=aux1;
}

void append(Nodo*& head_ref, int new_data)
{
    /* 1. allocate node */
    Nodo* new_node = new Nodo();

    Nodo *last = head_ref; /* used in step 5*/

    /* 2. put in the data */
    new_node->dato = new_data;

    /* 3. This new node is going to be
    the last node, so make next of
    it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty,
    then make the new node as head */
    if (head_ref == NULL)
    {
        head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
    {
        last = last->next;
    }

    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}

void mostrarLista(Nodo *&Lista){
    Nodo *nuevoNodo=new Nodo();

    nuevoNodo=Lista;
    while(Lista!=NULL){
        cout<<nuevoNodo->dato<<endl;
        nuevoNodo=nuevoNodo->next;
    }
};

