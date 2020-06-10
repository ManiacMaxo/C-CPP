/* ------------------------------------------------------------------------
NAME: Victor Gorchilov
CLASS: 11a
NUMBER: 8
FILE NAME: main.c
FILE PURPOSE:
implementation of the unix command `ls` in c
------------------------------------------------------------------------ */

#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define O_ALL 1 << 0
#define O_RECURSIVE 1 << 1
#define O_LONGFORMAT 1 << 2

size_t files_cnt;

char f_type(mode_t mode) {
    /* ------------------------------------------------------------------------
    FUNCTION: file type
    gets file type from mode
    PARAMETERS:
    mode : mode_t, mode to get type
    ------------------------------------------------------------------------ */

    if (mode & S_IFREG) {  // regular file
        return '-';
    } else if (mode & S_IFDIR) {  // directory
        return 'd';
    } else if (mode & S_IFBLK) {  // block special
        return 'b';
    } else if (mode & S_IFCHR) {  // character special
        return 'c';
    } else if (mode & S_IFIFO) {  // pipe
        return 'p';
    } else if (mode & S_IFLNK) {  // symbolic link
        return 'l';
    } else if (mode & S_IFSOCK) {  // socket
        return 's';
    }
    return ' ';  // not supported file
}

int long_format(char *path, char *f_name) {
    /* ------------------------------------------------------------------------
    FUNCTION: long format
    for flag `l` prints more info for file
    PARAMETERS:
    path : string, filepath
    f_name : string, name of file to print
    ------------------------------------------------------------------------ */
    struct stat st;
    stat(path, &st);
    char type = f_type(st.st_mode);
    char perms[] = "---------";
    struct passwd *pw = getpwuid(st.st_uid);
    struct group *gr = getgrgid(st.st_gid);

    // user permissions
    perms[0] = *((st.st_mode & S_IRUSR) ? "r" : "-");
    perms[1] = *((st.st_mode & S_IWUSR) ? "w" : "-");
    perms[2] = *((st.st_mode & S_IXUSR) ? "x" : "-");
    // group permissions
    perms[3] = *((st.st_mode & S_IRGRP) ? "r" : "-");
    perms[4] = *((st.st_mode & S_IWGRP) ? "w" : "-");
    perms[5] = *((st.st_mode & S_IXGRP) ? "x" : "-");
    // others permissions
    perms[6] = *((st.st_mode & S_IROTH) ? "r" : "-");
    perms[7] = *((st.st_mode & S_IWOTH) ? "w" : "-");
    perms[8] = *((st.st_mode & S_IXOTH) ? "x" : "-");

    char datetime[20];
    if (time(NULL) <= st.st_mtime + (60 * 60 * 24 * 30 * 6)) {
        strftime(datetime, 20, "%b %d %H:%M", localtime(&(st.st_mtime)));
    } else {
        strftime(datetime, 20, "%b %d %Y", localtime(&(st.st_mtime)));
    }

    printf("%c%s %hu %s %s %llu %s %s\n", type, perms, st.st_nlink, pw->pw_name,
           gr->gr_name, st.st_size, datetime, f_name);

    return st.st_blocks;
}

