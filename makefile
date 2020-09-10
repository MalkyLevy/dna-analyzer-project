CC=g++

#INC_FLAGS=-I../include

CFLAGS= -g -pedantic -Wall -Werror -Wconversion -ansi $(INC_FLAGS)

CXXFLAGS=$(CFLAGS)


# find cpp files in subdirectories
SOURCES := $(shell find . -name '*.cpp')

# find headers
HEADERS := $(shell find . -name '*.h')

OUTPUT := DNA

# Everything depends on the output
all: $(OUTPUT)

# The output depends on sources and headers
$(OUTPUT): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $(OUTPUT) $(SOURCES)

clean:
	$(RM) $(OUTPUT)

valgrind: $(OUTPUT)
	valgrind ./$(OUTPUT)
