#include <stdlib.h>

#include "Stack.h"

int g_nCurrent=0; /* Global int which works as an index of the current
                     element in the stack. Hence, it is not a real
                     stack pointer (SP) */

HANDLE createStack(int n) {
   return (HANDLE)malloc(n*sizeof(String));
}

void destroyStack(HANDLE h) {
   /* Fill in. destroyStack must free all allocated memory. */
    free(&h);
}

void Peek(HANDLE h,String s) {
   String *p;
   p=(String *)h; /* h is just a long, so we change it */
   /* Access to the Stack must work though the pointer p */
   /* Fill in! */
}

void Push(HANDLE h,String s) {
   /* Fill in! */
    // stack_node_t *new_pointer;
    
}

void Pop(HANDLE h,String s) {
   /* Fill in! */
}
