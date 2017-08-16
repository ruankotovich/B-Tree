#include <cstdio>
#include <cstdlib>

#define R_NOTHING 0
#define R_SOR 1
#define R_EOC 2
#define R_SON 3

struct Paper {
    int id;
    char title[300];
    int year;
    char authors[1024];
    int citations;
    char date[20];
    char snippet[1024];
};

inline char charClass(char previous, char current)
{
    // printf("[%c] [%c]\n", previous, current);
    switch (previous) {
    case '\"': {

        if (current == ';' || current == '\n' || current == EOF) {
            return R_EOC;
        }

    } break;

    case ';': {

        if (current == '\"') {
            return R_SOR;
        }

    } break;

    case '\r': {
        if (current == '\n' || current == EOF) {
            return R_EOC;
        }
    }
    }
    return R_NOTHING;
}

inline char firstContact(char previous, char current)
{
    // printf("[%c] [%c]\n", previous, current);
    switch (previous) {
    case '\"': {

        return R_EOC;
    } break;

    case ';': {
        if (current == ';') {
            return R_EOC;
        }
        if (current == 'N') {
            return R_SON;
        }

    } break;
    }
    return R_NOTHING;
}

inline void readColumn(FILE* file, char* buffer, char previous)
{
    char current = fgetc(file);
    int pointer = 0;
    char type;

    type = firstContact(previous, current);
    if (type != R_SON) {
        do {
            previous = current;

            if (type < R_SOR) {
                buffer[pointer++] = previous;
            }

            current = fgetc(file);
        } while ((type = charClass(previous, current)) < R_EOC);
    } else {
        fscanf(file, "ULL\n");
        fscanf(file, "ULL\r\n");
        fscanf(file, "ULL;");
        pointer = 1;
    }
    buffer[pointer - 1] = '\0';
}

void fileParser(FILE* file)
{
    int idBuffer;
    char titleBuffer[300];
    int yearBuffer;
    char authorsBuffer[1024];
    int citationsBuffer;
    char dateBuffer[20];
    char snippetBuffer[1024];

    char readBuffer[4096];

    while (fscanf(file, "\"%d\";", &idBuffer) == 1) {
        printf("\n\n -- Scanning for id %d : \n", idBuffer);

        // READ TITLE
        readColumn(file, readBuffer, ';');
        printf("Title : %s\n", readBuffer);

        // READ YEAR
        fscanf(file, "\"%d\";", &yearBuffer);
        printf("Year : %d\n", yearBuffer);

        // READ AUTHOR
        readColumn(file, readBuffer, ';');
        printf("Author : %s\n", readBuffer);

        // READ CITATION
        fscanf(file, "\"%d\";", &citationsBuffer);
        printf("Citation : %d\n", citationsBuffer);

        // READ DATE
        readColumn(file, readBuffer, ';');
        printf("Date : %s\n", readBuffer);

        // READ SNIPPET
        readColumn(file, readBuffer, ';');
        printf("Snippet : %s\n", readBuffer);
    }
}

int main(int argc, char* argv[])
{
    const char* filename = argv[1];
    FILE* file = fopen(filename, "rb+");
    fileParser(file);
}