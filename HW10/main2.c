#include <stdio.h>

int main() {
    int N;
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");
    if (inputFile == NULL || outputFile == NULL) {
        return 1;
    }
    fscanf(inputFile, "%d", &N);
    fclose(inputFile);

    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int letterIndex = 0;
    int cycleDigits[] = {2, 4, 6, 8};
    int cycleLength = 4;

    for (int i = 1; i <= N; i++) {
        if (i % 2 != 0) {
            // нечетная позиция — буква
            fprintf(outputFile, "%c", alphabet[letterIndex]);
            letterIndex++;
        } else {
            // четная позиция — цифра по циклу
            int index = (i / 2 - 1) % cycleLength;
            fprintf(outputFile, "%d", cycleDigits[index]);
        }
    }

    fclose(outputFile);
    return 0;
}
