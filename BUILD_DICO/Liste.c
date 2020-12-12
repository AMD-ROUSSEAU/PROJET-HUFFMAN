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
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->caractere = car;
    new_node->occurrence = occ;
    new_node->next_elem = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
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
    while(list_huffman != NULL){
        if ((list_huffman->caractere)==caractere){
            list_huffman->occurrence++;
            return list_huffman;
        }
        list_huffman=list_huffman->next_elem;
    }
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
    Node* mylist = NULL;
    Node* temp = NULL;//liste temporaire
    int car;
    FILE* file = fopen(file_in,"r");

    if (file==NULL){ //probleme d'ouverture du fichier
        fprintf(stderr, "-------------------ERREUR D'OUVERTURE-------------------");
    }

    while((car=fgetc(file)) != EOF){//Tant que nous ne sommes pas arrives a la fin du fichier texte
        if (mylist==NULL){//Si la liste est vide
            mylist=create_elem(car,1);
            temp=mylist;
        }
        else{
            if (increment_elem(mylist,car) == NULL){
                temp->next_elem=create_elem(car,1);
                temp=temp->next_elem;
            }
        }
    }
    fclose(file);
    return mylist;
}

/**
 * \brief Function to print a list
 * \param mylist a list of nodes.
 * \ return nothing.
 */
void print_list(Node* mylist)
{
    if(mylist==NULL)
    {
        return;
    }
    else
    {
        while(mylist!=NULL){
            printf("[%d][%d] -> \n",mylist->caractere, mylist->occurrence);
            mylist = mylist->next_elem;
        }
    }
}

/**
 * \brief Function to count the number of elements in a list
 * \param mylist a list of nodes.
 * \ return the number of elements in the list.
 */
int nb_element_list(Node* mylist)
{
    if (mylist == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + nb_element_list(mylist->next_elem);
    }
}
