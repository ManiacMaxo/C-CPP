#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 100

typedef struct {
    char name[41], num_class[max], b_Day[2], b_Month[2], b_Year[4];
    int bDay, bMonth, bYear;
    time_t Days;
} tstudent;

int isLeap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

void dateToNum(tstudent s[], int stu) {
    if (s[stu].bMonth > 1) s[stu].Days += 31;
    if (s[stu].bMonth > 2) {
        if (isLeap(s[stu].bYear) == 1)
            s[stu].Days += 29;
        else
            s[stu].Days += 28;
    }
    if (s[stu].bMonth > 3) s[stu].Days += 31;
    if (s[stu].bMonth > 4) s[stu].Days += 30;
    if (s[stu].bMonth > 5) s[stu].Days += 31;
    if (s[stu].bMonth > 6) s[stu].Days += 30;
    if (s[stu].bMonth > 7) s[stu].Days += 31;
    if (s[stu].bMonth > 8) s[stu].Days += 31;
    if (s[stu].bMonth > 9) s[stu].Days += 30;
    if (s[stu].bMonth > 10) s[stu].Days += 31;
    if (s[stu].bMonth > 11) s[stu].Days += 30;
}

int fileWrite(char* fName) {
    FILE* file;
    char s[max] = "0";
    int isFirst = 1;
    file = fopen(fName, "w");
    if (file) {
        printf("Write:\n");
        while (strcmp(s, "END") != 0) {
            if (!isFirst) {
                fprintf(file, "%s\n", s);
            }
            gets(s);
            isFirst = 0;
        }
        fclose(file);
        return 1;
    }
    return 0;
}

int fileRead(char* fName, tstudent s[]) {
    FILE* file;
    char str[max];
    int line = 0, stu = 0;
    file = fopen(fName, "r");
    if (file) {
        while (!feof(file)) {
            if (line == 3) {
                fgets(str, max, file);
                s[stu].bDay = 10 * (str[0] - '0') + str[1] - '0';
                s[stu].bMonth = 10 * (str[3] - '0') + str[4] - '0';
                s[stu].bYear = 1000 * (str[6] - '0') + 100 * (str[7] - '0') +
                               10 * (str[8] - '0') + str[9] - '0';
                stu++;
                line = 0;
            } else if (line == 1)
                strcpy(s[stu].name, str);
            else if (line == 2)
                strcpy(s[stu].num_class, str);
            line++;
        }
        fclose(file);
        return 1;
    }
    return 0;
}

void SortStructDescend(tstudent s[], int numStu) {
    int i, stu;
    tstudent temp;
    for (stu = 0; i < numStu - 1; stu++) {
        for (i = 0; i < numStu - i - 1; i++) {
            if (s[stu].bYear == s[stu + 1].bYear) {
                dateToNum(s, stu);
                if (s[stu].Days < s[stu + 1].Days) {
                    temp = s[stu];
                    s[stu] = s[stu + 1];
                    s[stu + 1] = temp;
                }
            } else if (s[stu].bYear < s[stu + 1].bYear) {
                temp = s[stu];
                s[stu] = s[stu + 1];
                s[stu + 1] = temp;
            }
        }
    }
}

int main() {
    char fName[max] = "Students.txt";
    tstudent s[max];
    int stu, numStu = sizeof s / sizeof s[0];
    printf("Enter the filename: ");
    gets(fName);
    fileWrite(fName);
    fileRead(fName, s);
    SortStructDescend(s, numStu);

    // Output
    for (stu = 0; stu < numStu; stu++) {
        printf("%s\n", s[stu].name);
        printf("№%s\n", s[stu].num_class);
        printf("%d/%d/%d", s[stu].bDay, s[stu].bMonth, s[stu].bYear);
    }
}
