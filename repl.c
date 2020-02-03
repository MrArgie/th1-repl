#include "th.h"
#include <stdio.h>
#include <stdlib.h>
#include "linenoise.h"

int main( int argc, char const * const * argv ) 
{
    int rc = 0;
    int i;
    char* line;
    Th_Vtab vtab = {.xMalloc = malloc, .xFree = free};
    Th_Interp * interp = Th_CreateInterp( &vtab );
    th_register_language( interp );

    while(1)
    {
        line = linenoise("> ");
        if(line == NULL)
            break;
        linenoiseHistoryAdd(line);
        rc = Th_Eval(interp, 1, line, -1);
        printf("[%d] %s\n", rc, Th_GetResult(interp, NULL));
        free(line);
    }

    Th_DeleteInterp( interp );
    return rc;
}
