#include <stdio.h>
#include <string.h>

int main() {
    char line[1001];
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    if (!fin || !fout) return 1;

    if (fgets(line, sizeof(line), fin)) {
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') line[len - 1] = '\0';

        char *word = strtok(line, " ");
        int max_len = 0;
        char longest_word[101] = "";  // длина слова не более 100 символов
        while (word != NULL) {
            int word_len = strlen(word);
            if (word_len > max_len) {
                max_len = word_len;
                strcpy(longest_word, word);
            }
            word = strtok(NULL, " ");
        }
        fprintf(fout, "%s", longest_word);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
