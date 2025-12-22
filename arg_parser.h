//
// Created by alias on 12/22/2025.
//

#pragma once
#ifndef ARG_PARSER_H
#define ARG_PARSER_H
#include <stdlib.h>

#include "util.h"

typedef struct arg_pair {
    char* key;
    char* value;
} t_arg_pair;

char* as_string(struct arg_pair pair) {
    if (pair.value == nullptr)
        return pair.key;
    int key_len = strlen_custom(pair.key);
    int value_len = strlen_custom(pair.value);
    int total_len = key_len + 1 + value_len;

    char* string = (char*) calloc(total_len, sizeof(char));
    repeat(total_len) {
        if (counter < key_len) {
            string[counter] = pair.key[counter];
            continue;
        }
        if (counter == key_len) {
            string[counter] = ' ';
            continue;
        }
        if (counter - value_len >= value_len) {
            int value_index = counter - (value_len*2);
            string[counter] = pair.value[value_index];
        }
    }

    return string;
}

typedef struct arg_parser {
    int* argc;
    t_arg_pair* argv;
} t_arg_parser;

void init_arg_parser(struct arg_parser* parser, int argc, char** argv) {
    int arg_counter = 0;
    int largest_len = 0;
    parser->argc = &arg_counter;
    parser->argv = malloc(argc * sizeof(char*));
    for(int counter = 1; counter < argc; counter++) {
        t_arg_pair pair;
        char* string = argv[counter];
        pair.key = string;
        char* next = argv[counter+1];
        if (next != nullptr && !starts_with(next, '-')) {
            pair.value = next;
            counter++;
        } else {
            pair.value = nullptr;
        }

        if (strlen_custom(as_string(pair)) > largest_len) {
            largest_len = strlen_custom(as_string(pair));
        }

        parser->argv[arg_counter++] = pair;
    }
    parser->argv = realloc(parser->argv, arg_counter + 1);
}

char* get_value_string(struct arg_parser parser, char* argument) {
    repeat(*parser.argc) {
        struct arg_pair pair = parser.argv[counter];
        if (pair.key == argument) {
            return pair.value;
        }
    }
    return nullptr;
}

int has_value(struct arg_parser parser, char* argument) {
    return get_value_string(parser, argument) != nullptr;
}

#endif //ARG_PARSER_H
