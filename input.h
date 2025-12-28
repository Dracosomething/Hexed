//
// Created by Draco on 12/19/2025.
//

#pragma once
#ifndef INPUT_H
#define INPUT_H
#include <stdio.h>
#include <stdlib.h>

char *read_line() {
  int cursor = 0;
  int character;
  int _1KB = 1024;
  int allocated_memory = _1KB * sizeof(char);
  char *p_string = (char *)malloc(allocated_memory);

  while (p_string != nullptr && (character = getchar()) != '\n' &&
         character != EOF) {
    if (cursor == allocated_memory) {
      _1KB += 4096;
      allocated_memory = _1KB * sizeof(char);

      if ((p_string = (char *)realloc(p_string, allocated_memory)) == nullptr) {
        free(p_string);
        return nullptr;
      }
    }

    p_string[cursor++] = character;
  }

  if (p_string != nullptr) {
    p_string[cursor] = '\0';
    p_string = (char *)realloc(p_string, cursor + 1);
  } else
    return nullptr;

  return p_string;
}

#endif // INPUT_H
