CC=clang
CFLAGS=-std=c99 -Wall
LFLAGS=

SRCDIR=src
BUILDDIR=build
OUT=qmario

OBJS=$(BUILDDIR)/cpu.o \
	 $(BUILDDIR)/bus.o
MAINOBJ=$(BUILDDIR)/main.o
TOBJS=$(BUILDDIR)/bus.test.o \
	  $(BUILDDIR)/cpu.test.o

run: $(BUILDDIR)/$(OUT)
	$(BUILDDIR)/$(OUT)

test: $(BUILDDIR) $(OBJS) $(TOBJS)
	for i in $(TOBJS); do \
		$(CC) $(OBJS) $$i -o $(BUILDDIR)/tests $(LFLAGS); \
		$(BUILDDIR)/tests; \
	done

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

