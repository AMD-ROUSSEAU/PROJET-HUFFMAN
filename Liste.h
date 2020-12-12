#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED


//Définition de la structure Node
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * \typedef struct Node
 * \brief a Node is a node containing a caractere and its occurrence.
 */

typedef struct Node{
    int caractere;/**< the ascii code of the caractere contained in Node*/
    int occurrence;/**< the occurrence of the caractere*/
    struct Node* next_elem;/**< the reference to the next element of the list*/
    struct Node* left;/**< the reference to the left sub-tree of the tree*/
    struct Node* right;/**< the reference to the right sub-tree of the tree*/
}Node;

Node* create_elem(int car,int occ);
Node* increment_elem(Node* list_huffman,int caractere);
Node* create_list_char(char* file_in);
void print_list(Node* mylist);
int nb_element_list(Node* mylist);

#endif // LISTE_H_INCLUDED
