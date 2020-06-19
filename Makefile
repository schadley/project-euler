CC = g++

SOURCES = $(wildcard *.cpp)
PROGRAMS = $(patsubst %.cpp,%,$(SOURCES))

$(PROGRAMS): %: %.cpp
	$(CC) $< -o $@

.PHONY: clean
clean:
	rm -f $(PROGRAMS)
