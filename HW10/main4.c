#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char word1[101], word2[101];
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    if (!fin || !fout) {
        return 1;
    }

    fscanf(fin, "%s %s", word1, word2);
    fclose(fin);

    int count1[26] = {0};
    int count2[26] = {0};

    // подсчёт частоты букв в первом слове
    for (int i = 0; word1[i]; i++) {
        count1[word1[i] - 'a']++;
    }
    // подсчёт частоты букв во втором слове
    for (int i = 0; word2[i]; i++) {
        count2[word2[i] - 'a']++;
    }

    // ищем буквы, которые встречаются ровно по одному разу в обоих словах
    int first = 1;
    for (int ch = 0; ch < 26; ch++) {
        if (count1[ch] == 1 && count2[ch] == 1) {
            if (!first) {
                fprintf(fout, " ");
            }
            fprintf(fout, "%c", ch + 'a');
            first = 0;
        }
    }

    fclose(fout);
    return 0;
}
