#include <stdio.h>
#include <time.h>

int main() {
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    const char *hours[] = {"Twelve", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven"};
    const char *mins[] = {"O'clock", "Five past", "Ten past", "Fifteen past", "Twenty past", "Twentyfive past", "Half past", "Twentyfive to", "Twenty to", "Fifteen to", "Ten to", "Five to"};
    const char *ampm[] = {"AM", "PM"};
    
    if ((int) timeinfo->tm_min / 5 == 0) {
        printf("It's %s %s\n", hours[timeinfo->tm_hour % 12], timeinfo->tm_hour < 12 ? "AM" : "PM");
    } else if (timeinfo->tm_min > 30) {
        printf("It's %s %s %s\n", mins[(int) timeinfo->tm_min / 5], hours[(timeinfo->tm_hour + 1) % 12], ampm[(int) timeinfo->tm_hour/12]);
    } else {
        printf("It's %s %s %s\n", mins[(int) timeinfo->tm_min / 5], hours[timeinfo->tm_hour % 12], ampm[(int) timeinfo->tm_hour/12]);
    }
}
