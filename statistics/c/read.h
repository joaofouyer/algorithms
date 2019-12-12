#ifndef ALGORITHMS_READ_H
#define ALGORITHMS_READ_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int * readline();
char * * split_string(char * , char * , int *);
char* readStdin(char* string, int size);
int readInt(char * string, int size);
int * readArray(char * string, int size);

#endif //ALGORITHMS_READ_H
