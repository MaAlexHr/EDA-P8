#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dlistc.h"

dlistc *create_dlist_c(){
    dlistc *l = (dlistc*)malloc(sizeof(dlistc));
    l->head = NULL;
    l->tail = NULL;
    l->num = 0;
    return l;
}

bool remove_dlist_c(dlistc *l){
    if(!is_empty_dlist_c(l))
        empty_dlist_c(l);
    free(l);
    return true;
}
/*
 *Estas funciones no modifican la lista
 */
DATA search_dlist_c(dlistc *l, int pos){
    if(pos == 0) return l->head->data;
    else if(pos == l->num-1) return l->tail->data;
    else if(pos >0 && pos < l->num-1){//antes l->num-2
        dnode *t = l->head->next;
        for(int i=1; i< l->num-1; i++){
            if(i==pos) return t->data;
            t = t->next;
        }
    }
    return -1;
}

dnode* search_dnode_dlist_c(dlistc *l, int pos){
    if(pos == 0) return l->head;
    else if(pos == l->num-1) return l->tail;
    else if(pos >0 && pos < l->num-2){
        dnode *t = l->head->next;
        for(int i=1; i<l->num-2; i++){
            if(i==pos) return t;
            t = t->next;
        }
    }
    return NULL;
}

int locate_dlist_c(dlistc *l, DATA data){
    dnode *t = l->head;
    for(int i= 0; i <l->num; i++){
        if(t->data==data) return i;
        t = t->next;
    }
    return -1;
}

void print_dlist_c(dlistc *l){
    dnode *t = l->head;
    printf("[ ");
    for(int i=0; i < l->num-1; i++){
        printf("%d, ", t->data);
        t = t->next;
    }
    printf("%d ", t->data);
    printf("]\n");
}

bool is_empty_dlist_c(dlistc *l){
    if(l->head == NULL && l->tail == NULL) return true;
    return false;
}
/*
 *Estas fnciones si modifican la lista
 */
void empty_dlist_c(dlistc *l){
    if(is_empty_dlist_c(l)) return;
    dnode *t = l->head;
    while(remove_init_c(l));
}

bool delete_data_c(dlistc *l, DATA data){
    dnode *t = l->head;
    for(int i = 0; i < l->num; i++){
        if(t->data == data){
            if(i == 0) return remove_init_c(l);
            return remove_pos_c(l,i);//yo
        }
    }
    return false;//yo
}

bool insert_init_c(dlistc* l, DATA data){
    if(l == NULL) return false;
    dnode *nuevo = create_dnode(data);
    if(is_empty_dlist_c(l)){        
        l->head = nuevo;
        l->tail = nuevo;
        l->tail->next = l->head;
    	l->head->prev = l->tail;
        l->num =1;
        return true;
    }
    nuevo->next = l->head;
    l->head->prev = nuevo;
    l->head = nuevo;
    l->tail->next = l->head;
    l->head->prev = l->tail;
    l->num++;
    return true;
}

bool insert_end_c(dlistc* l, DATA data){
    if(l == NULL) return false;
    dnode *nuevo = create_dnode(data);
    if(is_empty_dlist_c(l)){        
        l->head = nuevo;
        l->tail = nuevo;
        l->tail->next = l->head;
    	l->head->prev = l->tail;
        l->num =1;
        return true;
    }
    l->tail->next = nuevo;
    nuevo->prev = l->tail;
    l->tail = nuevo;
    l->tail->next = l->head;
    l->head->prev = l->tail;
    l->num++;
    return true;
}

bool insert_dlist_c(dlistc* l, DATA data,  int pos){
    if(l == NULL) return false;
    dnode *nuevo = create_dnode(data);
    if(pos ==0) return insert_init_c(l, data);
    else if(pos == l->num)
        return insert_end_c(l,data);
    else if(pos >0 && pos< l->num-1){
        dnode *t = l->head->next;
        for(int i =1; i < pos; i++){
            t= t->next;
        }
        dnode *prev = t->prev;    
        prev->next = nuevo;
        nuevo->next = t;
        nuevo->prev = prev;        
        t->prev = nuevo;
        l->num++;
        return true;
    }
    return false;
}

bool remove_end_c(dlistc *l){
    if(l == NULL || is_empty_dlist_c(l)) return false;
    if(l->head == l->tail){
    	l->tail->next = NULL;
    	l->head->prev = NULL;
        remove_dnode(l->head);
        l->head = l->tail = NULL;
        l->num = 0;
        return true;
    }
    dnode *t = l->tail->prev;
    t->next= NULL;
    l->tail->prev = NULL;
    remove_dnode(l->tail);
    l->tail = t;
    l->tail->next = l->head;
    l->head->prev = l->tail;
    l->num--;
    return true;
}

bool remove_init_c(dlistc *l){
    if(l == NULL || is_empty_dlist_c(l)) return false;
    if(l->head == l->tail){
    	l->tail->next = NULL;
    	l->head->prev = NULL;
        remove_dnode(l->head);
        l->head = l->tail = NULL;
        l->num = 0;
        return true;
    }
    dnode *t = l->head->next;
    l->head->next= NULL;
    t->prev = NULL;
    remove_dnode(l->head);
    l->head = t;
    l->tail->next = l->head;
    l->head->prev = l->tail;
    l->num--;
    return true;
}

bool remove_pos_c(dlistc *l ,int pos){
    if(pos == 0){
        return remove_init_c(l);
    }else if(pos == l->num-1){
        return remove_end_c(l);
    }else if(pos>0 && pos < l->num-1){
        dnode *t = l->head->next;
        for(int i =1; i < pos; i++){
            t= t->next;
        }
        dnode *prev = t->prev;    
        dnode *next = t->next;        
        prev->next = next;        
        next->prev = prev;
        t->next = NULL;
        t->prev = NULL;
        remove_dnode(t);
        l->num--;
        return true;
    }
    return false;
}


