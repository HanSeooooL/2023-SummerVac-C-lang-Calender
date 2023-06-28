//
//  Fileinout.c
//  C lang Calender
//
//  Created by 한설 on 2023/06/28.
//

#include <stdio.h>
#include <stdlib.h>
#include "vacationCalender.h"

#define MAX_CHAR_PER_LINE 1000

Travel *Travelfilelead(int days, Travel *arr) {
    FILE *fp;
    char str[MAX_CHAR_PER_LINE];
    fp = fopen("rank.txt", "r");
    if (fp != NULL) {
        while (fgets(str, MAX_CHAR_PER_LINE, fp)) {
            
        }
        fclose(fp);
    }
    return arr;
}
