#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

#define GEOSHOT_PROJECT_DIR ".geoshot"
#define GEOSHOT_CONFIG ".geoshot/config"
#define GEOSHOT_INDEX ".geoshot/index"


static void print_help(void) {
    printf("Geoshot - local version control utility for mineral resource block models files\n\n");
    printf("Usage:\n");
    printf(" geoshot init\n");
    printf(" geoshot add <file> <comment>\n");
    printf(" geoshot status <file>\n");
    printf(" geoshot check <file>\n");
    printf(" geoshot switch <file>\n");
}

static int is_regular_file(const char *path) {
    struct stat info;

    if (stat(path, &info) != 0) {
        return 0;
    }

    return S_ISREG(info.st_mode);
}

static int create_empty_file(const char *path) {
    FILE *file = fopen(path, "wbx");

    if (file == NULL) {
        perror(path);
        return -1;
    }

    if (fclose(file) != 0) {
        perror(path);
        return -1;
    }

    return 0;
}

static int init_repository(void) {
    if (mkdir(GEOSHOT_PROJECT_DIR, 0755) != 0) {
        if (errno != EEXIST) {
            perror("Geoshot: cannot create repository directory");
            return 1;
        }

        if (is_regular_file(GEOSHOT_CONFIG) &&
            is_regular_file(GEOSHOT_INDEX)) {
            printf("Geoshot: repository already initialized\n");
            return 0;
        }

        fprintf(stderr, "Geoshot: directory exists, but repository is incomplete\n");
        return 1;
    }

    if (create_empty_file(GEOSHOT_CONFIG) != 0) {
        fprintf(stderr, "Geoshot: failed to create config\n");
        return 1;
    }

    if (create_empty_file(GEOSHOT_INDEX) != 0) {
        fprintf(stderr, "Geoshot: failed to create index\n");
        return 1;
    }

    printf("Geoshot: repository initialized\n");
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_help();
        return 1;
    }

    if (strcmp(argv[1], "help") == 0 ||
        strcmp(argv[1], "--help") == 0) {
        print_help();
        return 0;
    }

    if (strcmp(argv[1], "init") == 0) {
        return init_repository();
    }

    if (strcmp(argv[1], "add") == 0) {
        printf("Geoshot: add command received\n");
        return 0;
    }

    if (strcmp(argv[1], "status") == 0) {
        printf("Geoshot: status command received\n");
        return 0;
    }

    if (strcmp(argv[1], "check") == 0) {     
        printf("Geoshot: check command received\n");
        return 0;
    }

    if (strcmp(argv[1], "switch") == 0) {
        printf("Geoshot: switch command received\n");
        return 0;
    }

    fprintf(stderr, "Geoshot: unknown command '%s'\n", argv[1]);
    fprintf(stderr, "Run 'geoshot --help' for usage\n");

    return 1;
}
