#include <stdio.h>
#include <stdlib.h>
#include <math.h>


Node2* create_node(char caractere, int occurrence)
{

    Node2* new_node = (Node2*)malloc(sizeof(Node2));
    new_node->caractere = caractere;
    new_node->occurrence = occurrence;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Element* smaller_element(Element* mylist)
{
    Element* smaller = mylist;
    while (mylist->next != NULL)
    {
        if (mylist->next->repetition <= smaller->repetition)
        {
            smaller = mylist->next;
            mylist = mylist->next;
        }
        else
        {
            mylist = mylist->next;
        }
    }

    return smaller;
}

void delete_element(Element** malist, Element* x)
{
    Element* temp = NULL;
    Element* buffer = (*malist);
    if (malist == NULL)
    {
        return;
    }
    else
    {
        while (buffer->next != NULL)
        {
            if (buffer->next->caractere == x->caractere)
            {
                temp = buffer->next->next;
                free(buffer->next);
                buffer->next = temp;
            }
            else
            {
                buffer = buffer->next;
            }
        }
    }
    if ((*malist)->caractere == x->caractere)
    {
        buffer = *malist;
        *malist = (*malist)->next;
        free(buffer);
    }
}

Node2* tree_huffman(Element* copied_list)
{
    Node2* Tree = NULL;
    Node2* right_node;
    Node2* left_node;
    Node2* current_node;
    Element* small_element_left;
    Element* small_element_right;
    while (copied_list != NULL)
    {
        if (Tree == NULL)
        {
            small_element_right = smaller_element(copied_list);
            right_node = create_node(small_element_right->caractere, small_element_right->repetition);
            print_list(copied_list);
            delete_element(&copied_list, small_element_right);
            printf("\n");
            print_list(copied_list);
            printf("\n");
            small_element_left = smaller_element(copied_list);
            left_node = create_node(small_element_left->caractere, small_element_left->repetition);
            delete_element(&copied_list, small_element_right);

            Tree = create_node(0, small_element_right->repetition + small_element_left->repetition);

            Tree->left = left_node;
            Tree->right = right_node;
        }
        else
        {
            small_element_left = smaller_element(copied_list);
            left_node = create_node(small_element_left->caractere, small_element_left->repetition);
            current_node = create_node(0, Tree->occurrence + small_element_left->repetition);
            delete_element(&copied_list, small_element_left);

            current_node->left = left_node;
            current_node->right = Tree;
            Tree = current_node;
        }
    }
    print_list(copied_list);
    return Tree;

}

void print_tree(Node2* tree)
{
    if (tree != NULL)
    {
        printf("[ %c | %d ] ->", tree->caractere, tree->occurrence);
        print_tree(tree->left);
        print_tree(tree->right);
    }
}

int nb_element_tree_right(Node2* Tree)
{
    if (Tree == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + nb_element_tree_right(Tree->right);
    }
}
