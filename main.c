#include <stdio.h>
#include "input.h"
#include "string.h"

int main(void) {
    setvbuf(stdout, nullptr, _IOLBF, stdout->_bufsiz);
    
    printf("Input hex text\n");
    char* hex_string = read_line();
    
    if (starts_with(hex_string, '#')) {
        hex_string = remove_first(hex_string);
    }

    printf("input %s", hex_string);
    return 0;
}
