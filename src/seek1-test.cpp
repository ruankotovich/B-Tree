#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "article.hpp"
#include "primarybtree.hpp"

using namespace std;

int main()
{
    PrimaryBTree btree;
   
    int id;

    FILE* indexFile = fopen("test/primaryindex.block", "rb");

    btree.readRoot(indexFile);

    FILE* keysFile = fopen("test/keyfiles.data", "rb");
    bool gambi = true;

    if (indexFile != NULL) {
        while (fread(&id, sizeof(int), 1, keysFile)) {
            Article_t a;
            auto result = btree.getArticle(id + 330, &a, indexFile);
            cout << id << "\n";

            if (!result.first) {
                gambi = false;
                cout << "RECORD NUMBER " << id << " NOT FOUND!!";
                break;
                /*cout << a.toString();
                cout << "\n\nNumber of block read in PrimaryBTree Index to find the record: " << result.second + 1;
                fseek(indexFile, 0, SEEK_END);
                cout << "\n\nTotal number of blocks in primary index file: " << ((ftell(indexFile) / sizeof(AbstractBlock_t))) << "\n";*/
            }
        }

        if (gambi) {
            cout << "NOIS SOMO ZICA CARAMBA \\o/!!";
        }
    } else {
        cout << "There isn't a primary index file.\n";
    }

    return 0;
}
