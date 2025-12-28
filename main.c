#include "arg_parser.h"
#include "hexadecimal.h"
#include "input.h"
#include "util.h"
#include <stdio.h>

int main(int argc, char **argv) {
  // setvbuf(stdout, nullptr, _IOLBF, stdout->_bufsiz);
  t_arg_parser parser;
  init_arg_parser(&parser, argc, argv);

  char *hex_string = NULL;

  if (argc <= 1) {
    printf("Input hex text\n");
    hex_string = read_line();

    if (starts_with(hex_string, '#')) {
      hex_string = remove_first(hex_string);
    }
  } else {
    if (has_value(parser, "--text"))
      hex_string = get_value_string(parser, "--text");
    if (has_value(parser, "-t"))
      hex_string = get_value_string(parser, "-t");
  }

  if (hex_string == NULL)
    return 1;

  char **decimals = splitstr(hex_string, 2);
  int size = strlen_custom(hex_string) / 2;

  char decoded[size];
  repeat(size) {
    char *decimal_hex = decimals[counter];
    decoded[counter] = get_decimal_value(decimal_hex);
  }
  
  printf("%s", decoded);

  return 0;
}
