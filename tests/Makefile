# Makefile

CC = g++
CFLAGS = -Wall

OBJDIR = obj
DEPSDIR = ../obj
DEPS = $(DEPSDIR)/catalogo.o
EXECS = test-operator-lt

$(OBJDIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

lesser-than: $(OBJDIR)/test-operator-lt.o $(DEPS)
	$(CC) $(CFLAGS) $(OBJDIR)/test-operator-lt.o $(DEPS) -o test-operator-lt
 
.PHONY:

clean:
	rm $(EXECS) $(OBJDIR)/*.o
