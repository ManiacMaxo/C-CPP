#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define maxM 20
#define maxS 30

typedef struct {
    int num;
    char name[41];
    int marks[maxM];
    float avr;
} tstudent;

void SortAvr(tstudent s[], int stu) {
    int i, j, k=0;
    tstudent temp;
    for (i = 0; i < stu-1; i++) {
        for (j = 0; j < stu-i-1; j++) {
            if(s[j].avr < s[j+1].avr) {
                temp = s[i];
                s[i] = s[i+1];
                s[i+1] = temp;
            }
        }
    }
}

void SortNames(tstudent s[], int stu) {
    int i, j, k=0;
    tstudent temp;
    for (i = 0; i < stu-1; i++) {
        for (j = 0; j < stu-i-1; j++) {
            for(k=0; s[j].name[k] == s[j+1].name[k], k<41; k++);
            if (tolower(s[j].name[k]) > tolower(s[j+1].name[k])) {
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

int main() {
    int i, k, m, stu = 0, sort;
    tstudent s[maxS];
    printf("Number of students: ");
    do {
        scanf("%d", &stu);
    } while(stu<1 || stu>maxS);
    
    // Input
    printf("Number of marks: ");
    do {
        scanf("%d", &m);
    } while(m<1 || m>maxM);
    for(i=0; i<stu; i++) {
        printf("Number: ");
        scanf("%d", &s[i].num);
        printf("Name: ");
        getchar();
        gets(s[i].name);
        s[i].avr = 0;
        for(k=0; k<m; k++) {
            do {
                printf("Mark %d of %s: ", k+1, s[i].name);
                scanf("%d", &(s[i].marks[k]));
            } while(s[i].marks[k]<2 || s[i].marks[k]>6);
            s[i].avr += s[i].marks[k];
        }
        s[i].avr /= m;
    }
   
    // Sort
    printf("Sort by name press 1\nSort by average press 2\n");
    scanf("%d", &sort);
    if(sort == 1)
        SortNames(s, stu);
    else SortAvr(s, stu);
    
    // Output
    for(i=0; i<stu; i++) {
        printf("\n%3d %-41s", s[i].num, s[i].name);
        for(k=0; k<m; k++) {
            printf("%d ", s[i].marks[k]);
        }
        printf("%6.2f",s[i].avr);
    }
    printf("\n");
}
