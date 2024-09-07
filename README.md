# get_next_line

Create a function capable of reading and returning a single line from a file descriptor, including the newline character, without knowing its size beforehand.

In **the bonus** for this project, `get_next_line()` should manage multiple file descriptors at the same time using only one static variable.

Tested with Valgrind to ensure there are no memory leaks, confirming the proper management of allocated memory.
