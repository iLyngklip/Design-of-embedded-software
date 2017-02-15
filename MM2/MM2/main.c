//
//  main.c
//  MM2
//
//  Created by Mathias Lyngklip Kjeldgaard on 15/02/2017.
//  Copyright © 2017 Mathias Lyngklip Kjeldgaard. All rights reserved.
//

#include <stdio.h>





int srtlen(char *testStreng){
    int i = 0;
    for(i=0;testStreng[i]!='\0';i++);
    return i;
};

int findTheDamnNeedle(char *haystack, char *needle){
    
    int indexHaystack = 0;
    int indexNeedle = 0;
    
    for(indexHaystack = 0; haystack[indexHaystack] != '\0' && needle[indexNeedle] != '\0'; indexHaystack++){
        if(haystack[indexHaystack] == needle[indexNeedle]){
            indexNeedle++;
        } else if(needle[indexNeedle] != '\0') {
            indexNeedle = 0;
        }
    }
    
    if(indexNeedle != 0){
        return indexHaystack-indexNeedle;
    }
    
    // Når den hertil, er der sket en fejl.
    return NULL;
    
    
    
    /* --------------------- DEN HER VIRKER!!!
    int indexHaystack = 0;
    int indexNeedle = 0;
    
    for(indexHaystack = 0; indexHaystack < strlen(haystack) && indexNeedle < strlen(needle); indexHaystack++){
        if(haystack[indexHaystack] == needle[indexNeedle]){
            char harstackTemp = haystack[indexHaystack];
            char needleTemp = needle[indexNeedle];
            indexNeedle++;
        } else if(indexNeedle != strlen(needle)) {
            indexNeedle = 0;
        }
    }
    
    if(indexNeedle != 0){
        return indexHaystack-indexNeedle;
    }
    */ // --------------------------------------
    
    
    /*
    for(index=0; haystack[index]!=needle[0] && index <= strlen(haystack); index++){
        
    };
    for(int i=0; i <= strlen(haystack) && haystack[i+index] == needle[i]; i++){
        if(i == strlen(needle)){
            return index;
        };
    };
    
    */
};




int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    char Navn[] = "Johnny Madsen";
    char haystack[] = "Jeg er mega sej og jeg hedder Mathias";
    char needle[] = "mega";
    
    printf("String har længden: %lu\n", strlen(Navn));
    printf("Needle gemmer sig ved: %d\n", findTheDamnNeedle(haystack, needle));
    
    
    return 0;
};