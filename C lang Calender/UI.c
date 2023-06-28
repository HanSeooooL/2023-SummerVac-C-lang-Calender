//
//  UI.c
//  C lang Calender
//
//  Created by 한설 on 2023/06/28.
//

#include "vacationCalender.h"
#include "windows.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


static void gotoxy(int x, int y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

static void calender(void);
static void printcalender(int plus, Travel *arr);

void title(void) {
    calender();
}

void calender(void) {
    int n = 0;
    int cursor, X, Y;
    Travel *arr;
    printcalender(n, arr);
    X = STARTPOINTX;
    Y = STARTPOINTY + 1;
    gotoxy(X, Y);
    while (1) {
        cursor = _getch();
        switch (cursor) {
            case LEFT:
                X += XGAP;
                gotoxy(X, Y);
            case RIGHT:
                X -= XGAP;
                gotoxy(X, Y);
            case UP:
                Y -= YGAP;
                gotoxy(X, Y);
            case DOWN:
                Y += YGAP;
                gotoxy(X, Y);
            case ENTER:
                
        }
    }
}

void printcalender(int plus, Travel *arr) {
    unsigned int dayday;
    int X, Y, n;
    time_t timer;
    struct tm* t;
    
    system("clear");
    timer = time(NULL);
    t = localtime(&timer);
    dayday = calfirstdayday(t -> tm_mday, t -> tm_wday, plus);
    X = STARTPOINTX; Y = STARTPOINTY;
    gotoxy(0, 0);
    printf("%d년 %d월\n\n", (t -> tm_year + 1900), (t -> tm_mon) + 1);
    
    //sunday X좌표 10 그 뒤부터 4씩 해서 마지막 Saturday 34
    //다음 주의 같은 요일은 Y좌표 5부터 시작해서 2씩 내리기
    //여행 일정이 있는 날은 노란색으로 출력

    //30일과 31일 구별
    //if(((t -> tm_mon) + 1 >= 8 && (t -> tm_mon) + 1 % 2 == 0) || ((t -> tm_mon) + 1 < 8 && (t -> tm_mon) + 1 % 2 == 1)) n = 32;
    //else n = 31;
    
    n = checkmonthlength(t -> tm_year + 1900, (t -> tm_mon + 1), plus);
    
    for(int i = 1; i < n; i++) {
        gotoxy(X + (dayday * XGAP), Y);
        printf("%d ", i);
        dayday += 1;
        if(dayday > 6) {
            //printf("\n");
            dayday = 0;
            Y += YGAP;
        }
    }
}
