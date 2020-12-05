#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

typedef struct Element
{
    char caractere;
    int repetition;
    struct Element* next;
}Element;

typedef struct Node
{
    Element* data;
    struct Node* left;
    struct Node* right;
}Node;

typedef struct Node2{

    char caractere;

    int occurrence;

    struct Node2* left;

    struct Node2* right;

}Node2;

typedef struct List_Node
{

}List_Node;
/** APPENDIX FUNCTION **/

// CRREATION DE MAILLON DANS LE BUT DE CREER UNE LISTE
Element* create_element(char Letter);
// AFFICHAGE DE LA LISTE
void print_list(Element * myList);
void print_tree(Node2* tree);
// COMPTE LE NOMBRE D'ELEMENT APPARTENANT A LA LISTE
int nb_element_list(Element* mylist);


/**********************************************************************************************************************/
// PART 1 : FROM LETTER TO BIT

/** FUNCTION A **/
int presence_letter(Element** mylist,char Letter);
int ascii_to_binary(char car);
void translate_binary();

/** FUNCTION B **/
int nb_caractere(FILE* fichier);

// PART 2 : THE NAIVE VERSION OF HUFFMAN CODE

///     2.1 OCCURENCE      ///

/** FUNCTION C **/
Element* Occurence();
void add_new_el_end(Element** mylist, Element* new_element);


///     2.2 TREE     ///


/** FUNCTION D **/
Element* smaller_element(Element* mylist);
void delete_element( Element** mylist, Element* target);
Node2* create_node(char caractere,int occurrence);
Node2* tree_huffman(Element* copied_list);
///     2.3 DICTIONNARY    ///


/** FUNCTION E **/
void Storage_Dictionary(Node2* T_Huffman);
int nb_element_tree_right(Node2* Tree);


///     2.4 ENCODING     ///


/** FUNCTION F **/
void Encodage(FILE* fichier);

/** FUNCTION G **/




#endif // FONCTION_H_INCLUDED
