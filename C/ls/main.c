/* ------------------------------------------------------------------------
NAME: Victor Gorchilov
CLASS: 11a
NUMBER: 8
FILE NAME: main.c
FILE PURPOSE:
implementation of the unix command `ls` in c
using POSIX
------------------------------------------------------------------------ */

#include <dirent.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

const char datatypes[] = "p db-ls ";
// FIFO   1
// CHR    2
// DIR    4
// BLK    6
// REG    8
// LNK   10
// SOCK  12
// WHT   14

const unsigned short O_ALL = 1 << 0;
const unsigned short O_RECURSIVE = 1 << 1;
const unsigned short O_LONGFORMAT = 1 << 2;

int find(char *str, char ch) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ch) {
            return 1;
        }
    }
    return 0;
}

char f_type(mode_t mode) {
    if (mode & S_IFREG) {
        return '-';
    } else if (mode & S_IFDIR) {
        return 'd';
    } else if (mode & S_IFBLK) {
        return 'b';
    } else if (mode & S_IFCHR) {
        return 'c';
    } else if (mode & S_IFIFO) {
        return 'p';
    } else if (mode & S_IFLNK) {
        return 'l';
    } else if (mode & S_IFSOCK) {
        return 's';
    }
    return ' ';
}

void long_format(char *path) {
    struct stat st;
    stat(path, &st);
    char perms[11] = "---------";
    char type = f_type(st.st_mode);
    int files = 1;
    char date[] = "some date";
    struct passwd *user = getpwuid(st.st_uid);
    struct group *group = getgrgid(st.st_gid);

    printf("%c%s %d %s %s %llu %s %s", type, perms, files, user, group, st.st_size,
           date, path);
}

int print_dir(char *path, unsigned short options) {
    DIR *dir;
    dir = opendir(path);
    struct dirent *entry;
    // char **dirs = malloc()

    while ((entry = readdir(dir))) {
        // hidden files are ignored
        if (!(options & O_ALL) &&
            (entry->d_name[0] == '.' ||
             entry->d_name[strlen(entry->d_name) - 1] == '~')) {
            continue;
        }
        if (!(options & O_LONGFORMAT)) {  // print short format
            printf("%c %s\n", datatypes[(entry->d_type / 2)], entry->d_name);
        } else {  // print long format
            // long_format(entry->d_name);
        }
        // recursively iterate directories
        // if ((options & O_RECURSIVE) && entry->d_type == 4) {
        //     dirs[d++] = *entry->d_name;
        // }
    }

    closedir(dir);
    return 0;
}

void ls(unsigned short options, char *files) {
    struct stat st;

    for (int f = 0; f < strlen(files); f++) {
        stat(&files[f], &st);
        if (st.st_mode & S_IFDIR) {  // is a directory
            if (f > 1) printf("\n%s:\n", &files[f]);
            print_dir(&files[f], options);
        } else {
            switch (options & O_LONGFORMAT) {
                case 0:  // not long format
                    stat(&files[f], &st);
                    printf("%c %s\n", f_type(st.st_mode), &files[f]);
                    break;
                case 1:  // long format
                    long_format(&files[f]);
            }
        }
    }

    // perror("ls: cannot access %s: No such file or directory", files[0]);
}

void parse_cmdline(int argc, char **argv, unsigned short *options, char **files) {
    options = 0;
    *files = NULL;
    if (argc < 2) {  // no arguments
        char *path = ".";
        files[0] = path;
        return;
    }

    int f = 0;
    for (int arg = 1; arg < argc; arg++) {
        if (argv[arg][0] == '-') {  // options
            // options are one string
            for (int opt = 0; opt < strlen(argv[arg]); opt++) {
                switch (argv[arg][opt]) {
                    case '-':
                        break;
                    case 'a':
                        *options |= O_ALL;
                        break;
                    case 'l':
                        *options |= O_LONGFORMAT;
                        break;
                    case 'R':
                        *options |= O_RECURSIVE;
                        break;
                    default:
                        printf("Invalid option");
                }
            }
        } else {  // filepath
            files[f++] = argv[arg];
        }
    }

    // files = realloc(files, sizeof(char *) * f);
    // printf("options: %u, files: %zu\n", *options, sizeof(files));
}

int main(int argc, char **argv) {
    unsigned short options = 0;          // bitmap
    char *files = malloc(sizeof(argv));  // array of pointers

    parse_cmdline(argc, argv, &options, &files);
    ls(options, files);

    // free(files);
    return 0;
}
