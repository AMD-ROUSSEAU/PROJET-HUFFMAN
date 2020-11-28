#include <stdio.h>
#include <stdlib.h>
#include "FONCTION.h"

int main()
{

   translate_binary();

    FILE* fichier = fopen("Alice.txt","r");
    FILE* fichier2 = fopen("Output.txt","r");

    int x = nb_caractere(fichier);
    int y = nb_caractere(fichier2);

    printf("Le nombre de caractère dans Alice.txt est %d\n",x);
    printf("Le nombre de caractère dans Output.txt est %d\n",y);
fclose(fichier);
fclose(fichier2);

    Element* mylist=NULL;

    mylist = Occurence();

     print_list(mylist);
    printf("\n\nIl y a %d lettres differentes \n",nb_element_list(mylist));

Node2* HUFFMAN= NULL;
HUFFMAN = tree_huffman(mylist);
print_tree(HUFFMAN);

Storage_Dictionary(HUFFMAN);
    return 0;
}
