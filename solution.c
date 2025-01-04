#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define INPUT_PATH "input"

FILE * input;

int   readInt();
int   readStr(int maxSize, char** str);
char* readFixedStr(int size);
long* readLongArr(int size);
int*  readIntArr(int size);
char* readCharArr(int size);


void run() {
    // Solution
}


int readInt() {
    int i;
    
    fscanf(input, "%d", &i);

    return i;
}


int readStr(int maxSize, char** str) {
    *str = malloc((maxSize + 1)*sizeof(char));

    fscanf(input, "%s", *str);

    return strlen(*str);
}

char* readFixedStr(int size) {
    char* str;

    if (readStr(size, &str) != size) {
        printf("\nWrong str size\n");
        exit(EXIT_FAILURE);
    }

    return str;
}

long* readLongArr(int size) {
    long* arr = malloc(size*sizeof(long));
    int i;

    for (i = 0; i<size; i++) {
        fscanf(input, "%li", arr + i);
    }

    return arr;
}

int* readIntArr(int size) {
    int* arr = malloc(size*sizeof(int));
    int i;

    for (i = 0; i<size; i++) {
        fscanf(input, "%d", arr + i);
    }

    return arr;
}

char* readCharArr(int size) {
    char* arr = malloc(size*sizeof(char));
    int i;

    for (i = 0; i<size; i++) {
        char c = ' ';
        while(c == ' ') fscanf(input, "%c", &c);
        * (arr + i) = c;
        
    }

    printf("%c", *(arr + i));

    return arr;
}

void setup() {
    #ifdef INPUT_PATH
    input = fopen(INPUT_PATH, "r");
    #else
    input = stdin;
    #endif
}

int main() {
    setup();

    run();

    return 0;
}