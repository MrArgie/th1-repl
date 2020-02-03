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
    char const * arg;
    char doRender = 0;
    int gotFiles = 0;
    char gotHelp = 0;
    th_register_language( interp );
    //th_register_basic_commands( interp );
#ifdef TH_ENABLE_OB
    th_register_ob( interp );
#endif
    //th_register_client( interp );

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
