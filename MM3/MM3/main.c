#include <stdio.h>

#include "Beer.h"

int menu() {
    int nSelection;
    printf("Options:\n");
    printf("1) Add new beer\n");
    printf("2) See all beers\n");
    printf("3) Stop program\n");
    printf("4) Fjern sager!\n");
   scanf("%d",&nSelection);
   return nSelection;
}

int main() {
   struct Beer *beer;
   int nSelection=0;
   beer=NULL;
   while (nSelection!=3) {
       
      nSelection=menu();
      if (nSelection==1) beer=addBeer(beer);
      else if (nSelection==2) seeBeers(beer);
      else if (nSelection==4){
          removeSpecificBeer(beer);
      }
   }
   return 0;
}

