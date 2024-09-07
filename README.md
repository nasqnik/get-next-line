# get_next_line - 42 Project

Create a function capable of reading and returning a single line from a file descriptor, including the newline character, without knowing its size beforehand.

Tested with Valgrind to ensure there are no memory leaks, confirming the proper management of allocated memory.

## Bonus Files
In **the bonus** for this project, `get_next_line()` should manage multiple file descriptors at the same time using only one static variable. There is no Makefile for this project, so it should be compiled directly using cc.

- `get_next_line_bonus.c`
- `get_next_line_bonus.h`
- `get_next_line_utils_bonus.c`
