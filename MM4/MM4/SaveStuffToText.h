//
//  SaveStuffToText.h
//  MM4
//
//  Created by Mathias Lyngklip Kjeldgaard on 22/02/2017.
//  Copyright © 2017 Mathias Lyngklip Kjeldgaard. All rights reserved.
//

#ifndef SaveStuffToText_h
#define SaveStuffToText_h

#define FILENAME "savedBeers.txt"

#include <stdio.h>

    FILE openFile(char filename[]);
    #ifdef Beer_h
#ifdef FILENAME
        int saveStuff(struct Beer *beersToSave);
#else
        int saveStuff(struct Beer *beersToSave, char filename[]);
#endif
    #endif







#endif /* SaveStuffToText_h */
