# ########################################
# ##
# ## Makefile
# ## LINUX compilation
# ##
##############################################

# Flags
# -g turn on debug info
C++FLAG = -g -std=c++14 -Wall

# Math library

MATH_LIBS = -lm
EXEC_DIR=.

# Rule for .cpp files
# .SUFFIXES : .cc.o

# $@ is target test_pints2d.o
# $< is first prerequisite test_points2d.cc
# test_points2d.cc is the source file, compile it into -> test_points2d.o
# -I. look at current directory for header files
# -c compile source file.cc into object file.o
# g++ -g -std=c++14 -Wall -I. -c test_points2d.cc -o test_points2d.o
.cc.o:
	g++ $(C++FLAG) $(INCLUDES)  -c $< -o $@

# Includes.
INCLUDES = -I.
LIBS_ALL = -L/usr/lib -L/usr/local/lib $(MATH_LIBS)

# ZEROTH PROGRAM
ALL_OBJ0 = test_points2d.o

PROGRAM_0 = test_points2d

# program_0 is the target we wanna built and : $all_objs are the dependencies
# test_points2d: test_points2d.o
#   g++ -g -std=c++14 -Wall -o ./test_points2d test_points2d.o -I. -lm

$(PROGRAM_0): $(ALL_OBJ0)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ0) $(INCLUDES) $(LIBS_ALL)
	g++ -g -std=c++14 -Wall -o ./test_pints2d test_points2d.o -I. -L/usr/lib -L/usr/local/lib -lm

# Compiling all
# make test_points2d
all:
	make $(PROGRAM_0)

# Clean obj files
clean:
	(rm -f *.o; rm -f test_points2d)

# hey: one two
# 	# Outputs "hey", since this is the target name
# 	echo $@

# 	# Outputs all prerequisites newer than the target
# 	echo $?

# 	# Outputs all prerequisites
# 	echo $^

# 	# Outputs the first prerequisite
# 	echo $<

# 	touch hey

# one:
# 	touch one

# two:
# 	touch two

# clean:
# 	rm -f hey one two