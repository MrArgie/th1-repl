# Minimal TCL-like repl

Mostly based on [TH1](https://www.fossil-scm.org/index.html/doc/trunk/www/th1.md) (from Fossil SCM), using [linenoise](https://github.com/antirez/linenoise) for REPL line editing and with some extra procedures added to make it more useful. Aim is to create a minimal and slow TCL interpreter that is a good fit for baremetal embedded work. My use case requires something like JimTCL but where one can eschew the complexity (and speed) of native types for the simplicity (and small binary size) of pure strings.

WIP

License conditions for TH1 and linenoise can be found at the start of their respective header files