#include <stdio.h>
#include <string.h>

int main() {
    char str[1001]; // строка не более 1000 символов
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");
    if (inputFile == NULL || outputFile == NULL) {
        return 1; // ошибка открытия файла
    }

    if (fgets(str, sizeof(str), inputFile) != NULL) {
        size_t len = strlen(str);
        // удаляем перенос строки, если есть
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
            len--;
        }

        if (len > 0) {
            char last_char = str[len - 1];

            int firstPrinted = 0;
            for (int i = 0; i < len - 1; i++) { // до предпоследнего символа
                if (str[i] == last_char) {
                    if (firstPrinted) {
                        fprintf(outputFile, " ");
                    }
                    fprintf(outputFile, "%d", i + 1);
                    firstPrinted = 1;
                }
            }
        }
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
