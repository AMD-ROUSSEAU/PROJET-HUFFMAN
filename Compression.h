#ifndef COMPRESSION_H_INCLUDED
#define COMPRESSION_H_INCLUDED
#include "Traduction.h"

#define length_code 100

 /**
  * \typedef struct code_car
  * \brief a Node is a tab containing a caractere and its compressed code.
  */
typedef struct code_car{
  char caractere;/**< the caractere contained in code_car*/
  char* code[length_code];/**< the code of the caractere contained in code_car*/
  struct code_car* next;/**< the reference to the next element of the tab*/
}code_car;

code_car* read_dico(char* dico);
code_car* create_elem_dic();
char* find_code(code_car* dico_list,char car);
void compression_file(char* file_text,char* compressed, code_car* memory_dico);

#endif // COMPRESSION_H_INCLUDED
