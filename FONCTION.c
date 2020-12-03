#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FONCTION.h"

//hello

int nb_caractere(FILE* fichier)
{
    int x=0;
    int Lettre;
    if (fichier != NULL) // test opening file
    {
        Lettre =fgetc(fichier);//Reading first letter
        while( Lettre != EOF)
        {
            x++;// repetition counter
            Lettre =fgetc(fichier);//Letter next
        }
        fclose(fichier);//closing file
        return x; // return number of repetition

    }
    else
    {
        // display error message
        printf("Impossible d'ouvrir le fichier test.txt");
        return 0;
    }
}

int ascii_to_binary(char car)
{
    int c=car;
    if (c == 0)
        return 0;
    if (c == 1)
        return 1;
    return ((c % 2) + 10 * ascii_to_binary(c / 2));
}

//Fonction permettant de traduire un fichier texte en code binaire (8 bits par caractere)
/*Parametres : un fichier input.txt contenant le texte à traduire et un fichier output.txt
 dans lequel la traduction de input.txt en code binaire sera écrit*/
void translate_binary (char* file_in, char* file_out)
{
    char car;
    FILE* input=fopen(file_in,"r");//on ouvre input.txt en mode lecture
    FILE* output=fopen(file_out,"w");//on ouvre input.txt en mode écriture
    if(input==NULL)//problème d'ouverture du fichier
    {
        fprintf(stderr, "-------------------ERREUR D'OUVERTURE-------------------");
    }

    if(output==NULL)//problème d'ouverture du fichier
    {
        fprintf(stderr, "-------------------ERREUR D'OUVERTURE-------------------");
    }

    while((car=fgetc(input)) != EOF){//Tant que nous ne sommes pas arrivés à la fin du fichier texte
    {
        fprintf(output, "%08d", ascii_to_binary(car));
    }
    fclose(input);//on ferme le fichier input.txt
    fclose(output);//on ferme le fichier output.txt
}
    
//Fonction qui crée un noeud
Node* create_elem(char caractere)
{
    printf("Entrée dans create_elem\n");
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->caractere = caractere;
    new_node->occurrence=1;
    new_node->next_elem=NULL;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
    
//Fonction qui permet d'incrémenter l'occurrence d'un noeud existant dans la liste
//Retourne l'addresse du noeud s'il est present
//Retourne NULL si le noeud n'est pas present
Node* increment_elem(Node* list_huffman,char caractere){
    printf("Entrée dans increment_elem\n");
    while(list_huffman != NULL){
        if ((list_huffman->caractere)==caractere){
            list_huffman->occurrence++;
            return list_huffman;
        }
        list_huffman=list_huffman->next_elem;
    }
    return NULL;
}

//Fonction qui crée une liste contenant les caracteres presents dans un fichier texte et leurs occurrences
//Si le caractere courant n'est pas dans la liste : creation d'un noeud contenant le caractere et ajout de ce noeud dans la liste
//Si le caractere courant est dans la liste : incrementation de son occurrence
Node* create_list_huffman(char* file_in){
    Node* mylist=NULL;
    Node* temp=NULL;//liste temporaire
    char car;
    FILE* file=fopen(file_in,"r");

    printf("Entrée dans create_list_huffman\n");
    if (file==NULL){ //problème d'ouverture du fichier
        fprintf(stderr, "-------------------ERREUR D'OUVERTURE-------------------");
    }

    while((car=fgetc(file)) != EOF){//Tant que nous ne sommes pas arrivés à la fin du fichier texte
        if (mylist==NULL){//Si la liste est vide
            mylist=create_elem(fgetc(file));
            temp=mylist;
        }
        else{
            if (increment_elem(mylist,car) == NULL){
                temp->next_elem=create_elem(car);
                temp=temp->next_elem;
            }
        }
    }
    fclose(file);
    return mylist;
}
    

/*int presence_letter(Element** mylist, char  Letter)
{
    Element* temp = (*mylist);

    while(temp!=NULL)
    {
        if((temp->caractere)==Letter)
        {
            (temp->repetition)++;
            return 1;
        }
        else
            temp=temp->next;
    }
    return 0;
}

//Source : CM Marshal
void add_new_el_end(Element** mylist, Element* new_element)
{
    Element* temp = (*mylist);
    if((*mylist)== NULL)
    {
        (*mylist) = new_element;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_element;
    }
}
*/
void print_list(Node* mylist)
{
    if(mylist==NULL)
    {
        return;
    }
    else
    {

        printf("[%c][%d] -> \n",mylist->caractere, mylist->occurrence);
        print_list(mylist->next_elem);
    }
}

int nb_element_list(Node* mylist)
{
    if(mylist == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + nb_element_list(mylist->next_elem);
    }
}

/*Element* create_element(char Letter)
{
    Element* new_element=NULL;
    new_element = malloc(sizeof(Element));
    new_element->caractere = Letter;
    new_element->repetition = 1;
    new_element->next = NULL;
    return new_element;
}

Node2* create_node(char caractere,int occurrence)
{

    Node2* new_node=(Node2*)malloc(sizeof(Node2));
    new_node->caractere = caractere;
    new_node->occurrence=occurrence;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

Element* Occurence()
{

    Element* mylist= NULL;

    char Letter;
    FILE* file= fopen("Alice.txt","r");

    Letter = fgetc(file);
    Element* new_element = create_element(Letter);
    add_new_el_end(&mylist,new_element);
    Letter = fgetc(file);
    while (Letter != EOF)
    {
        /** LA LETTRE EST PAS PRESENTE J'AJOUTE UN MAILLON POUR ELLE */
        /*if(presence_letter(&mylist, Letter) == 0)
        {
            new_element = create_element(Letter);
            add_new_el_end(&mylist->next,new_element);
            Letter=fgetc(file);
        }
        /** LA LETTRE EST PRESENTE JE PASSE AU SUIVANT**/
       /* else
        {
            Letter=fgetc(file);
        }
    }
    fclose(file);
    return mylist;
}*/

Node* smaller_element(Node* mylist)
{
    Node* smaller = mylist;
    while(mylist->next_elem != NULL)
    {
        if(mylist->next_elem->occurrence <= smaller->occurrence)
        {
            smaller=mylist->next_elem;
            mylist = mylist->next_elem;
        }
        else
        {
            mylist = mylist->next_elem;
        }
    }

    return smaller;
}

//A modifier avec la nouvelle structure Node*
void delete_element( Element** malist, Element* x)
{
   Element* temp=NULL;
    Element* buffer= (*malist);
    if(malist==NULL)
    {
        return;
    }
    else
    {
        while( buffer->next != NULL)
        {
            if(buffer->next->caractere == x->caractere)
            {
                temp= buffer->next->next;
                free(buffer->next);
                buffer->next = temp;
            }
            else
            {
                buffer = buffer->next;
            }
        }
}
    if ((*malist)->caractere == x->caractere)
    {
        buffer = *malist;
        *malist = (*malist)->next;
        free(buffer);
    }
}

//Fonction a modifier
/*Node2* tree_huffman(Element* copied_list)
{
    Node2* Tree=NULL;
    Node2* right_node;
    Node2* left_node;
    Node2* current_node;
    Element* small_element_left;
    Element* small_element_right;
    while (copied_list != NULL)
    {
        if (Tree==NULL)
        {
            small_element_right = smaller_element(copied_list);
            right_node=create_node(small_element_right->caractere,small_element_right->repetition);
print_list(copied_list);
            delete_element(&copied_list,small_element_right);
printf("\n");
print_list(copied_list);
printf("\n");
            small_element_left=smaller_element(copied_list);
            left_node=create_node(small_element_left->caractere,small_element_left->repetition);
            delete_element(&copied_list,small_element_right);

            Tree = create_node(0,small_element_right->repetition+small_element_left->repetition);

            Tree->left=left_node;
            Tree->right=right_node;
        }
        else
        {
            small_element_left=smaller_element(copied_list);
            left_node=create_node(small_element_left->caractere,small_element_left->repetition);
            current_node=create_node(0,Tree->occurrence+small_element_left->repetition);
            delete_element(&copied_list,small_element_left);

            current_node->left=left_node;
            current_node->right=Tree;
            Tree=current_node;
        }
    }
    print_list(copied_list);
    return Tree;

}

void print_tree(Node2* tree)
{
    if(tree != NULL)
    {
        printf("[ %c | %d ] ->",tree->caractere, tree->occurrence);
        print_tree(tree->left);
        print_tree(tree->right);
    }
}

int nb_element_tree_right(Node2* Tree)
{
    if(Tree == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + nb_element_tree_right(Tree->right);
    }
}
*/
    
//A modifier avec la nouvelle structure et le nouvel arbre de Huffman
void Storage_Dictionary(Node2* T_Huffman)
{
  printf(" DEBUT DICO  \n");
    /** OPENING DICO FILE **/
    FILE* Dico = NULL;
    Dico = fopen("Dico.txt","r+");
    fputc('A',Dico);
    /** TEST IF OPENING SUCCESSFUL **/
    printf(" OUVERTURE DICO \n");
    if( Dico != NULL)
    {
        /** -1 BECAUSE THE TABLE START TO 0 **/
        int chemin[nb_element_tree_right(T_Huffman)-1];
        int emplacement=0;
        int i;

        /** FIRTS CASE **/
        //printf("\n REGARD ICI : %c \n", T_Huffman->left->caractere);
        printf(" LETTRE : %c : 0 ",T_Huffman->right->left->caractere);
        fprintf(Dico,"%c : 0",T_Huffman->right->left->caractere);
        fputs("\n", Dico);
        //printf("DANS SI PREMIER CASE \n");
        /** TREE PATH **/
        while(T_Huffman->right != NULL)
        {
            /** RIGHT PATH TAKEN THEN +1 CASE OF VALUE 1 **/
            //printf("DANS BOUCLE WHILE \n");
            printf("\n");
            chemin[emplacement]= 1;
            emplacement++;
            T_Huffman = T_Huffman->right;
            /** PRESENCE OF A LETTER **/
            printf("\nLETTRE: %c : ",T_Huffman->right->left->caractere);
                fprintf(Dico,"%c : ",T_Huffman->right->left->caractere);
                //printf("DANS BOUCLE WHILE  DANS IF\n");

            /** BROWSE THE TABLE TO DISPLAY PATH **/

            for(i = 0; i< emplacement; i++)
            {
                printf("%d",chemin[i]);
                fprintf(Dico,"%d",chemin[i]);
                //printf("DANS BOUCLE WHILE  DANS FOR\n");
            }
            /** 0 : LEFT PATH TO ACCESS THE LETTER **/
           fputc('0', Dico);
           printf("0");
           fputc('A',Dico);
           fputs("\n", Dico);
           printf("\n");
        }
    }
    else
    {
        /** OPENING FAILURE **/
        printf(" DICO FILE CANNOT BE OPENED ");
    }
    fclose(Dico);

}

/*void Encodage(FILE* fichier)
{
    FILE* sortie = fopen("Sortie.txt","w");

    caractere = fgetc(fichier);
    caractere2 = fgetc(sortie);

    // The letter is not at the end
    while( caractere != EOF)
    {

        while( caracter2 != EOF)
        {
            //The letter is a letter presents in dico.txt
            if( caractere == caractere2)
            {
                // The binary code is just on one line
                while(// tant qu'on est pas arrivé au bout de la ligne ")
                {
                    // writing binary code in sortie.txt
                    fputs(fputc(dico),sortie);
                }
            }
            else
            {
                fputs(".",sortie);
            }
            // -> sauter une ligne pour lire caractere en dessous
            caractere2 = fgetc(dico);
        }
        // -> se replacer au debut

        // Next letter of Alice.txt
        caractere = fgetc(fichier);
    }
}
*/

void compression_file(FILE* file)
{
    FILE* file_compressed = NULL;
    file_compressed = fopen("Compresse.txt", "w");




}

