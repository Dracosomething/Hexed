//
// Created by alias on 12/18/2025.
//

#ifndef STRING_H
#define STRING_H

#define repeat(AMOUNT) for (int counter = 0; counter < AMOUNT; counter++)

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

int islower(char to_check) {
    return to_check >= 'a' && to_check <= 'z';
}

int is_num(char to_check) {
    return to_check >= '0' && to_check <= '9';
}

int isupper(char to_check) {
    return to_check >= 'A' && to_check <= 'Z';
}

void init_uppercase_list(char* p_list, char lowercase_list[]) {
    int length = strlen_custom(lowercase_list);
    for (int i = 0; i < length; i++) {
        char current = lowercase_list[i];

        if (is_num(current)) {
            p_list[i] = current;
            continue;
        }

        if (islower(current)) {
            char uppercase_current = current - 32;
            p_list[i] = uppercase_current;
            continue;
        }

        p_list[i] = current;
    }    
}

int equals_any_ignore_case(char to_check, char list[]) {
    int contains = 0;
    
    int length = strlen_custom(list);
    char uppercase_list[length];
    init_uppercase_list(uppercase_list, list);

    repeat(length) {
        char lowercase = list[counter];
        char uppercase = list[counter];

        contains = to_check == lowercase || to_check == uppercase;

        if (contains)
            break;
    }

    return contains;
}

int contains_any_ignore_case(char* string, char list[]) {
    int contains = 0;

    for (int i = 0; i < strlen_custom(string); i++) {
        char current = string[i];
        contains = equals_any_ignore_case(current, list);
        if (contains)
            break;
    }
    
    return contains;
}

#endif //STRING_H
