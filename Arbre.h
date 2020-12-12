#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

#include "Liste.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//Définition de la structure Node
typedef struct Node{
    char caractere;
    int occurrence;
    int code[];
    struct Node* next_elem;//pointe sur l'élément suivant de la liste
    struct Node* left;//pointe sur le sous-arbre gauche
    struct Node* right;//pointe sur le sous-arbre droit
}Node;

void print_tree(Node* tree);
Node* smaller_element(Node* mylist);
Node* delete_smaller(Node* list, Node* smaller);;
Node* create_tree_huffman(Node* list_node);


#endif // FONCTION_H_INCLUDED
