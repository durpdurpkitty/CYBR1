#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE *file;
    char word[100];
    int total_chars = 0;
    int total_words = 0;

    file = fopen("norwich.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(file, "%s", word) != EOF) {
        int len = strlen(word);
        for (int i = 0; i < len; i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
                len = i;
                break;
            }
        }
        total_chars += len;
        total_words++;
    }

    fclose(file);

    if (total_words > 0) {
        float average_length = (float)total_chars / total_words;
        printf("%.2f\n", average_length);
    } else {
        printf("File is empty.\n");
    }

    return 0;
}
