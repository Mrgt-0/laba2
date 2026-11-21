CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -Wpedantic -O0
EXE = .exe

DIRS = ex04 ex05_and_ex06 ex07 ex09 ex10_and_ex12 ex11 ex14 ex15
.PHONY: all clean ex13 $(DIRS)
all: $(DIRS) ex13

$(DIRS):
	@echo "===== Building $@ ====="
	@gcc $(CFLAGS) $@/*.c -o $@/app$(EXE) 2>/dev/null || true
	@g++ $(CFLAGS) $@/*.cpp -o $@/app$(EXE) 2>/dev/null || true

ex13:
	@echo "===== Building ex13 (multi-file) ====="
	gcc $(CFLAGS) ex13/main.c ex13/device.c -o ex13/app$(EXE)

clean:
	@echo "===== CLEAN ====="
	-rm -f */*.exe */app