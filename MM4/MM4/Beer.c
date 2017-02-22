#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct Beer *removeBeer(struct Beer *beer,char *szID) {
   struct Beer *start,*old;
   int i;
   start=beer; /* Vi gemmer oprindelig entry til listen til senere brug */
   old=NULL; /* Til at starte med antager vi, at der ikke er en tidl. node */
   for (i=0; i<g_nNumberOfBeers; i++) {
      if (!strcmp(szID,beer->type)) { /* Fundet saa derfor slet */
         if (!old) { /* Hovsa! Det var faktisk den foerste node vi ville slette! */
            old=beer->next; /* Vi bruger nu old som den nye foerste node og sparer en variabel */
            free(beer); /* beers naeste er gemt, saa ud med beer */
            g_nNumberOfBeers--;
            return old; /* Entry til listen er aendret saa vi maa returnere denne */
         }
         /* Vi naar kun hertil, hvis vi er et sted inde i listen */
         old->next=beer->next; /* Vi springer over den node der skal slettes */
         free(beer); /* Vi kan nu roligt slette noden, da beer->next er gemt */
         g_nNumberOfBeers--;
         return start; /* Da foerste node ikke matchede, returnerer vi bare den oprindelige entry */
      }
      old=beer; /* Vi gemmer lige den gamle beer */
      beer=beer->next; /* Intet match, saa vi hopper videre til naeste node */
   }
   return start; /* Vi har ikke fundet en bajer der matchede */
}



void oneDoesSimplyNotSaveBeer(struct Beer *beersToSave){
    FILE *fp = fopen("/Users/iLyngklip/Dropbox/AAU/jegErSej.txt","w");
    if(!fp)
    {
        printf("THIS IS BULLSHIT\n");
    } else
    {
        // printf("Jeg er faktisk sej\n");
        // printf("%d\n", fp);
        struct Beer *tmp;
        fprintf(fp, "%s %d\n", "antalBajer",g_nNumberOfBeers);
        for (int i=0; i<g_nNumberOfBeers; i++)
        {
            tmp=beersToSave->next;
            fprintf(fp, "%s %s\n", "Type:", beersToSave->type);
            fprintf(fp, "%s %f\n", "Price:", beersToSave->price);
            fprintf(fp, "%s %f\n", "Percentage:", beersToSave->alc);
            fprintf(fp, "%s %s %f\n", "Amount", "[ml]:", beersToSave->ml);
            beersToSave=tmp;
            printf("dillertest\n");
        }
        fclose(fp);
    }
}

struct Beer *oneDoesSimplyGetBeerFromPlaces(struct Beer *beer){
    FILE *fp = fopen("/Users/iLyngklip/Dropbox/AAU/jegErSej.txt","r");
    struct Beer *readBeer;
    /* Allocate space for new element/node: */
    readBeer=(struct Beer *)malloc(sizeof(struct Beer));
    /* Insert new element/beer before any other element: */
    readBeer->next=beer;
    char strings[5][15];
    // char type[6];
    char price[7];
    
    
    fscanf(fp, "%s %d", strings, &g_nNumberOfBeers);
    
    // char typeBeer[81];
    if(g_nNumberOfBeers != 0){
        char tempType[81];
        float tempVals[3];
        char tempStorage[100];
        fgets(tempStorage, 100,fp);
        for(int i = 0; i< g_nNumberOfBeers; i++){
            
            for(int k=0;k<=4;k++){
                fgets(tempStorage, 100, fp);
                if(k==0){
                    sscanf(tempStorage, "%s %s",strings[0],tempType);
                } else if(k==4){
                // stuff
                    sscanf(tempStorage, "%s %s %f", strings[0],strings[1],&tempVals[k-1]);
                } else {
                    sscanf(tempStorage, "%s %f",strings[0], &tempVals[k-1]);
                }
                /*sscanf(tempStorage,"%s %d %s %80s %s %f %s %f %s %s %f",
                       strings[0],
                       &g_nNumberOfBeers,
                       strings[1],
                       readBeer->type,
                       &price,
                       &readBeer->price,
                       strings[3],
                       &readBeer->alc,
                       strings[4],
                       strings[0],
                       &readBeer->ml
                       );
                 */
            }
            // Gem data her!
            strcpy(tempType, readBeer->type);
            readBeer->price = tempVals[0];
            readBeer->alc = tempVals[1];
            readBeer->ml = tempVals[2];
            
        }
    }
    
 //
    
    printf("Antal bajer fundet: %d\n", g_nNumberOfBeers);
    
    
    // struct Beer *tmp;
    int i;
    printf("Har fundet:\n");
    for (i=0; i<g_nNumberOfBeers; i++) {
        printf("Type: %s\n",readBeer->type);
        printf("Price: %f\n",readBeer->price);
        printf("Percentage: %f\n",readBeer->alc);
        printf("Amount [ml]: %f\n",readBeer->ml);
    }
    
    fclose(fp);
    // addBeer(readBeer);
    return readBeer;
    
}





