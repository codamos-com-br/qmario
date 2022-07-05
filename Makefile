CC=clang
CFLAGS=-std=c99 -Wall
LFLAGS=

SRCDIR=src
BUILDDIR=build
OUT=qmario

OBJS=$(BUILDDIR)/cpu.o
MAINOBJ=$(BUILDDIR)/main.o
TOBJS=$(BUILDDIR)/cpu.test.o

run: $(BUILDDIR)/$(OUT)
	$(BUILDDIR)/$(OUT)

test: $(BUILDDIR) $(OBJS) $(TOBJS)
	$(CC) $(OBJS) $(TOBJS) -o $(BUILDDIR)/tests $(LFLAGS)
	$(BUILDDIR)/tests

# Constrói o executável principal
$(BUILDDIR)/$(OUT): $(BUILDDIR) $(OBJS) $(MAINOBJ)
	$(CC) $(OBJS) $(MAINOBJ) -o $(BUILDDIR)/$(OUT) $(LFLAGS)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

.PHONY: clean
clean:
	$(RM) -r $(BUILDDIR)

