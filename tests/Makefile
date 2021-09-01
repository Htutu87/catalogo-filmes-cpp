# Makefile

CC = g++
CFLAGS = -Wall

OBJDIR = obj
DEPSDIR = ../obj
DEPS = $(DEPSDIR)/catalogo.o
EXECS = test-cin

$(OBJDIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@	

cin: $(OBJDIR)/test-cin.o $(DEPS)
	$(CC) $(CFLAGS) $(OBJDIR)/test-cin.o $(DEPS) -o test-cin

clean:
	rm $(EXECS) $(OBJDIR)/*.o
