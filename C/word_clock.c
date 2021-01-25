#include <stdio.h>
#include <time.h>

int main() {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    const char *hours[] = {"Twelve", "One",  "Two", "Three",
                           "Four",   "Five", "Six", "Seven",
                           "Eight",  "Nine", "Ten", "Eleven"};
    const char *mins[] = {"",
                          "Five past",
                          "Ten past",
                          "Fifteen past",
                          "Twenty past",
                          "Twentyfive past",
                          "Half past",
                          "Twentyfive to",
                          "Twenty to",
                          "Fifteen to",
                          "Ten to",
                          "Five to"};
    const char *ampm[] = {"AM", "PM"};
    short int hour =
        timeinfo->tm_min > 30 ? timeinfo->tm_hour + 1 : timeinfo->tm_hour;

    printf("It's %s %s %s\n", mins[(int)timeinfo->tm_min / 5], hours[hour % 12],
           ampm[timeinfo->tm_hour >= 12]);
}
