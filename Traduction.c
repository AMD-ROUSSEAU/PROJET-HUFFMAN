#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Traduction.h"

int nb_caractere(FILE* fichier)
{
    int x = 0;
    int Lettre;
    if (fichier != NULL) // test opening file
    {
        Lettre = fgetc(fichier);//Reading first letter
        while (Lettre != EOF)
        {
            x++;// repetition counter
            Lettre = fgetc(fichier);//Letter next
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
    int c = car;
    if (c == 0)
        return 0;
    if (c == 1)
        return 1;
    return ((c % 2) + 10 * ascii_to_binary(c / 2));
}

void translate_binary()
{
    char c;
    FILE* Alice = fopen("Alice.txt", "r");
    FILE* Output = fopen("Output.txt", "w");
    if (Alice == NULL)
    {
        fprintf(stderr, "-------------------ERREUR D'OUVERTURE-------------------");
    }

    if (Output == NULL)
    {
        fprintf(stderr, "-------------------ERREUR D'OUVERTURE-------------------");
    }

    while ((c = fgetc(Alice)) != EOF)
    {
        fprintf(Output, "%08d", ascii_to_binary(c));
    }
    fclose(Alice);
    fclose(Output);
}

void Storage_Dictionary(Node2* T_Huffman, T_Huffman->code[], int x) // ajout d'un nouveau paramètre "code" dans la structure 
{
  printf(" DEBUT DICO  \n");
    /** OPENING DICO FILE **/
    FILE* Dico = NULL;
    Dico = fopen("Dico.txt","r+");
   
    /** TEST IF OPENING SUCCESSFUL **/
    if( Dico != NULL)
    {

        if ( T_Huffman->left == NULL && T_Huffman->right == NULL) // feuille trouvé 
        {   
            fprintf(Dico,"%c : ",T_Huffman->caractere ); // Ecriture de la lettre dans le fichier dico
            int i=0;
            for(i=1; i< 10; i++)
            {
                fprintf(Dico,"%d",T_Huffman->code[i]);// Ecriture du code binaire dans le fichier Dico
            }
            fputc("\n",Dico);
        }
        else if ( T_Huffman->left != NULL )
        {   
           T_Huffman->code[x] = 0;
           Storage_Dictionnary(T_Huffman->left, x++);// Si je vais a gauche le code prend un 0
        }
        else if( T_Huffman->right != NULL)
        {
            T_Huffman->code[x] = 1 ; 
            Storage_Dictionnary(T_Huffman->right,x++); // Si je vais a droite le code prend un 1
        }
    }
    else
    {
        /** OPENING FAILURE **/
        printf(" DICO FILE CANNOT BE OPENED ");
    }
    fclose(Dico);

}
