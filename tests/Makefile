# Makefile

CC = g++
CFLAGS = -Wall

OBJDIR = obj
DEPSDIR = ../obj
DEPS = $(DEPSDIR)/catalogo.o
EXECS = inout-test\
		comparisons-test

$(OBJDIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@	

all: inout comparisons

# Recompila o arquivo catalogo.cpp.
# OBS: O .o tem que existir no diretório pai
update-lib:
	$(CC) $(CFLAGS) -c ../src/catalogo.cpp -o ./obj/catalogo.o

inout: update-lib $(OBJDIR)/inout-test.o $(DEPS)
	$(CC) $(CFLAGS) $(OBJDIR)/inout-test.o $(DEPS) -o inout-test

comparisons: update-lib $(OBJDIR)/comparisons-test.o $(DEPS)
	$(CC) $(CFLAGS) $(OBJDIR)/comparisons-test.o $(DEPS) -o comparisons-test

clean:
	rm $(EXECS) $(OBJDIR)/*.o
