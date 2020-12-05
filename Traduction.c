#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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