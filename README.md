# EDA-P8
/*Programador HERNANDEZ ROJAS MARA ALEXANDRA
 *EDA 1    Grupo 13    Practica 8 "Listas Ligadas"
 *Cuestionario
 */
 1: Operaciones que se pueden realizar en una lista doblemente ligada
 1 insertar al inicio, 2 insertar al final, 3 insertar en X posicion, 4 eliminar al inicio, 5 eliminar al final, 
 6 eliminar X posicion, 7 buscar nodo, 8 buscar dato, 9 buscar posicion, 10 eliminar X dato, 11 vaciar la lista.
 2: Diferencias entre lista ligada simple y lista doblemente ligada
 En una lista doblemente ligada cada nodo tiene dos punteros uno que apunta al próximo nodo y otro que apunta al 
 anterior mientras que una lista simple los nodos solo teinen un puntero que va al siguiente elemento.
 3:Diferencias entre LDL y LDL Circular
 El la lista doblemente ligada tanto el apuntador a previo del primer nodo como el puntero al siguiente del ultimo nodo apuntan a nulo.
 En la circular el previo al primero apunta al ultimo nodo y el siguiente del ultimo apunta al primer nodo.
 4:Escrba el tipo struct para el nodo
 typedef struct _dnode dnode;
 struct _dnode{
    DATA data;
    dnode *next;
    dnode *prev;
 }
5:Escriba rl tipo estruct para una LDL
struct _dlist{
    dnode *head;
    dnode *tail;
    int num;
 }
 6:Escriba rl tipo estruct para una LDL Circular
 struct _dlistc{
    dnode *head;
    dnode *tail;
    int num;
}
7: Escriba como recorrer una lista ligada sin usar tail
 Utilizamos el contador de nodos de la lista como referencia para saber en que posición nos encontramos ( i ) si tomamos en cuenta la posición 0 como la del primer nodo entonces la ultima posición será una unidad menor que el numero de nodos. Por ejemplo si la recorremos del inicio al final
dnode *t = l->head;
 for(int i =0; i < l->num; i++)
     t=t->next;
8: Escriba como recorrer una lista ligada CIRCULAR sin usar tail
Utilizamos el contador de nodos de la lista como referencia para saber en que posición nos encontramos ( i ) si tomamos en cuenta la posición 0 como la del primer nodo entonces la ultima posición será una unidad menor que el numero de nodos. Podemos hacer lo mismo porque no importa a donde apunte el siguiente de tail o el anterior a head el numero de nodos es una constante.  Por ejemplo si la recorremos del inicio al final
dnode *t = l->head;
 for(int i =0; i < l->num; i++)
     t=t->next;

//CONCLUSIONES
Considero que manejar una lista doblemente ligada es muy comoda de usar porque podemos recorrerr la lista del principio al final 
o del final al principio y reduce la cantidad de lineas en el codigo dentro de las funciones eliminar X posicion e insertar en X posicion
porque como cada nodo tiene la dirección del siguiente y del anterior no necesitamos las funciones auxiliares ultimo() penultimo() anterior()
que definimos para la lista ligada simple. Sin embargo este tipo de lista tiene que utilizar más memoria porque tiene el doble de apuntadores entre nodos.
En cuanto a la forma de recorrer ambas listas si lo hacemos por referencia con un apuntador temporal 't' sabremos  que hemos terminado de recorrerla cuando
t->next == NULL si vamos hacia adelante o t->prev == NULL si vamos hacia atras mientras que en la lista circular cambiamos esas condiciones por 
t->next == l->head y t->prev == l->tail respectivamente. Aunque tambien podemos hacerlo utilizando un contador 'i=0' e igualarlo al numero de nodos menos uno,
lo que nos puede llevar a utilizar la misma función para imprimir ambas listas.


