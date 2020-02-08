# Minimal TCL-like repl

Mostly based on [TH1](https://www.fossil-scm.org/index.html/doc/trunk/www/th1.md) (from Fossil SCM), using [linenoise](https://github.com/antirez/linenoise) for REPL line editing and with some extra procedures added to make it more useful. Aim is to create a minimal and slow TCL interpreter that is a good fit for RTOS embedded work. The use case I am aiming for requires something like JimTCL but where one can eschew the complexity (and speed) of native types for the simplicity (and small binary size) of pure strings. I need a replacement for a handcrafted CLI that could benefit from a bit of scripting and that can cope with binary hex strings without bringing unicode to the party.

## Existing functionality

Procedures:
- `array`
    - `exists VARNAME`
    - `names VARNAME`
- `catch SCRIPT ?VARNAME?`
- `expr EXPR`
- `for INIT CONDITION INCR SCRIPT`
- `foreach VARNAME LIST BODY`
- `if EXPR1 BODY1 ?elseif EXPR2 BODY2? ? ?else? BODYN?`
- `info`
    - `commands`
    - `args`
    - `exists VARNAME`
- `lindex LIST INDEX`
- `lappend VARNAME VALUE`
- `list ?ARG1 ?ARG2? ...?`
- `llength LIST`
- `lsearch LIST STRING`
- `lrange LIST FIRST LAST`
- `lmap VARNAME LIST BODY`
- `proc NAME ARGLIST CODE`
- `rename OLDCMD NEWCMD`
- `set VARNAME ?VALUE?`
- `string`
    - `compare STR1 STR2`
    - `first NEEDLE HAYSTACK ?STARTINDEX?`
    - `index STRING INDEX`
    - `is CLASS STRING`
    - `last NEEDLE HAYSTACK ?STARTINDEX?`
    - `length STRING`
    - `range STRING FIRST LAST`
    - `repeat STRING COUNT`
    - `trim STRING`
    - `trimleft STRING`
    - `trimright STRING`
- `unset VARNAME`
- `uplevel ?LEVEL? SCRIPT`
- `upvar ?FRAME? OTHERVAR MYVAR ?OTHERVAR MYVAR ...?`
- `puts STRING ?...?`
- `breakpoint`
- `return ?-code CODE? ?VALUE?`
- `break ?VALUE...?`
- `continue ?VALUE...?`
- `error ?VALUE...?`

## Roadmap

Some things I'd like to add as time goes by:
- New procedures (with generally minimal choice when it comes to options):
    - `switch STRING PATTERN BODY ?PATTERN BODY ...?`
    - extra list commands
        - `linsert LIST INDEX ELEMENT`
        - `lreverse LIST`
        - `lsort LIST`
    - `unknown`
    - `format`, `scan`?
- Filesystem module (separate c file since it would need porting per arch.). No allowance for changing dir:
    - `glob ?DIRNAME? PATTERN`
    - `source FILENAME`
    - `file`
        - `copy ?-force? SOURCE TARGET`
        - `move ?-force? SOURCE TARGET`
        - `rm FILENAME`
        - `size FILENAME`
        - `isfile FILENAME`
        - `mtime FILENAME`
        - `mkdir DIRNAME`
        - plus some basic, self-contained file I/O with filename as parameter -> no pointers, references or dangling file handles (but very slow)
            - `read FILENAME OFFSET SIZE`
            - `append FILENAME DATA`
            - `write FILENAME OFFSET DATA`
- Pack module, same functionality as the procedures of the same name in JimTCL, just perhaps using subcommands instead of -option:
    - `pack`
    - `unpack`
- Being able to inspect the interpreter state from another context
- Being able to abort/cancel a script from another context

WIP

## Why TCL?

Lends itself very well to commandline-like interfaces

### Why not Scheme?

TBD

### Why TH1?

TBD. To be honest, outside of very restricted embedded work, JimTCL is probably a better pick

License conditions for TH1 and linenoise can be found at the start of their respective header files