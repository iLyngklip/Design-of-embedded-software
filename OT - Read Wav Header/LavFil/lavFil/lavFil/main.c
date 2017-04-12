//
//  main.c
//  lavFil
//
//  Created by Mathias Lyngklip Kjeldgaard on 15/03/2017.
//  Copyright © 2017 Mathias Lyngklip Kjeldgaard. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    FILE *f = fopen("waves", "w");
    if(f == NULL){
        printf("ERROR!\n");
    } else {
        printf("open\n");
    }
    
    
    for(int i = 0; i < 15; i++){
        fprintf(f, "%d\n", i);
        printf("%d\n", i);
    };
    
    fclose(f);
    printf("Closed\n");
    
    return 0;
}
