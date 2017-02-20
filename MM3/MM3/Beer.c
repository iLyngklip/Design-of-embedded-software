#include <stdio.h>
#include <stdlib.h>

#include "Beer.h"

static int g_nNumberOfBeers=0; /* Made static so it only can be accessed here */
                               /* g_ is for "global" */

struct Beer *addBeer(struct Beer *beer) {
   struct Beer *new_beer;
   /* Allocate space for new element/node: */
   new_beer=(struct Beer *)malloc(sizeof(struct Beer));
   /* Insert new element/beer before any other element: */
   new_beer->next=beer;

   printf("Type: ");
   scanf("%s",new_beer->type);
   printf("Price: ");
   scanf("%f",&new_beer->price);
   printf("Percentage: ");
   scanf("%f",&new_beer->alc);
   printf("Amount [ml]: ");
   scanf("%f",&new_beer->ml);

   g_nNumberOfBeers++; /* We increment since we just added a beer */
   return new_beer;
}

void seeBeers(struct Beer *beer) {
   struct Beer *tmp;
   int i;
   for (i=0; i<g_nNumberOfBeers; i++) {
      tmp=beer->next;
      printf("Type: %s\n",beer->type);
      printf("Price: %f\n",beer->price);
      printf("Percentage: %f\n",beer->alc);
      printf("Amount [ml]: %f\n",beer->ml);
      beer=tmp;
   }
}



struct Beer *typeToFind(struct Beer *beer){
    printf("typeToFind\n");
    char tmpString[81];
    printf("Type: ");
    scanf("%s",tmpString);
    
    struct Beer *tmp;
    for(int i = 0; i<g_nNumberOfBeers;i++){
        tmp = beer->next;
        if(strcmp(beer->type, tmpString) == 0){
            printf("Found: %s\n", beer->type);
            return beer;
        } else {
            beer = tmp;
        }
    }
    
    return NULL;
}


// Tester lige et nemmere koncept
int type2Find(struct Beer *beer){
    printf("typeToFind\n");
    char tmpString[81];
    printf("Type: ");
    scanf("%s",tmpString);
    
    struct Beer *tmp;
    for(int i = 0; i<g_nNumberOfBeers;i++){
        tmp = beer->next;
        if(strcmp(beer->type, tmpString) == 0){
            printf("Found: %s\n", beer->type);
            return i;
        } else {
            beer = tmp;
        }
    }
    return -1;
}


// Koncept 1
void removeSpecificBeer(struct Beer *beer){
    struct Beer *tmpBeer = typeToFind(beer);
    // Check if it actually worked finding the string
    if(tmpBeer){
        
    } else {
        return;
    }
}

// Koncept 2
void removeSpecificBeer2(struct Beer *beer){
    int tmp = type2Find(beer);
    
    struct Beer *tmpBeer;
    //tmpBeer = beer->next;
    // Check if it actually worked finding the string
    if(tmp != -1){
        for(int i = 0; i < tmp-1; i++){
            beer = beer->next;
        }
        tmpBeer = beer->
    } else {
        return;
    }
}


