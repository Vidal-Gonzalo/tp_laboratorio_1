/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
//Pide memoria para mi linkedlist
LinkedList* ll_newLinkedList(void);

//Devuelve la cantidad de elementos de mi lista
int ll_len(LinkedList* this);

Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

//Agrega un elemento a la lista (un vagón más para la locomotora)
int ll_add(LinkedList* this, void* pElement);

//Ej: (Passenger* p) ll_add(listaPasajero, p)

//Le paso un elemento y me devuelve un índice. Usarlo como usaba el searchIndexPerId para modificar.
int ll_indexOf(LinkedList* this, void* pElement);

//Le paso un index y me devuelve el elemento de ese index. Lo mismo q arriba.
//Ej: p = (Passenger*)ll_get(listaPasajeros,0);
//Ej: for(int i = 0 ; i < ll_len(listaPasajero); i++){ll_get(listaPasajero, i);}
void* ll_get(LinkedList* this, int index);

//Sobreescribe un elemento sobre el index elegido
//Ej: ll_set(listaPasajero, 0, p);
int ll_set(LinkedList* this, int index,void* pElement);

//Elimina un nodo de la lista
int ll_remove(LinkedList* this,int index);

//Elimina todos los nodos de la lista
int ll_clear(LinkedList* this);

//Elimina toda la lista
int ll_deleteLinkedList(LinkedList* this);

//Recorre la lista para verificar cuál está limpia
int ll_isEmpty(LinkedList* this);

//Introduce un elemento en el index decidido sin eliminar la que estaba ahí
int ll_push(LinkedList* this, int index, void* pElement);

//?
void* ll_pop(LinkedList* this,int index);

//Verifica si contiene determinado elemento
int ll_contains(LinkedList* this, void* pElement);

//Verifica que dos listas sean iguales?
int ll_containsAll(LinkedList* this,LinkedList* this2);
LinkedList* ll_subList(LinkedList* this,int from,int to);
LinkedList* ll_clone(LinkedList* this);
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
