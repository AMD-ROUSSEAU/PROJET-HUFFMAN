#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

typedef struct Element
{
    char caractere;
    int repetition;
    struct Element* next;
}Element;

int nb_element_list(Element* mylist);
int presence_letter(Element** mylist, char Letter);
Element* create_element(char Letter);
void print_list(Element* myList);
Element* Occurence();
void add_new_el_end(Element** mylist, Element* new_element);

#endif // FONCTION_H_INCLUDED