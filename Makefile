# Name of your final executable
TARGET = sms

# Find all .c files in the folder
SRCS = $(wildcard *.c)

# The default rule when you type 'make'
all: $(TARGET)

# Compile ALL .c files together into ONE program
$(TARGET): $(SRCS)
	gcc -Wall $(SRCS) -o $(TARGET)

# Clean up rule (type 'make clean' to delete the app)
clean:
	rm -f $(TARGET)