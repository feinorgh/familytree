PREFIX=/usr/local
CFLAGS+=-Wall -Wextra -MMD -MP
LDFLAGS+=
SRCDIR = src
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJDIR = $(BUILD_PREFIX)obj
_OBJS = $(SOURCES:src/%.c=%.o)
OBJECTS = $(patsubst %,$(OBJDIR)/%,$(_OBJS))
DEP = $(OBJECTS:.o=.d)

familytree: $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)


$(OBJECTS): $(OBJDIR)

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

-include $(DEP)
