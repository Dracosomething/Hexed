//
// Created by Draco on 12/22/2025.
//

#pragma once
#ifndef ARG_PARSER_H
#define ARG_PARSER_H
#include <stdlib.h>

#include "util.h"

typedef struct arg_pair {
  char *key;
  char *value;
} t_arg_pair;

typedef struct arg_parser {
  int argc;
  t_arg_pair *argv;
} t_arg_parser;

void init_arg_parser(struct arg_parser *parser, int argc, char **argv) {
  int arg_counter = 0;
  (*parser).argv = (t_arg_pair *)malloc(argc * sizeof(struct arg_parser));
  for (int counter = 1; counter < argc; counter++) {
    t_arg_pair pair;
    char *string = argv[counter];
    pair.key = string;
    char *next = argv[counter + 1];
    if (next != nullptr && !starts_with(next, '-')) {
      pair.value = next;
      counter++;
    } else {
      pair.value = nullptr;
    }

    (*parser).argv[arg_counter++] = pair;
  }
  (*parser).argc = arg_counter;
}

char *get_value_string(struct arg_parser parser, char *argument) {
  repeat(parser.argc) {
    struct arg_pair pair = parser.argv[counter];
    if (str_matches(pair.key, argument)) {
      return pair.value;
    }
  }
  return nullptr;
}

int has_value(struct arg_parser parser, char *argument) {
  return get_value_string(parser, argument) != nullptr;
}

#endif // ARG_PARSER_H
