
CC = $(shell which gcc)
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c11
LDFLAGS = -lm $(shell sdl2-config --libs)

SRC_DIR = src
BIN_DIR = bin
BUILD_DIR = build
INCLUDE_DIR = include

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

EXEC = raycasting

all: $(BIN_DIR)/$(EXEC)

# Build target
$(BIN_DIR)/$(EXEC): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $@ -c $<

# Create necessary directories
$(BIN_DIR) $(BUILD_DIR):
	mkdir -p $@


# since build dir is already staged we have to make clean before comitting
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean check distcheck
