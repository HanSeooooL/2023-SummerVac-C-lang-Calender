//
//  backend.c
//  C lang Calender
//
//  Created by 한설 on 2023/06/28.
//

#include "vacationCalender.h"
#include <stdlib.h>


//1일의 요일계산
int calfirstdayday(int today, int dayday, int plus) {
    
    return ((dayday) + (7 - ((today % 7) + 6) % 7)) % 7;
}

//30일과 31일 구별
int checkmonthlength(int year, int month, int plus) {
    if ((month + plus) + 1 == 2) {
        if ( !(year % 4) && ((year % 100) || !(year % 400)))
            return 28 + 1;
        else
            return 29 + 1;
    }
    else if(((month + plus) + 1 >= 8 && (month + plus) + 1 % 2 == 0) || ((month + plus) + 1 < 8 && (month + plus) + 1 % 2 == 1))
        return 31 + 1;
    else
        return 30 + 1;
}

Travel *checkbigSchedule(int year, int month) {
    Travel *res;
    int days;
    days = checkmonthlength(year, month, 0);
    
    res = (Travel*)malloc(sizeof(Travel) * days - 1);
    
    for (int i = 0; i < days - 1; i++) {
    }
    
    return res;
}
