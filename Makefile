PREFIX=/usr/local
CFLAGS+=-Wall -Wextra
LDFLAGS+=
SRCDIR = src
SOURCES = $(wildcard $(SRCDIR)/*.c)
HEADERS = $(wildcard $(SRCDIR)/*.h)
OBJDIR = $(BUILD_PREFIX)obj
_OBJS = $(SOURCES:src/%.c=%.o)
OBJECTS = $(patsubst %,$(OBJDIR)/%,$(_OBJS))
DEP = $(OBJECTS:.o=.d)

familytree: $(OBJDIR) $(OBJECTS)
	$(CC) -o familytree $(OBJECTS) $(LDFLAGS)

%.d: %.c
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(DEFINES) -c $< -o $@

.PHONY: clean cleandep install uninstall

clean:
	rm -rf $(obj) familytree obj

depclean:
	rm -f $(DEP)

distclean: clean depclean

install: familytree
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp $< $(DESTDIR)$(PREFIX)/bin/familytree

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/familytree
