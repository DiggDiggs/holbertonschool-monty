#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: interger
 * @prev: pointer to the previous element of the stack (or queue)
 * @next: pointer to the next element of the stack (or queue)
 * 
 * 
 * description: doubly linked list node structure for stack and queue LIFO, FIFO
*/
typedef struct stack_s  
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode 
 * @f: function that handles the opcode
 * 
 * description: opcode and its function for stack and queue LIFO, FIFO
*/
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **struct, unsigned int line_number);
} instruction_t;

/**
 * struct global_v -struct to contain data 
 * @number: opcode's parameter 
 * @line_number: line number at current line 
 * @queue_ask: location in the queue
 * @stack: head of double linked list
 * @file: pointer to the file for stack, queues, LIFO, FIFO
*/
typedef struct global_v
{
    FILE *file;
    unsigned int line_number;
    char *number;
    int queue_ask;
    stack_t *stack;
} global_v;

extern global_var global_variable;

void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void free_list(stack_t *stack);
void exec0p(char (*array)[80]);

#endif 