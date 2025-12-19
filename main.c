#include <stdio.h>
#include "string.h"

int main(void) {
    char* hex_string = "";

    printf("Input hex text\n");
    scanf("%s", &hex_string);

    if (starts_with(hex_string, '#')) {
        remove_first(hex_string);
    }

    char** bytes = splitstr(hex_string, 2);
    
    return 0;
}
