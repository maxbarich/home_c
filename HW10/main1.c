#include <stdio.h>
#include <string.h>

int main() {
    char line[101]; // максимально 100 символов + 1 для нуля
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");
    
    if (inputFile == NULL || outputFile == NULL) {
        // Обработка ошибок открытия файлов
        return 1;
    }

    // Читаем строку из файла
    if (fgets(line, sizeof(line), inputFile) != NULL) {
        // Удаляем возможный перенос строки в конце
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }
        
        // Формируем строку из трех повторений
        fprintf(outputFile, "%s, %s, %s %zu", line, line, line, len);
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
