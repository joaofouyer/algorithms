#ifndef READ_H
#define READ_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int * readline();
char * * split_string(char * str, char * delim, int * tokens);
char* readStdin(char* string, int size);
int readInt(char * string, int size);
long readLong(char * string, int size);
int * readArray(char * string, int size);
long * readArrayLong(char * string, int size);

#endif // READ_H
