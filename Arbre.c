#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Arbre.h"
#include "Liste.h"


/**
 * \brief Function to search for the smallest element in a Node* List
 * \ param mylist a node list containing each caractere and its occurrence.
 * \ return the address of the smallest element of mylist.
 */
Node* smaller_element(Node* mylist)
{
    Node* smaller = mylist;
    while (mylist->next_elem != NULL)
    {
        if (mylist->next_elem->occurrence <= smaller->occurrence)
        {
            smaller = mylist->next_elem;
            mylist = mylist->next_elem;
        }
        else
        {
            mylist = mylist->next_elem;
        }
    }

    return smaller;
}

/**
 * \brief Function to erase an element frome the list
 * \param mylist a node list containing each caractere and its occurrence and smaller the element that will be erased.
 * \ return mylist without smaller in it.
 */
//Fonction qui supprime l'élément smaller de la liste et qui retourne la nouvelle liste
Node* delete_smaller(Node* list, Node* smaller){
    Node* mylist=list;
    Node* first_elem=mylist;
    Node* previous = NULL; //Noeud precedent

    //printf("Entree dans delete_smaller\n");
    while(mylist != NULL){
        if (mylist==smaller){
            if(previous==NULL)//Cas où smaller est le premier element de la liste
            {
                return mylist->next_elem;
            }
            else // smaller n'est pas le premier element
            {
                if((mylist->next_elem)==NULL){//smaller est le dernier element de la liste
                    previous->next_elem = NULL;
                    return first_elem;
                }
                else //smaller n'est ni le premier ni le dernier element de la liste
                {
                    (previous->next_elem) = (smaller->next_elem);
                    return first_elem;
                }
            }
        }
        previous=mylist;
        mylist=mylist->next_elem;
    }
}

/**
 * \brief Function to create a Huffman tree from a node list
 * \param mylist mylist a node list containing each caractere and its occurrence.
 * \ return mylist with the new node created in it.
 */
Node* create_tree_huffman(Node* list_node){
    Node* mylist=list_node;
    Node* small_elem_1;
    Node* small_elem_2;
    Node* new_node;

    while(mylist->next_elem != NULL){
        small_elem_1 = smaller_element(mylist);//on trouve le premier plus petit element et on le stocke dans small_elem_1
        mylist=delete_smaller(mylist,small_elem_1);//on supprime le premier plus petit element de mylist
        small_elem_1->next_elem = NULL;//l'element n'est plus dans la liste

        small_elem_2 = smaller_element(mylist);//on trouve le deuxieme plus petit element et on le stocke dans small_elem_2
        mylist=delete_smaller(mylist,small_elem_2);//on supprime le deuxieme plus petit element de mylist
        small_elem_2->next_elem = NULL;//l'element n'est plus dans la liste

        new_node=create_elem(NULL,(small_elem_1->occurrence)+(small_elem_2->occurrence));
        new_node->left=small_elem_1;
        new_node->right=small_elem_2;

        new_node->next_elem = mylist;//on rajoute le nouveau noeud en debut de liste
        mylist = new_node;
    }
    return mylist;
}

/**
 * \brief Function to print a tree
 * \param mytree a Huffman tree containing each caractere and its occurrence.
 * \ return nothing.
 */

void print_tree(Node* tree){
    if(tree!=NULL){
        //printf("Entree dans print_tree\n");
        printf("[%c]|[%d] ->\n",tree->caractere,tree->occurrence);
        print_tree(tree->left);
        print_tree(tree->right);

    }
}


