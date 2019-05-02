#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("filename.txt", "w");
    fprintf(fp, "Blah Blah");
    fclose(fp);

    return (0);
}