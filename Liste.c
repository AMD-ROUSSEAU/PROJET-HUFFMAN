#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Liste.h"

/**
 * \brief Function to create a node
 * \param the ascii code of a caractere car and its occurrence occ.
 * \ return new_node the address of the new node created.
 */
//Fonction qui cree un noeud
Node* create_elem(int car,int occ)
{
    return new_node;
}


/**
 * \brief Function to increment the occurrence of a node if it is present in the tree
 * \param list_huffman a list of nodes and caractere the ascii code of a caractere.
 * \ return the address of the node if it is present or NULL if it is not present.
 */

//Fonction qui permet d'incrementer l'occurrence d'un noeud existant dans la liste
//Retourne l'addresse du noeud s'il est present
//Retourne NULL si le noeud n'est pas present
Node* increment_elem(Node* list_huffman,int caractere){
   
    return NULL;
}

/**
 * \brief Function to create a list from a text file
 * \param file_in the text file from which tree is created.
 * \ return the address of the created list.
 */
//Fonction qui cree une liste contenant les caracteres presents dans un fichier texte et leurs occurrences
//Si le caractere courant n'est pas dans la liste : creation d'un noeud contenant le caractere et ajout de ce noeud dans la liste
//Si le caractere courant est dans la liste : incrementation de son occurrence
Node* create_list_char(char* file_in){
    
    return mylist;
}

/**
 * \brief Function to print a list
 * \param mylist a list of nodes.
 * \ return nothing.
 */
void print_list(Node* mylist)
{
    return;
}

/**
 * \brief Function to count the number of elements in a list
 * \param mylist a list of nodes.
 * \ return the number of elements in the list.
 */
int nb_element_list(Node* mylist)
{
        return 1 + nb_element_list(mylist->next_elem);
    
}
