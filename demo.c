#include "demo.h"
#include "stack.h"


//matching pair function as taught in class
bool is_matching_pair(char character1, char character2) {
    if (character1 == '(' && character2 == ')') //checks for regular brackets
        return true;
    else if (character1 == '{' && character2 == '}') //checks for curly brackets
        return true;
    else if (character1 == '[' && character2 == ']') //checks for square brackets
        return true;
    else
        return false;
}


bool check_brackets(const char *str) {
    stack_ptr s = stack_new();

    // TODO (task 3): using the stack 's', check the brackets in the strings.
    char temp; //create a temp variable
    while(*str){ //while loop to loop through entire string of brackets
        if(*str == '(' || *str == '{' || *str == '['){ //if an opening bracket, push onto the stack
            stack_push(s,*str);
        }
        if(*str == ')' || *str == '}' || *str == ']'){ //if a closing bracket, pop off the stack
            if(!stack_pop(s,&temp)){ //checking if that stack is empty 
                return false;
            }else if (!is_matching_pair(temp,*str)){ //running the match pair function
                return false; //if it doesnt work return false
            }
        }
    str++; //increment the string before end of loop
    }
    if(stack_pop(s,&temp)){ //use pop function to tell if stack is empty and the free the stack memory
        stack_free(s);
        return false;
    }else{
        stack_free(s); //otherwise free the memory
        return true;
    }
}
