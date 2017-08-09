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

int main()
{
    FILE* file;
    file = fopen("testinho.txt", "r");

    int buffer_id;
    char buffer_title[300];
    int buffer_year;
    char buffer_authors[1024];
    int buffer_citations;
    char buffer_date[50];
    char buffer_snipper[1024];

    while (fscanf(file, "\"%d\";", &buffer_id) == 1) {

        printf(" --- SEEKING RECORD AT POSITION --- \nbuffer_id : [%d] \n", buffer_id);

        if (fscanf(file, "\"%300[^\"]\";", buffer_title) == 1) {
            printf("buffer_title : [%s] \n", buffer_title);
        } else if (fscanf(file, "NULL;") == 0) {
            printf("buffer_title : nullptr(0x00000000000000000000 ** badalloc **)\n");
        }

        if (fscanf(file, "\"%d\";", &buffer_year) == 1) {
            printf("buffer_year : [%d] \n", buffer_year);
        } else if (fscanf(file, "NULL;") == 0) {
            printf("buffer_year : nullptr(0x00000000000000000000 ** badalloc **)\n");
        }

        if (fscanf(file, "\"%1024[^\"]\";", buffer_authors) == 1) {
            printf("buffer_authors : [%s] \n", buffer_authors);
        } else if (fscanf(file, "NULL;") == 0) {
            printf("buffer_authors : nullptr(0x00000000000000000000 ** badalloc **)\n");
        }

        if (fscanf(file, "\"%d\";", &buffer_citations) == 1) {
            printf("buffer_citations : [%d] \n", buffer_citations);
        } else if (fscanf(file, "NULL;") == 0) {
            printf("buffer_citations : nullptr(0x00000000000000000000 ** badalloc **)\n");
        }

        if (fscanf(file, "\"%50[^\"]\";", buffer_date) == 1) {
            printf("buffer_date : [%s] \n", buffer_date);
        } else if (fscanf(file, "NULL;") == 0) {
            printf("buffer_date : nullptr(0x00000000000000000000 ** badalloc **)\n");
        }

        if (fscanf(file, "\"%1024[^\"]\"\n", buffer_snipper) == 1) {
            printf("buffer_snipper : [%s] \n", buffer_snipper);
        } else if (fscanf(file, "NULL\n") == 0) {
            printf("buffer_snipper : nullptr(0x00000000000000000000 ** badalloc **)\n");
        }

        const long tll = ftell(file);
        printf(" *** CURSOR at %ld ***\n", tll);
    }

    // while (fscanf(file, "%50[^;];%300[^;];%50[^;];%1024[^;];%50[^;];%50[^;];%1024[^\n]\n;", buffer_id, buffer_title, buffer_year, buffer_authors, buffer_citations, buffer_date, buffer_snipper) >= 1) {
    // printf("\n\n buffer_id : %s \n buffer_title : %s \n buffer_year : %s \n buffer_authors : %s \n buffer_citations : %s \n buffer_date : %s \n buffer_snipper : %s\n", buffer_id, buffer_title,buffer_year, buffer_authors, buffer_citations, buffer_date, buffer_snipper);
    // }
}