#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

//Définition de la structure Node
typedef struct Node{
    char caractere;
    int occurrence;
    struct Node* next_elem;//pointe sur l'élément suivant de la liste
    struct Node* left;//pointe sur le sous-arbre gauche
    struct Node* right;//pointe sur le sous-arbre droit
}Node;

/** APPENDIX FUNCTION **/

// CRREATION DE MAILLON DANS LE BUT DE CREER UNE LISTE
Node* create_elem(char caractere);
// AFFICHAGE DE LA LISTE
void print_list(Node * myList);
//void print_tree(Node2* tree);//A modifier
// COMPTE LE NOMBRE D'ELEMENT APPARTENANT A LA LISTE
int nb_element_list(Node* mylist);


/**********************************************************************************************************************/
// PART 1 : FROM LETTER TO BIT

/** FUNCTION A **/
//int presence_letter(Element** mylist,char Letter);
int ascii_to_binary(char car);
void translate_binary(char* file_in, char* file_out);

/** FUNCTION B **/
int nb_caractere(FILE* fichier);

// PART 2 : THE NAIVE VERSION OF HUFFMAN CODE

///     2.1 OCCURENCE      ///

/** FUNCTION C **/
//Element* Occurence();
//void add_new_el_end(Element** mylist, Element* new_element);
Node* increment_elem(Node* list_huffman,char caractere);
Node* create_list_huffman(char* file_in);

///     2.2 TREE     ///


/** FUNCTION D **/
Node* smaller_element(Node* mylist);
void delete_element( Element** mylist, Element* target);
//Node2* create_node(char caractere,int occurrence);//Plus nécessaire
//Node2* tree_huffman(Element* copied_list);//A modifier
///     2.3 DICTIONNARY    ///


/** FUNCTION E **/
void Storage_Dictionary(Node2* T_Huffman);//A modifier
int nb_element_tree_right(Node2* Tree);//A modifier


///     2.4 ENCODING     ///


/** FUNCTION F **/
void Encodage(FILE* fichier);

/** FUNCTION G **/




#endif // FONCTION_H_INCLUDED
