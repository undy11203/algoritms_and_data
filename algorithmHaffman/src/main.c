#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

#include "Encode.h"
#include "Decode.h"

int main(void) {
    FILE* in;
    FILE* out;

    in = fopen("in.txt", "rb");
    out = fopen("out.txt", "wb");

    char way = (char)fgetc(in);

    if (way == 'c') {
        Encode(in, out);        
    }
    else if(way == 'd') {
        Decode(in, out);
    }

    fclose(in);
    fclose(out);

    
    return EXIT_SUCCESS;
}
