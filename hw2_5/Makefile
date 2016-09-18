# Written by Louis Croce
# Built off of Jae Woo Lee's sample Makefile
# This Makefile should be used as a template for future Makefiles.
# It’s heavily commented, so hopefully you can understand what each
# line does.

# We’ll use gcc for C compilation and g++ for C++ compilation

CC  = gcc
CXX = g++

# Let’s leave a place holder for additional include directories

INCLUDES =

# Compilation options:
# -g for debugging info and -Wall enables all warnings

CFLAGS   = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)

# Linking options:
# -g for debugging info

LDFLAGS = -g

# List the libraries you need to link with in LDLIBS
# For example, use "-lm" for the math library

LDLIBS =

# The 1st target gets built when you type "make".
# It’s usually your executable.  ("main" in this case.)
#
# Note that we did not specify the linking rule.
#
# Instead, we rely on one of make’s implicit rules:
#
#     $(CC) $(LDFLAGS) <all-dependent-.o-files> $(LDLIBS)
#
# Also note that make assumes that main depends on main.o,
# so we can omit it if we want to.

echo:

echo2:

echo3:

echo4:
# make uses the following implicit rule to compile a .c file into a .o
# file:
#
#     $(CC) -c $(CFLAGS) <the-.c-file>
#

# Always provide the "clean" target that removes intermediate files.
# What you remove depend on your choice of coding tools
# (different editors generate different backup files for example).
#
# And the "clean" target is not a file name, so we tell make that
# it’s a "phony" target.

.PHONY: clean
clean:
	rm -f *.o a.out core echo echo2 echo3 echo4

# "all" target is useful if your Makefile builds multiple programs.
# Here we’ll have it first do "clean", and rebuild the main target.

.PHONY: all
all: clean echo echo2 echo3 echo4