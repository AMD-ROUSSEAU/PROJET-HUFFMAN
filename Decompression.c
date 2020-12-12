#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Decompression.h"

/**
 * \brief Function to find the caractere correspondind to a binary code
 * \param code_lettre a binary code and dico the dictionary.
 * \ return the caractere found in the dictionary corresponding to the binary code or -1 if the caractere is not found.
 */
int find_ascii(char* code_lettre, code_car* dico)
{
    while(dico!=NULL){
        if(strcmp(dico->code,code_lettre)==0)
        {
            return dico->caractere;
        }
        dico=dico->next;
    }
    return -1;
}

/**
 * \brief Function to decompress a text file
 * \param f_decomp the text file in which the decompressed code will be written, f_comp the text file containing the compressed code, dico the dictionary.
 * \ return nothing.
 */
void decompress_file(char *f_decomp,char* f_comp,code_car* dico)
{
    char car;
    int asci;
    char* code[100];

    FILE* file_decomp=fopen(f_decomp,"w");
    FILE* file_comp=fopen(f_comp,"r");
    memset(code,'\0',100);

    while((car=fgetc(file_comp)) != EOF){
        sprintf(code,"%s%c",code,car);
        asci=find_ascii(code,dico);
        if(asci>0)
        {
            fprintf(file_decomp,"%c",asci);
            memset(code,'\0',100);
        }
    }
    fclose(file_decomp);
    fclose(file_comp);
}
