# Minimal TCL-like repl

Mostly based on [TH1](https://www.fossil-scm.org/index.html/doc/trunk/www/th1.md) (from Fossil SCM), using [linenoise](https://github.com/antirez/linenoise) for REPL line editing and with some extra procedures added to make it more useful. Aim is to create a minimal and slow TCL interpreter that is a good fit for RTOS embedded work. The use case I am aiming for requires something like JimTCL but where one can eschew the complexity (and speed) of native types for the simplicity (and small binary size) of pure strings. I need a replacement for a handcrafted CLI that could benefit from a bit of scripting and that can cope with binary hex strings without bringing unicode to the party.

Some things I'd like to add as time goes by:
- Procedures (the options for these will probably be a subset of those defined for JimTCL):
  - `foreach` - DONE
  - `switch`
  - `source`
  - `puts` - DONE
  - extra list commands: `lmap`, `lappend`, `lassign`, `linsert`, `lsort`, `lrange`, `lreplace`, `lreverse` and `lsort`. `lmap` - DONE
  - `pack`, `unpack`: same functionality as the procedures of the same name in JimTCL
  - some basic, self-contained, file I/O: `read` and `write` with filename as parameter -> no pointers, references or dangling file handles (but very slow)
  - `unknown`
  - `format`, `scan`?
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