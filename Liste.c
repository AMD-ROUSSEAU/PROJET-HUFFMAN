#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int presence_letter(Element** mylist, char  Letter)
{
    Element* temp = (*mylist);

    while (temp != NULL)
    {
        if ((temp->caractere) == Letter)
        {
            (temp->repetition)++;
            return 1;
        }
        else
            temp = temp->next;
    }
    return 0;
}

//Source : CM Marshal
void add_new_el_end(Element** mylist, Element* new_element)
{
    Element* temp = (*mylist);
    if ((*mylist) == NULL)
    {
        (*mylist) = new_element;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_element;
    }
}

void print_list(Element* mylist)
{
    if (mylist == NULL)
    {
        return;
    }
    else
    {

        printf("[%c][%d] -> ", mylist->caractere, mylist->repetition);
        print_list(mylist->next);
    }
}

int nb_element_list(Element* mylist)
{
    if (mylist == NULL)
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
    Element* new_element = NULL;
    new_element = malloc(sizeof(Element));
    new_element->caractere = Letter;
    new_element->repetition = 1;
    new_element->next = NULL;
    return new_element;
}


Element* Occurence()
{

    Element* mylist = NULL;

    char Letter;
    FILE* file = fopen("Alice.txt", "r");

    Letter = fgetc(file);
    Element* new_element = create_element(Letter);
    add_new_el_end(&mylist, new_element);
    Letter = fgetc(file);
    while (Letter != EOF)
    {
        /** LA LETTRE EST PAS PRESENTE J'AJOUTE UN MAILLON POUR ELLE */
        if (presence_letter(&mylist, Letter) == 0)
        {
            new_element = create_element(Letter);
            add_new_el_end(&mylist->next, new_element);
            Letter = fgetc(file);
        }
        /** LA LETTRE EST PRESENTE JE PASSE AU SUIVANT**/
        else
        {
            Letter = fgetc(file);
        }
    }
    fclose(file);
    return mylist;
}
