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

void translate_binary ()
{
    char c;
    FILE* Alice=fopen("Alice.txt","r");
    FILE* Output=fopen("Output.txt", "w");
    if(Alice==NULL)
    {
        fprintf(stderr, "-------------------ERREUR D'OUVERTURE-------------------");
    }

    if(Output==NULL)
    {
        fprintf(stderr, "-------------------ERREUR D'OUVERTURE-------------------");
    }

    while((c=fgetc(Alice))!=EOF)
    {
        fprintf(Output, "%08d", ascii_to_binary(c));
    }
    fclose(Alice);
    fclose(Output);
}

int presence_letter(Element** mylist, char  Letter)
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

void print_list(Element* mylist)
{
    if(mylist==NULL)
    {
        return;
    }
    else
    {

        printf("[%c][%d] -> ",mylist->caractere, mylist->repetition);
        print_list(mylist->next);
    }
}

int nb_element_list(Element* mylist)
{
    if(mylist == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + nb_element_list(mylist->next);
    }
}

Element* create_element(char Letter)
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
        if(presence_letter(&mylist, Letter) == 0)
        {
            new_element = create_element(Letter);
            add_new_el_end(&mylist->next,new_element);
            Letter=fgetc(file);
        }
        /** LA LETTRE EST PRESENTE JE PASSE AU SUIVANT**/
        else
        {
            Letter=fgetc(file);
        }
    }
    fclose(file);
    return mylist;
}

Element* smaller_element(Element* mylist)
{
    Element* smaller = mylist;
    while(mylist->next != NULL)
    {
        if(mylist->next->repetition <= smaller->repetition)
        {
            smaller=mylist->next;
            mylist = mylist->next;
        }
        else
        {
            mylist = mylist->next;
        }
    }

    return smaller;
}

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

Node2* tree_huffman(Element* copied_list)
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

void Encodage(FILE* Alice)
{
    FILE* Output2 = fopen("Output2.txt","w"); // Opening of the file Output 
    FILE* Dico = fopen("Dico.txt", "r"); // Opening of the file Dico which is the dictionnary containing all the binary numbers correspondind to the caracters

    caracter = fgetc(Alice);
    caracterD = fgetc(Dico);

    // Until that the the caracter is not at the end of the file do these
    while( caracter != EOF)
    {
        while (caracterD != EOF) 
        {
            if(caracter == caracter D) // if the caracter in the file Alice corresponds to the caracter present in the dictionnary
            {
                while (caracterD != '\n') // until we go to the next line to see the next caracter
                {
                    fgetc(Dico); 
                    fgetc(Dico);
                    fgetc(Dico);
                    fgetc(Dico);
                    printf("%d",caracterD);
                    
                }
            }
                
            else
            {
                fgetc([\n],Dico);
            }
 
       }
   
    }
}

void compression_file(FILE* file)
{
    FILE* file_compressed = NULL;
    file_compressed = fopen("Compresse.txt", "w");




}

