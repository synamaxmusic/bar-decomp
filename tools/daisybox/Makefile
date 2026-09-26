CC := gcc
CFLAGS := -I include -flto -ggdb3 -O3 -Wall -Wextra -std=c11 -Wno-multichar -DLOG_USE_COLOR
DEFINES := -DSTB_LOG -DSTB_VECTOR
CPPFLAGS := -I.
LDFLAGS :=
BUILD_DIR := build

TARGET := daisybox
SRC_DIRS := $(shell find src -type d)
C_FILES  := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
O_FILES  := $(foreach f,$(C_FILES:.c=.o),$(BUILD_DIR)/$f) 

$(shell mkdir -p $(foreach dir,$(SRC_DIRS),$(BUILD_DIR)/$(dir)))

LIBDIR := libs
LIBS := -lcjson -lelf

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(O_FILES)
	$(CC) $(LDFLAGS) -o $@ $(O_FILES) $(LIBS)

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

genForm0:
	$(CC) $(CFLAGS) genForm0.c src/elf_parse.c $(LIBS)  -o genForm0

clean:
	rm -fr $(BUILD_DIR)
