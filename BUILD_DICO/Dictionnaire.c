#include "Dictionnaire.h"

/**
 * \brief Function to write a caractere and its code in a text file
 * \param dico the text file in which we write, mytree a Huffman tree, path the code of the caractere.
 * \ return nothing.
 */
void storage_letter(FILE* dico,Node* mytree,char* path){
    char path_left[100];
    char path_right[100];
    char letter_code[100];

    strcpy(path_left,path);
    strcpy(path_right,path);

    if(mytree!=NULL){
        if(mytree->caractere==NULL){//Noeud intermediaire
            strcat(path_left,"0");
            storage_letter(dico,mytree->left,path_left);

            strcat(path_right,"1");
            storage_letter(dico,mytree->right,path_right);
        }
        else{//Noeud contenant une lettre
            if(path==NULL){//Il n'y a qu'un noeud dans l'arbre contenant une lettre donc un seul caractere dans le fichier texte,peu probable
                sprintf(letter_code, "%c:%s", mytree->caractere, "0");
                printf("Lettre code 1 = %s\n",letter_code);
                fprintf(dico,"%s\n",letter_code);
            }
            else{
                sprintf(letter_code, "%c:%s", mytree->caractere, path);
                printf("Lettre code 2 = %s\n",letter_code);
                fprintf(dico,"%s\n",letter_code);
            }
        }
    }
}

/**
 * \brief Function to call for function storage_letter
 * \param mytree a Huffman tree, Dico_name the text file in which we write.
 * \ return nothing.
 */
void Storage_Dictionary(Node* mytree,char* Dico_name){

    /** OPENING DICO FILE **/
    FILE* file_dico=fopen(Dico_name,"w");
    if (file_dico==NULL){ //probleme d'ouverture du fichier
        fprintf(stderr, "-------------------ERREUR D'OUVERTURE DE DICO.TXT-------------------");
    }

    storage_letter(file_dico,mytree,"");
    fclose(file_dico);
}
