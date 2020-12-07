#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

//Définition de la structure Node
typedef struct Node{
    char caractere;
    int occurrence;
    int code[];/*++++++++MODIF++++++++++*/
    struct Node* next_elem;//pointe sur l'élément suivant de la liste
    struct Node* left;//pointe sur le sous-arbre gauche
    struct Node* right;//pointe sur le sous-arbre droit
}Node;

Node* create_elem(char car,int occ);
int nb_element_list(Node* mylist);
Node* increment_elem(Node* list_huffman,char caractere);
Node* create_list_char(char* file_in);
void print_list(Node* myList);

#endif // FONCTION_H_INCLUDED
