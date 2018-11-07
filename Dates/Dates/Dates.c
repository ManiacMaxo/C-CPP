#include <stdio.h>

int isLeap (int year) {
    if ((year%4==0 && year%100!=0) || (year%400==0)) {
        return 1;
    }
    else {
        return 0;
    }
}

int *prevdate (int d, int m, int y) {
    static int p[3];
    if (d>1) {
        p[0] = d-1;
        p[1] = m;
        p[2] = y;
    }
    else {
        if (m>1) {
            p[1] = m-1;
            p[2] = y;
            switch (p[1]) {
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    p[0] = 31;
                    break;
                case 4: case 6: case 9: case 11:
                    p[0] = 30;
                    break;
                case 2:
                    if (isLeap(y)==1) {
                        p[0] = 29;
                        break;
                    }
                    if (isLeap(y)==0) {
                        p[0] = 28;
                        break;
                    }
            }
        }
        else {
            p[0] = 31;
            p[1] = 12;
            p[2] = y-1;
        }
    }
    return p;
}

int *nextdate (int d,int m, int y) {
    static int n[3];
    if ((d<=27) || (d<=28 && m==2 && isLeap(y)==1) || (d<=29 && m!=2) || (d<=30 && (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12))) {
        n[0] = d+1;
        n[1] = m;
        n[2] = y;
    }
    else {
        n[0] = 1;
        if (m<12) {
            n[1] = m+1;
            n[2] = y;
        }
        else {
            n[1] = 1;
            n[2] = y+1;
        }
    }
    return n;
}

int dayoftheyear (int d, int m, int y) {
    if (m>1) d += 31;
    if (m>2) {
        if (isLeap(y)==1) d += 29;
        else d += 28;
    }
    if (m>3) d += 31;
    if (m>4) d += 30;
    if (m>5) d += 31;
    if (m>6) d += 30;
    if (m>7) d += 31;
    if (m>8) d += 31;
    if (m>9) d += 30;
    if (m>10) d += 31;
    if (m>11) d += 30;
    return d;
}

int main()
{
    int day, month, year;
    
    do {
        do {
            printf ("\nDay: ");
            scanf("%d",&day);
        } while (day<1 || day>31);
        
        do {
            printf ("\nMonth: ");
            scanf("%d",&month);
        } while (month<1 || month>12);
        
        do {
            printf ("\nYear: ");
            scanf("%d",&year);
        } while (year<1);
    } while ((day==31 && (month==2 || month==4 || month==6 || month==9 || month==11)) || (day==30 && month==2 ) || (day==29 && month==2 && isLeap(year)==0)
             );
    
    int* prev = prevdate(day, month, year);
    printf ("\nPrevious date: %d:%d:%d",*prev,*(prev+1),*(prev+2));
    
    int* next = nextdate(day,month,year);
    printf("\nNext date: %d:%d:%d", *next, *(next+1), *(next+2));
    
    int rday = dayoftheyear(day, month, year);
    printf("\nDay of the year: %d",rday);
    
    return 0;
}
