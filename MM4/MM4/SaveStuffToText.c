//
//  SaveStuffToText.c
//  MM4
//
//  Created by Mathias Lyngklip Kjeldgaard on 22/02/2017.
//  Copyright © 2017 Mathias Lyngklip Kjeldgaard. All rights reserved.
//

#include "SaveStuffToText.h"

FILE openFile(char filename[]){
    FILE *fp = fopen(filename, "w+");
    if(!fp){
        // Hvis der er en fejl med at åbne filen
        return *fp;
    } else {
        // Det lykkedes at åbne filen
        return *fp;
    }
    
    //return NULL;
}

#ifdef FILENAME
// Case FILENAME er defineret
int saveStuff(struct Beer *beersToSave){
    FILE *fp = openFile(FILENAME);
    if(fp){
        struct Beer *tmp;
        int i;
        for (i=0; i<g_nNumberOfBeers; i++) {
            tmp=beersToSave->next;
            fprintf(fp, "Type: %s\n",beersToSave->type);
            fprintf(fp, "Price: %f\n",beersToSave->price);
            fprintf(fp, "Percentage: %f\n",beersToSave->alc);
            fprintf(fp, "Amount [ml]: %f\n",beersToSave->ml);
            fprintf(fp, "----------\n");
            beersToSave=tmp;
        }
    } else {
        return NULL;
    }
}

#else
// case FILENAME er IKKE defineret
int saveStuff(struct Beer *beersToSave, char filename[]){
    return NULL;
}
#endif
