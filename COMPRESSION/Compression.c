#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Compression.h"

/*Chargement du dictionnaire en memoire*/


code_car* create_elem_dic(){
    code_car* new_elem=(code_car*)malloc(sizeof(code_car));
    new_elem->caractere=(char)NULL;
    sprintf(new_elem->code,"%s","");
    new_elem->next=NULL;
    return new_elem;
}

/**
 * \brief Function to load a dictionary in memory (in a tab)
 * \param dico the text file containing the dictionary.
 * \ return the address of the tab containing the dictionary.
 */
code_car* read_dico(char* dico){
    char* read;
    int i,length_line;
    code_car* first_code=NULL;
    code_car* current_code=NULL;
    code_car* previous_code=NULL;
    char line[length_code];

    FILE* file_dico=fopen(dico,"r");

    read=fgets(line,length_code,file_dico);//length_code : taille max de la ligne qu'on veut lire (car comme on a defini une taille pour line, cela evite un depassement), dico : fichier qu'on veut lire, line : variable temporaire de stockaged'une ligne du fichier dico)
    while(read!=0){
        length_line=strlen(line);
        if(length_line>0)
        {
            length_line=length_line-1;

            current_code = create_elem_dic();
            current_code->caractere=line[0];
            for (i=2;i<length_line;i++){ //on copie le code dans current_code
                sprintf(current_code->code,"%s%c",current_code->code,line[i]);
            }

            if(previous_code==NULL){//on est sur le premier caractere
                first_code=current_code;
                previous_code=current_code;
            }
            else{
                previous_code->next=current_code;
                previous_code=current_code;
            }
            read=fgets(line,length_code,file_dico);
        }
    }
    fclose(file_dico);
    return first_code;
}

/*=====================================================================================================*/

/*Encodage*/

/**
 * \brief Function to find the code of a caractere in the dictionary
 * \param dico_list the dictionary, car a caractere.
 * \ return the code of the caractere if the caractere is found in the dictionary or NULL if it is not found.
 */
char* find_code(code_car* dico_list,char car){
    code_car* current_dico_list=dico_list;
    if(current_dico_list!=NULL){
        while(current_dico_list->next!=NULL){
            if(current_dico_list->caractere==car){
                return current_dico_list->code;
            }
            else current_dico_list=current_dico_list->next;
        }
    }
    return NULL;
}

/**
 * \brief Function to compress a text file in another text file
 * \param file_text the text file that needs to be compressed, compressed the text file in which the compressed code will be written and memory_dico the dictionary.
 * \ return nothing.
 */
void compression_file(char* file_text,char* compressed, code_car* memory_dico){
    printf("Entree dans compression_file");
    code_car* dictionary=memory_dico;
    code_car* dictionary_temp=memory_dico;
    char car;
    char* code[100];
    code_car* car_code;

    FILE* text_read=fopen(file_text,"r");
    FILE* comp_file=fopen(compressed,"w");

    while((car=fgetc(text_read)) != EOF){
         while(dictionary_temp!=NULL){
            if(dictionary_temp->caractere==car){
                fprintf(comp_file,"%s",dictionary_temp->code);
            }
            dictionary_temp=dictionary_temp->next;
         }
         dictionary_temp = dictionary;
    }
    fclose(text_read);
    fclose(comp_file);
}
