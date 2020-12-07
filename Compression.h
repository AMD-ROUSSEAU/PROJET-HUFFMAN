#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

typedef struct Element
{
    char caractere;
    int repetition;
    struct Element* next;
}Element;

typedef struct Node
{
    Element* data;
    struct Node* left;
    struct Node* right;
}Node;

typedef struct Node2{

    char caractere;

    int occurrence;

    struct Node2* left;

    struct Node2* right;

}Node2;

typedef struct List_Node
{

}List_Node;




#endif // FONCTION_H_INCLUDED
