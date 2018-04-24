PREFIX=/usr/local
CFLAGS+=-Wall -Wextra
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)

familytree: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

-include $(DEP)
%.d: %.c
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean cleandep install uninstall

clean:
	rm -f $(obj) familytree src/*.o

depclean:
	rm -f $(DEP)

distclean: clean depclean

install: familytree
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp $< $(DESTDIR)$(PREFIX)/bin/familytree

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/familytree
