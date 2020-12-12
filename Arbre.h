
#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

#include "Liste.h"

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

Node* smaller_element(Node* mylist);
Node* delete_smaller(Node* list, Node* smaller);
Node* create_tree_huffman(Node* list_node);
void print_tree(Node* tree);


#endif // ARBRE_H_INCLUDED
