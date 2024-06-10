#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *file;
    char ch;
    int wordCount = 0;
    int inWord = 0;

    // Block 1:
    file = fopen("norwich.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Block 2:
    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch)) {
            if (inWord) {
                inWord = 0;
                wordCount++;
            }
        } else {
            inWord = 1;
        }
    }

    // Block 3:
    if (inWord) {
        wordCount++;
    }

    // Block 4:
    fclose(file);
    printf("Wordcount: %d\n", wordCount);
    return 0;
}
