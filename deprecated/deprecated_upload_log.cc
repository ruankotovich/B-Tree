#include <cstdio>
#include <cstdlib>

struct Paper {
    int id;
    char title[300];
    int year;
    char authors[1024];
    int citations;
    char date[19];
    char snipper[1024];
};

int resourceColumnBuilder(FILE* _reader, const char* _pattern, const void* _redirect, const bool lastColumn)
{

    if (fscanf(_reader, _pattern, _redirect) < 1) {

        if (!lastColumn) {
            if (fscanf(_reader, "%*[^;];") < 0) {
                fscanf(_reader, ";");
            }
        } else {
            if (fscanf(_reader, "%*[^\n]\n") < 0) {
                fscanf(_reader, "\n");
            }
        }

        return 0;
    }

    return 1;
}

int main()
{
    FILE* file;
    file = fopen("misc/artigo.csv", "r");

    int buffer_id;
    char buffer_title[600];
    int buffer_year;
    char buffer_authors[2048];
    int buffer_citations;
    char buffer_date[50];
    char buffer_snipper[2048];

    while (fscanf(file, "\"%d\";", &buffer_id) == 1) {

        printf(" --- SEEKING RECORD AT POSITION --- \nbuffer_id : [%d] \n", buffer_id);

        // if (fscanf(file, "\"%300[^\"]\";", buffer_title) == 1) {
        //     printf("buffer_title : [%s] \n", buffer_title);
        // } else if (fscanf(file, "NULL;") == 0) {
        //     printf("buffer_title : nullptr(0x00000000000000000000 ** badalloc **)\n");
        // }

        if (!resourceColumnBuilder(file, "\"%600[^\"]\";", buffer_title, false)) {
            buffer_title[0] = '\0';
        } else {
            buffer_title[300] = '\0';
            printf("[1]Title extraction successed! %s\n", buffer_title);
        }

        // if (fscanf(file, "\"%d\";", &buffer_year) == 1) {
        //     printf("buffer_year : [%d] \n", buffer_year);
        // } else if (fscanf(file, "NULL;") == 0) {
        //     printf("buffer_year : nullptr(0x00000000000000000000 ** badalloc **)\n");
        // }

        if (!resourceColumnBuilder(file, "\"%d\";", &buffer_year, false)) {
            buffer_year = 0;
        } else {
            printf("[2]Year extraction successed! %d\n", buffer_year);
        }

        // if (fscanf(file, "\"%1024[^\"]\";", buffer_authors) == 1) {
        //     printf("buffer_authors : [%s] \n", buffer_authors);
        // } else if (fscanf(file, "NULL;") == 0) {
        //     printf("buffer_authors : nullptr(0x00000000000000000000 ** badalloc **)\n");
        // }

        if (!resourceColumnBuilder(file, "\"%2048[^\"]\";", buffer_authors, false)) {
            buffer_authors[0] = '\0';
        } else {
            buffer_authors[1024] = '\0';
            printf("[3]Author extraction successed! %s\n", buffer_authors);
        }

        // if (fscanf(file, "\"%d\";", &buffer_citations) == 1) {
        //     printf("buffer_citations : [%d] \n", buffer_citations);
        // } else if (fscanf(file, "NULL;") == 0) {
        //     printf("buffer_citations : nullptr(0x00000000000000000000 ** badalloc **)\n");
        // }

        if (!resourceColumnBuilder(file, "\"%d\";", &buffer_citations, false)) {
            buffer_citations = 0;
        } else {
            printf("[4]Citations extraction successed! %d\n", buffer_citations);
        }

        // if (fscanf(file, "\"%50[^\"]\";", buffer_date) == 1) {
        //     printf("buffer_date : [%s] \n", buffer_date);
        // } else if (fscanf(file, "NULL;") == 0) {
        //     printf("buffer_date : nullptr(0x00000000000000000000 ** badalloc **)\n");
        // }

        if (!resourceColumnBuilder(file, "\"%50[^\"]\";", buffer_date, false)) {
            buffer_date[0] = '\0';
        } else {
            printf("[5]Date extraction successed! %s\n", buffer_date);
        }

        // if (fscanf(file, "\"%1024[^\"]\"\n", buffer_snipper) == 1) {
        //     printf("buffer_snipper : [%s] \n", buffer_snipper);
        // } else if (fscanf(file, "NULL\n") == 0) {
        //     printf("buffer_snipper : nullptr(0x00000000000000000000 ** badalloc **)\n");
        // }

        if (!resourceColumnBuilder(file, "\"%2048[^\"]\"\n", buffer_snipper, true)) {
            buffer_snipper[0] = '\0';
        } else {
            buffer_snipper[1024] = '\0';
            printf("[6]Snippet extraction successed! %s\n", buffer_snipper);
        }

        // const long tll = ftell(file);
        // printf(" *** CURSOR at %ld ***\n", tll);
    }

    // while (fscanf(file, "%50[^;];%300[^;];%50[^;];%1024[^;];%50[^;];%50[^;];%1024[^\n]\n;", buffer_id, buffer_title, buffer_year, buffer_authors, buffer_citations, buffer_date, buffer_snipper) >= 1) {
    // printf("\n\n buffer_id : %s \n buffer_title : %s \n buffer_year : %s \n buffer_authors : %s \n buffer_citations : %s \n buffer_date : %s \n buffer_snipper : %s\n", buffer_id, buffer_title,buffer_year, buffer_authors, buffer_citations, buffer_date, buffer_snipper);
    // }
}