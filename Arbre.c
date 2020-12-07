#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//Fonction qui crée un noeud
Node* create_elem(char car,int occ)
{
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->caractere = (char)car;
    new_node->occurrence=occ;
    new_node->next_elem=NULL;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

Node* smaller_element(Node* mylist)
{
    Node* smaller = mylist;
    while (mylist->next != NULL)
    {
        if (mylist->next->repetition <= smaller->repetition)
        {
            smaller = mylist->next;
            mylist = mylist->next;
        }
        else
        {
            mylist = mylist->next;
        }
    }

    return smaller;
}

//Fonction qui supprime l'élément smaller de la liste et qui retourne la nouvelle liste
Node* delete_smaller(Node* list, Node* smaller){
    Node* mylist=list;
    Node* first_elem=mylist;
    Node* previous = NULL; //Noeud précédent

    //printf("Entree dans delete_smaller\n");
    while(mylist != NULL){
        if (mylist==smaller){
            if(previous==NULL)//Cas où smaller est le premier élément de la liste
            {
                return mylist->next_elem;
            }
            else // smaller n'est pas le premier élément
            {
                if((mylist->next_elem)==NULL){//smaller est le dernier élément de la liste
                    previous->next_elem = NULL;
                    return first_elem;
                }
                else //smaller n'est ni le premier ni le dernier élément de la liste
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

Node* create_tree_huffman(Node* list_node){
    Node* mylist=list_node;
    Node* small_elem_1;
    Node* small_elem_2;
    Node* new_node;

    while(mylist->next_elem != NULL){
        small_elem_1 = smaller_element(mylist);//on trouve le premier plus petit élément et on le stocke dans small_elem_1
        mylist=delete_smaller(mylist,small_elem_1);//on supprime le premier plus petit élément de mylist
        small_elem_1->next_elem = NULL;//l'élément n'est plus dans la liste

        small_elem_2 = smaller_element(mylist);//on trouve le deuxième plus petit élément et on le stocke dans small_elem_2
        mylist=delete_smaller(mylist,small_elem_2);//on supprime le deuxième plus petit élément de mylist
        small_elem_2->next_elem = NULL;//l'élément n'est plus dans la liste

        new_node=create_elem(NULL,(small_elem_1->occurrence)+(small_elem_2->occurrence));
        new_node->left=small_elem_1;
        new_node->right=small_elem_2;

        new_node->next_elem = mylist;//on rajoute le nouveau noeud en debut de liste
        mylist = new_node;
    }
    return mylist;
}

void print_tree(Node* tree)
{
    if (tree != NULL)
    {
        printf("[ %c | %d ] ->", tree->caractere, tree->occurrence);
        print_tree(tree->left);
        print_tree(tree->right);
    }
}

int nb_element_tree_right(Node* Tree)
{
    if (Tree == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + nb_element_tree_right(Tree->right);
    }
}
