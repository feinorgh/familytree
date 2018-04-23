PREFIX=/usr/local
CFLAGS+=-Wall
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)

LDFLAGS = -lz -lm

familytree: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

-include $(DEP)
%.d: %.c
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean cleandep install uninstall

clean:
	rm -f $(obj) familytree src/*.o

cleandep:
	rm -f $(DEP)

install: familytree
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp $< $(DESTDIR)$(PREFIX)/bin/familytree

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/familytree
