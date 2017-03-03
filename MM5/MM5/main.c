#include <stdio.h>

#include "Stack.h"

int main() {
   HANDLE h;
   String s;
   h=createStack(10); /* Room for 10 URLs on the stack */

   Peek(h,s); /* Take a peek at top of stack */
   printf("0: %s\n",s);   

   Push(h,"tv2.dk"); /* Add URL to the stack (like a browser cache) */
   Peek(h,s); /* Take a peek at top of stack */
   printf("1: %s\n",s);   

   Push(h,"dr.dk"); /* Add one more URL */
   Push(h,"youtube.com"); /* Add one more URL */   
   Peek(h,s); /* Take a peek at the last pushed URL */
   printf("2: %s\n",s);   
   
   Pop(h,s); /* Remove latest URL */
   printf("3: %s\n",s);      
   
   Peek(h,s); /* Take a peek at the top of the stack */
   printf("4: %s\n",s);      
   
   destroyStack(h);
   return 0;
}
