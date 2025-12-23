//
// Created by alias on 12/18/2025.
//
#pragma once
#ifndef UTIL_H
#define UTIL_H

#define repeat(AMOUNT) for (int counter = 0; counter < AMOUNT; counter++)

int strlen_custom(const char* string) {
    int len = 0;

    while (*string != '\0') {
        len++;
        string++;
    }
    
    return len;
}

char* clearstr(char* string) {
    for (int i = 0; i < strlen_custom(string); i++) {
        string[i] = '\0';
    }
}

char** splitstr(char* string, int len) {
    int str_length = strlen_custom(string);
    int final_size = str_length / len;
    char** strings = malloc(final_size * sizeof(char*));

    int strings_cursor = 0;
    int current_cursor = 0;
    
    for (int i = 0; i < str_length; i++) {
        char character = string[i];
        
        if (current_cursor >= len) {
            strings[strings_cursor++][current_cursor] = '\0';
            current_cursor = 0;
        }

        if (current_cursor == 0) {
            strings[strings_cursor] = malloc(len * sizeof(char) + 1);
        }
        
        strings[strings_cursor][current_cursor++] = character;
    }
    strings[strings_cursor][current_cursor] = '\0';

    return strings;
}

char* remove_first(char* string) {
    string++;
    return string;
}

int starts_with(char* string, char check) {
    return string[0] == check;
}

int islower_custom(char to_check) {
    return to_check >= 'a' && to_check <= 'z';
}

int is_num(char to_check) {
    return to_check >= '0' && to_check <= '9';
}

int isupper_custom(char to_check) {
    return to_check >= 'A' && to_check <= 'Z';
}

char get_lower(char uppercase) {
    return uppercase + 32;
}

char get_upper(char lowercase) {
    return lowercase - 32;
}

int equals_any_ignore_case(char to_check, char list[]) {
    int contains = 0;
    
    int length = strlen_custom(list);

    repeat(length) {
        char normal = list[counter];
        char extra;

        if (is_num(normal)) {
            contains = to_check == normal;
        }
        if (islower_custom(normal)) {
            extra = get_upper(normal);
            contains = to_check == extra || to_check == normal;
        }
        if (isupper_custom(normal)) {
            extra = get_lower(normal);
            contains = to_check == extra || to_check == normal;
        }
        
        if (contains)
            break;
    }

    return contains;
}

/**
 * TODO:
 * check every character against eachother.
 */
int str_matches(char* string1, char* string2) {
    int len1 = strlen_custom(string1);
    int len2 = strlen_custom(string2);
    if (len1 != len2)
        return 0;
    repeat(len1) {
        char char1 = string1[counter];
        char char2 = string2[counter];
        if (char1 != char2)
            return 0;
    }
    return 1;
}

#endif //UTIL_H
