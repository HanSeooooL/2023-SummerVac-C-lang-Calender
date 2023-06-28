#ifndef vacationCalender_h
#define vacationCalender_h

//데이터 구조체
typedef struct _travel {
    int code;           //고유코드
    char country[100];  //여행 국가
    char city[100];     //목적지 도시
    int syear;          //출발 년도
    int smonth;         //출발 달
    int sday;           //출발 일
    int byear;          //도착 년도
    int bmonth;         //도착 달
    int bday;           //도착 일
} Travel;

typedef struct _microtravel {
    int code;           //고유코드
    char place[1000];   //목적지
    int day;            //몇번째 날
    int shour;          //시작 시간
    int fhour;          //종료 시간
    unsigned int money; //예상 경비
} Microtravel;


//키보드 매크로
#define UP 72        //방향키 위
#define DOWN 80        //방향키 아래
#define LEFT 75        //방향키 왼쪽
#define RIGHT 77    //방향키 오른쪽
#define ENTER 13    //엔터키
#define ESC 27        //ESC키


//달력 출력 관련 매크로
#define STARTPOINTX 10
#define STARTPOINTY 5
#define XGAP 5
#define YGAP 2


//UI
void title(void);


//Algorithm
int calfirstdayday(int today, int dayday, int plus);  //1일의 요일 계산
int checkmonthlength(int year, int month, int plus); //달의 길이 계산

//File In / OUT
Travel *Travelfilelead(int days, Travel *arr);



#endif /* vacationCalender_h */
