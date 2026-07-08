# Name of your final executable
TARGET = sms

# Find all C files in the folder
SRCS = $(wildcard *.c)

# Detect which compiler is available
ifeq (, $(shell command -v gcc 2> /dev/null))
    ifeq (, $(shell command -v clang 2> /dev/null))
        $(error "no C compiler found")
    else
        CC = clang
    endif
else
    CC = gcc
endif

# Default when you enter "make"
all: $(TARGET)

# Compile all C files together
$(TARGET): $(SRCS)
	$(CC) -Wall $(SRCS) -o $(TARGET)

# Clean up rule | 'make clean'
clean:
	rm -f $(TARGET)