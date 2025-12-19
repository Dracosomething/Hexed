//
// Created by alias on 12/19/2025.
//

#ifndef HEXADECIMAL_H
#define HEXADECIMAL_H
#include "string.h"

int parse_character(char hex_byte) {
    char hex_letters[] = {'a', 'b', 'c', 'd', 'e', 'f'};

    if (equals_any_ignore_case(hex_byte, hex_letters)) {
        int code = hex_byte;
        int to_remove = 55;

        if (islower(hex_byte)) {
            to_remove += 32;
        }

        return code - to_remove;
    }

    if (is_num(hex_byte))
        return hex_byte - '0';
    
    return -1;
}

int get_decimal_value() {
    
}

#endif //HEXADECIMAL_H
