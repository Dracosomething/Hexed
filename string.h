//
// Created by alias on 12/18/2025.
//

#ifndef STRING_H
#define STRING_H

int strlen_custom(const char* string) {
    int len = 0;

    while (*string != '\0') {
        len++;
        string++;
    }


    return len;
}

void clearstr(char* string) {
    for (int i = 0; i < strlen_custom(string); i++) {
        string[i] = '\0';
    }
}

char** splitstr(char* string, int len) {
    char* strings[];
    int str_length = strlen_custom(string);
    int strings_cursor = 0;
    
    char current[len];
    int current_cursor = 0;
    for (int i = 0; i < str_length; i++) {
        char character = string[i];

        if (current_cursor >= len) {
            strings[strings_cursor] = current;
            strings_cursor++;
            clearstr(current);
            continue;
        }

        current[current_cursor] = character;
        current_cursor++;
    }

    return strings;
}

char* remove_first(char* string) {
    char new_str[];

    for (int i = 1; i < strlen_custom(string); i++) {
        char character = string[i];
        new_str[i-1] = character;
    }

    return new_str;
}

int starts_with(char* string, char check) {
    return string[0] == check;
}

int contains_any_ignore_case(char* string, char* list) {
    
}

#endif //STRING_H
