


#define FILENAME "savedBeers.txt"
struct Beer {
   char type[81]; /* Type of beer - max of 80 letters */
   float price;   /* Price */
   float alc;     /* Percentage */
   float ml;      /* Amount milliliter [ml] */
   struct Beer *next;
};

struct Beer *addBeer(struct Beer *beer);
void seeBeers(struct Beer *beer);
struct Beer *removeBeer(struct Beer *beer,char *szType);

FILE saveStuff(struct Beer *beersToSave);
FILE openFile(char filename[]);

int g_nNumberOfBeers=0; /* Made static so it only can be accessed here */
/* g_ is for "global" */


