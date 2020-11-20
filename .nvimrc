let starting = "\<C-l>clear;cd build;%s;cd .."

call MapTerminalCommand(0, "pb", printf(starting, "make"))
call MapTerminalCommand(0, "pr", printf(starting, "bin/sorting-visualizer"))
call MapTerminalCommand(0, "px", printf(starting, "make && bin/sorting-visualizer"))