int print_dir(char *path, unsigned short options) {
    /* ------------------------------------------------------------------------
    FUNCTION: print directory
    traverse all files in a directory
    PARAMETERS:
    path : string, file path
    options : bitmap, options are l a and r (not case sensitive)
    ------------------------------------------------------------------------ */
    const char datatypes[] = "pcdb-ls ";
    // FIFO   1
    // CHR    2
    // DIR    4
    // BLK    6
    // REG    8
    // LNK   10
    // SOCK  12
    // WHT   14

    DIR *dir;
    dir = opendir(path);
    if (!dir) {  // permission
        fprintf(stderr, "ls: cannot open directory %s: Permission denied\n", path);
        return 1;
    }
    struct dirent *entry;
    char **dirs;
    int d = 0;
    if (options & O_RECURSIVE) {  // allocate memory only with R flag
        int dir_size = 20;
        dirs = malloc(sizeof(char *) * dir_size);  // buffer for recursive
    }
    char long_path[255];
    int blocks = 0;

    while ((entry = readdir(dir))) {
        // printf("%s\n", entry->d_name);
        // hidden files are ignored
        if ((!(options & O_ALL) &&
             (entry->d_name[0] == '.' ||
              entry->d_name[strlen(entry->d_name) - 1] == '~')) ||
            strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        if (options & O_LONGFORMAT) {  // print short format
            sprintf(long_path, "%s/%s", path, entry->d_name);
            blocks += long_format(long_path, entry->d_name);
        } else {  // print long format
            printf("%c %s\n", datatypes[(entry->d_type / 2)], entry->d_name);
        }
        // recursively iterate directories
        if ((options & O_RECURSIVE) && entry->d_type == 4) {
            char dir_path[100];
            sprintf(dir_path, "%s/%s", path, entry->d_name);
            dirs[d++] = dir_path;
        }
    }
    if (options & O_LONGFORMAT) {
        printf("total %d\n", blocks >> 1);  // total number of blocks in directory
    }
    if (options & O_RECURSIVE) {  // print stached directories
        for (int i = 0; i < d; i++) {
            printf("\n%s\n", dirs[i]);
            print_dir(dirs[i], options);
        }
        free(dirs);
    }

    closedir(dir);
    return 0;
}

void ls(unsigned short options, char **files) {
    /* ------------------------------------------------------------------------
    FUNCTION: ls
    base function for ls
    PARAMETERS:
    options : bitmap, optional, flags
    files : array[char *], optional, files to traverse
    ------------------------------------------------------------------------ */
    struct stat st;

    for (int f = 0; f < files_cnt; f++) {
        if (stat(files[f], &st) == -1) {  // non-existant file
            fprintf(stderr, "ls: cannot access %s: No such file or directory\n",
                    files[f]);
            continue;
        }

        if (st.st_mode & S_IFDIR) {  // is a directory
            if (f > 0) printf("\n%s:\n", files[f]);
            print_dir(files[f], options);
        } else {                           // not a directory
            if (options & O_LONGFORMAT) {  // long format
                long_format(files[f], files[f]);
            } else {  // short format
                printf("%c %s\n", f_type(st.st_mode), files[f]);
            }
        }
    }
}

void parse_cmdline(int argc, char **argv, unsigned short *options, char **files) {
    /* ------------------------------------------------------------------------
    FUNCTION: parse commandline
    parsing input arguments to options and files
    PARAMETERS:
    argc : int, count of argv
    argv : array[char *], input arguments to program
    options : bitmap, empty - to flags
    files : array[char *], empty - filepaths
    ------------------------------------------------------------------------ */
    *options = 0;
    //*files = NULL;

    int f = 0;
    for (int arg = 1; arg < argc; arg++) {
        if (argv[arg][0] == '-') {  // options
            // options are one string
            for (int opt = 1; opt < strlen(argv[arg]); opt++) {
                // printf("%c %d\n", argv[arg][opt], strlen(argv[arg]));
                switch (argv[arg][opt]) {
                    case 'a':
                    case 'A':
                        *options |= O_ALL;
                        break;
                    case 'l':
                        *options |= O_LONGFORMAT;
                        break;
                    case 'r':
                    case 'R':
                        *options |= O_RECURSIVE;
                        break;
                }
            }
        } else {  // filepath
            files[f++] = argv[arg];
        }
    }

    if (f == 0) {
        char *path = ".";
        files[0] = path;
        files_cnt = 1;
    } else {
        files_cnt = f;
    }
}

int main(int argc, char **argv) {
    unsigned short options = 0;  // bitmap
    files_cnt = argc - 1;
    char **files = malloc(files_cnt * sizeof(char *));  // array of pointers

    parse_cmdline(argc, argv, &options, files);
    ls(options, files);

    free(files);
    return 0;
}
