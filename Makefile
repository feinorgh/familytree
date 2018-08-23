PREFIX=/usr/local
CFLAGS+=-Wall -Wextra -MMD -MP
CPPFLAGS=$(CFLAGS)
LDFLAGS+=
SRCDIR = src
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJDIR = $(BUILD_PREFIX)obj
_OBJS = $(SOURCES:src/%.cpp=%.o)
OBJECTS = $(patsubst %,$(OBJDIR)/%,$(_OBJS))
DEP = $(OBJECTS:.o=.d)

familytree: $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)


$(OBJECTS): $(OBJDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CPPFLAGS) $(DEFINES) -c $< -o $@

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
