//
// Created by alias on 12/19/2025.
//

#ifndef INPUT_H
#define INPUT_H
#include <stdio.h>
#include <stdlib.h>

char* read_line() {
    int cursor = 0; // current position in std in
    int character; // the current character that we are on in std in
    int p_4KB = 4096; // 4 kb
    int allocated_memory = p_4KB * sizeof(char); // current allocated memory
    char* p_string = malloc(allocated_memory); // string line is stored in

    while (p_string != nullptr && (character = getchar()) != '\n' && character != EOF) {
        if (cursor == allocated_memory) {
            p_4KB += 4096;
            allocated_memory = p_4KB * sizeof(char);
            
            if ((p_string = realloc(p_string, allocated_memory)) == nullptr) {
                free(p_string);
                return nullptr;
            }
        }
        

        p_string[cursor++] = character;
    }

    if (p_string != nullptr) {
        p_string[cursor] = '\0';
        p_string = realloc(p_string, cursor + 1);
    }
    else
        return nullptr;

    return p_string;
}

#endif //INPUT_H
