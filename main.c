#include <stdio.h>
#include "input.h"
#include "util.h"
#include "hexadecimal.h"

int main(int argc, char** argv) {
    setvbuf(stdout, nullptr, _IOLBF, stdout->_bufsiz);
    
    printf("Input hex text\n");
    char* hex_string = read_line();
    
    if (starts_with(hex_string, '#')) {
        hex_string = remove_first(hex_string);
    }

    char** decimals = splitstr(hex_string, 2);
    int size = strlen_custom(hex_string) / 2;
    
    char decoded[size];
    repeat(size) {
        char* decimal_hex = decimals[counter];
        decoded[counter] = get_decimal_value(decimal_hex);
    }

    printf("%s", decoded);
    
    return 0;
}
