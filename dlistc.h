#ifndef DLISTC_H
#define DLISTC_H

#include "dnode.h"

typedef struct _dlistc dlistc;

struct _dlistc{
    dnode *head;
    dnode *tail;
    int num;
};

dlistc *create_dlist_c();
bool remove_dlist_c(dlistc *l);

bool insert_init_c(dlistc *l, DATA data);
bool insert_end_c(dlistc *l, DATA data);
bool insert_dlist_c(dlistc *l, DATA data, int pos);

bool remove_init_c(dlistc *l);
bool remove_end_c(dlistc *l);
bool remove_pos_c(dlistc *l ,int pos);

DATA search_dlist_c(dlistc *l, int pos);
int locate_dlist_c(dlistc *l, DATA data);
dnode *search_dnode_dlist_c(dlistc *l, int pos);

void print_dlist_c(dlistc *l);

bool is_empty_dlist_c(dlistc *l);
void empty_dlist_c(dlistc *l);

bool delete_data_c(dlistc *l, DATA data);
#endif
