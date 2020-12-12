#include <stdio.h>
#include <stdlib.h>
#include "Liste.h"
#include "Arbre.h"
#include "Traduction.h"
#include "Compression.h"

int main()
{
    int choice=0;
    int file=0;
    int nb_car;
    Node* mylist;
    Node* mytree;
    code_car* dictionary;

    FILE* fichier = fopen("Alice.txt", "r");
    FILE* fichier2 = fopen("Dico.txt", "w");
    FILE* fichier3 = fopen("Output2.txt", "w");



    printf("WELCOME TO THE HUFFMAN PROGRAM\n");
    printf("MENU: \n");

    printf("1 : Compression a file\n2: Number of character in a file\n3: Display new dictionary\n ");
    printf("\nPlease select a choice : ");
    scanf("%d",&choice);

    printf("\n*************************************\n");
    if( choice<=3 && choice >=1)
    {
        printf("Your choice was registered by the program\n\n");

        switch(choice)
        {
        case 1:
            printf(" LOOK TO SABRINA  \n");

            break;
        case 2:
            printf("Please select a file : \n1 : Alice\n2: Amandine\n3: Matusa\n4: Sabrina\n");
            printf(" Your choice : ");
            scanf("%d",&file);

            switch(file)
            {
            case 1:
                nb_car = nb_caractere(fichier);
                printf("\n\nLe fichier contient %d caracteres.\n", nb_car);
                printf("\n\n\nTHANKS TO USE HUFFMAN PROGRAMM !!!\n\n    SEE YOU LATER\n\n");
                break;
            default :
                printf("The choice entered is not offerd ... TRY AGAIN");
                break;
            }
            break;
        case 3:
            mylist = create_list_char("Alice.txt");
            /*Tree creation*/
            mytree = create_tree_huffman(mylist);
            printf("\n Your new dictionary is below : \n");
            Storage_Dictionary(mytree,"Dico.txt");
            break;
        default:
            printf("The choice entered is not offerd ... TRY AGAIN");
            break;

        }
    }
    return 0;
}

