//
//  main.c
//  isLittleEndian
//
//  Created by Mathias Lyngklip Kjeldgaard on 13/02/2017.
//  Copyright © 2017 Mathias Lyngklip Kjeldgaard. All rights reserved.
//

#include <stdio.h>

struct bits{
    int b0 : 1;
    int b1 : 1;
    int b2 : 1;
    int b3 : 1;
    int b4 : 1;
    int b5 : 1;
    int b6 : 1;
    int b7 : 1;
};
union number {
    char C;
    struct bits b;
};

int isLittleEndian(){
    union number n;
    n.C = 100;
    n.b.b5 = 0;
    printf("%d\n", n.C);
    return 0;
}

uint32_t convertNumber(uint32_t number){
    printf("%d\n",number);
    char MSB = (number >> 4);      // Most  significant 4 bits
    char LSB = (number &= 0x0F);   // Least significant 4 bits
    if(MSB > 9){
        MSB += ('A'-10);
    } else {
        MSB += '0';
    };
    if(LSB > 9){
        LSB += ('A'-10);
    } else {
        MSB += '0';
    };
    
    printf("Modtog: %d . Altså: 0x%c%c\n",number,MSB,LSB);
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    isLittleEndian();
    convertNumber(26);
    return 0;
}
