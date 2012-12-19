# These ar Makefile variables. They behive rather like shell variables.
CC=clang
EXEC=program
OPTS=-Wall
DEBUGOPTS=-g

# The syntax $(VAR) is how a Makefile obtains the value of the variable VAR
# It is NOT like $( ) in the shell - that performs command substitution!
#
# The next two lines tell make that the program "program" depends on the file
# program.c, and the recipe for making it is equivalent to
# 	clang -Wall -o program program.c
$(EXEC): $(EXEC).c
	$(CC) $(OPTS) -o $(EXEC) $(EXEC).c

# This recipe includes debug options
debug: $(EXEC).c
	$(CC) $(OPTS) $(DEBUGOPTS) -o $(EXEC) $(EXEC).c

# The .PHONY directive tells make not to confuse this target "clean" with an
# actual file named "clean"
#
# Remove backup files (anything ending in ~) and any object files, in addition
# to the program itself.
.PHONY:
clean:
	rm -f *.o *~ $(EXEC)
