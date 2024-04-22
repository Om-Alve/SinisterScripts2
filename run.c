#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replaceWord(char *str, const char *newWord, const char *oldWord) {
    char *pos, temp[1000];
    int index = 0;
    int oldWordLen = strlen(oldWord);

    while ((pos = strstr(str, oldWord)) != NULL) {
        strcpy(temp, str);
        index = pos - str;
        str[index] = '\0';
        strcat(str, newWord);
        strcat(str, pos + oldWordLen);
    }
}

int main() {
    char script[10000];

    // Read Python script from file
    FILE *file = fopen("temp.csi", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }
    fread(script, sizeof(script), 1, file);
    fclose(file);

    // Replace words
    replaceWord(script, "def", "conjure");
    replaceWord(script, "class", "coven");
    replaceWord(script, "import", "summon");
    replaceWord(script, "return", "reap");
    replaceWord(script, "print", "scream");
    replaceWord(script, "for", "haunt");
    replaceWord(script, "while", "lurk");
    replaceWord(script, "if", "dread");
    replaceWord(script, "else", "curse");
    replaceWord(script, "try", "tempt");
    replaceWord(script, "except", "ward");
    replaceWord(script, "pass", "relent");
    replaceWord(script, "break", "shatter");
    replaceWord(script, "continue", "persist");
    replaceWord(script, "True", "unholy");
    replaceWord(script, "False", "blessed");
    replaceWord(script, "None", "void");
    replaceWord(script, "and", "conjoin");
    replaceWord(script, "or", "disjoin");
    replaceWord(script, "not", "negate");

    // Write modified script to a temporary file
    FILE *tempFile = fopen("temp_script.py", "w");
    if (tempFile == NULL) {
        fprintf(stderr, "Error creating temporary file\n");
        return 1;
    }
    fputs(script, tempFile);
    fclose(tempFile);

    // Run the modified script using Python
    system("python temp_script.py");

    // Delete the temporary file
    remove("temp_script.py");

    return 0;
}
