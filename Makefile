#Makefile

CC =  g++
CFLAGS = -Wall 

OBJDIR = obj
SRCDIR = src
OBJS = $(OBJDIR)/main.o\
		$(OBJDIR)/catalogo.o

EXEC = catalogo

catalogo: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)
	cp $(OBJDIR)/catalogo.o tests/obj/

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	    $(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm $(EXEC) $(OBJDIR)/*.o
