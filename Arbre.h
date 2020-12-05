#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

typedef struct Node
{
    Element* data;
    struct Node* left;
    struct Node* right;
}Node; 

typedef struct Node2 {

    char caractere;

    int occurrence;

    struct Node2* left;

    struct Node2* right;

}Node2;

void print_tree(Node2* tree);
Element* smaller_element(Element* mylist);
void delete_element(Element** mylist, Element* target);
Node2* create_node(char caractere, int occurrence);
Node2* tree_huffman(Element* copied_list);
int nb_element_tree_right(Node2* Tree);

#endif // FONCTION_H_INCLUDED