CC = gcc

CFLAGS = -Iinclude -Wall -Wextra -O2 -ffreestanding -nostdlib

LIBRARY = libstd.a

SRC_DIR = src
OBJ_DIR = obj
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: $(LIBRARY)

$(LIBRARY): $(OBJ_FILES)
	ar rcs $@ $^
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ_DIR)/*.o $(LIBRARY)
.PHONY: all clean
