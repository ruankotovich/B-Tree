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

inline char pairClass(char previous, char current)
{
    switch (previous) {
    case '\"': {

        if (current == ';' || current == '\n' || current == EOF) {
            return R_EOC;
        }

    } break;

    case 'L': {
        if (current == ';' || current == '\n' || current == EOF) {
            return R_EOC;
        }
    } break;

    case ';': {
        if (current == ';') {
            return R_EOC;
        }
        if (current == '\"' || current == 'N') {
            return R_SOR;
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
    while ((type = pairClass(previous, current)) < R_EOC) {
        if (type < R_SOR) {
            buffer[pointer++] = previous = current;
        } else {
            fscanf(file, "UL");
        }
        current = fgetc(file);
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
        printf("%s\n", readBuffer);

        // READ YEAR
        fscanf(file, "\"%d\";", &yearBuffer);
        printf("%d\n", yearBuffer);

        // READ AUTHOR
        readColumn(file, readBuffer, ';');
        printf("%s\n", readBuffer);

        // READ CITATION
        fscanf(file, "\"%d\";", &citationsBuffer);
        printf("%d\n", citationsBuffer);

        // READ DATE
        readColumn(file, readBuffer, ';');
        printf("%s\n", readBuffer);

        // READ SNIPPET
        readColumn(file, readBuffer, ';');
        printf("%s\n", readBuffer);
    }
}

int main()
{
    FILE* file = fopen("./misc/pattern.csv", "r");
    fileParser(file);
}