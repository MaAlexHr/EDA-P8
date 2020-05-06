/*PROGRAMADOR Hernandez Rojas Mara Alexandra
 * EDA I	Grupo 13
 * Practica 8 Listas ligadas
 */
#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"
#include "dlistc.h"

int main(){
    printf("\n\t\tHernandez Rojas Mara Alexandra EDA I grupo 13\n\n\t\tPractica 8 Listas Doblemente Ligadas\n");
    dlist *l;
    dlistc *c;
    int a, g;
    DATA b, h;
    dnode *t, *i;

    printf("\nLista Doblemente Ligada\n");
    printf("\nFuncioines para crear e insertar en la lista\n");
    l = create_dlist();
    insert_dlist(l, 0, 0);
    print_dlist(l);//[0]
    insert_dlist(l, 2, 1);
    print_dlist(l);//[0][2]
    insert_dlist(l, 1, 2);
    insert_dlist(l, 3, 1);
    print_dlist(l);//[0][3][2][1]
    printf("\nFuncioines para buscar\n");
    a = locate_dlist(l, 2);
    printf("\n locate_dlist() encontro el dato '2' en la pos %d",a);//[2]
    b = search_dlist(l, 1);
    printf("\n search_dlist() ubico el dato %d en la pos '1' ",b);//[3]
    t = search_dnode_dlist(l, 3);
    printf("\n search_dnode_dlist() devuelve un apuntador al nodo en pos '3' de la lista\n\t\t direccion apuntada %p \n", t);//Direccion de memoria
    printf("\nFuncionies para remover\n");
    remove_pos(l, 1);
    print_dlist(l);//[0][2][1]
    remove_pos(l, 1);
    print_dlist(l);//[0][1]
    delete_data(l, 0);
    print_dlist(l);//[1]
    empty_dlist(l);
    remove_dlist(l);
    l = NULL;

    printf("\nLista Doblemente Ligada Circular\n");
    printf("\nFuncioines para crear e insertar en la lista\n");
    c = create_dlist_c();
    insert_dlist_c(c,4,0);
    print_dlist_c(c);//[4]
    insert_dlist_c(c, 3, 1);
    print_dlist_c(c);//[4][3]
    insert_dlist_c(c, 2, 2);
    insert_dlist_c(c, 5, 1);
    print_dlist_c(c);//[4][5][3][2]
    printf("\n Funciones para buscar\n");
    g = locate_dlist_c(c,5);
    printf("\n locate_dlist_c() ubico el dato '5' en la pos %d ",g);//[1]
    h = search_dlist_c(c,2);
    printf("\n search_dlist_c() ubico el dato %d en la pos '2' ",h);//[3]
    i = search_dnode_dlist_c(c, 3);
    printf("\n search_dnode_dlist_c() devuelve un apuntador al nodo en pos '3' de la lista\n\t\t direccion apuntada %p \n", i);//Direccion de memoria
    printf("\nFuncionies para remover\n");
    remove_pos_c(c, 1);
    print_dlist_c(c);//[4][3][2]
    remove_pos_c(c, 1);
    print_dlist_c(c);//[4][2]
    delete_data_c(c,4);
    print_dlist_c(c);
    empty_dlist_c(c);
    remove_dlist_c(c);
    c = NULL;
    return 0;
}
