#include <stdio.h>
#include <string.h>

static void print_help(void) {
    printf("Geoshot - local version control utility for mineral resource block models files\n\n");
    printf("Usage:\n");
    printf(" geoshot init\n");
    printf(" geoshot add <file> <comment>\n");
    printf(" geoshot status <file>\n");
    printf(" geoshot check <file>\n");
    printf(" geoshot switch <file>\n");
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
        printf("Geoshot: init command received\n");
        return 0;
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
