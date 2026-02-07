#ifndef APC_H
#define APC_H

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"
#define PURPLE  "\033[1;35m"   // Purple / Magenta
#define MAGENTA "\033[1;35m"   // Same as purple
#define PINK    "\033[38;5;213m" 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define SUCCESS		1
#define FAILURE		0

#define SAME		0
#define OPERAND1	1
#define OPERAND2	2

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}node;

void addition(node *tail1, node *tail2, node **headR, node **tailR);
void subtraction(node *tail1, node *tail2, node **headR, node **tailR);
void multiplication(node *tail1, node *tail2, node **headR, node **tailR);
void division(node *headL1, node *headOPR2,node *tailOPR2, node **headR, node **tailR);

int cla_validation(int argc, char *argv[]);
void create_list(char *opr, node **head, node **tail);

int insert_first(node **head, node **tail, int data);
int insert_last(node **head, node **tail, int data);
int delete_list(node **head, node **tail);
void print_list(node *head);

int compare_list(node *head1, node *head2);
int list_len(node *head);
void remove_pre_zeros(node **head);



#endif
