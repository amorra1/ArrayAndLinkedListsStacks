#include <malloc.h>
#include "stack.h"

struct stack_node {
    // TODO (task 1): what fields do we need here?
    char val;
    struct stack_node *next;
};

struct stack {
    // Null if the stack is empty.
    struct stack_node *head;
};

stack_ptr stack_new() {
    stack_ptr s = malloc(sizeof(struct stack));
    s->head = NULL;
    return s;
}

void stack_free(stack_ptr s) {
    // TODO (task 1): how do we make sure the nodes don't leak memory?
    while (s->head != NULL) { //while the head does not point to NULL
        struct stack_node *temp = s->head; //creating a temp node
        s->head = s->head->next; //set the head to the next node
        free(temp); //free the temp memory
    }
    free(s); //free the stack
}

void stack_push(stack_ptr s, char c) {
        // TODO (task 1): how do we push an entry onto the stack?
        struct stack_node *new_node = malloc(sizeof(struct stack_node)); //create a new node
        new_node->val = c; //make the new nodes value the inputed value
        new_node->next = s->head; //set the new nodes pointer to the head
        s->head = new_node; // set the head to point to the new node
    }

    bool stack_pop(stack_ptr s, char *out) {
        // TODO (task 1): how do we pop an entry from the stack?
        if (s->head != NULL) { 
            *out = s->head->val; //retreive value
            struct stack_node *temp = s->head; //creates temp pointer to head of stack
            s->head = s->head->next; //move head to next node
            free(temp); //free the temp memory
            return true;
        }
        return false;
    }
