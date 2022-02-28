# C Cheatsheet

## Comments

```c
// This is a single-line comment
/*
    This is a multiline comment
*/
```

## Variables

### Integer number types

```c
short a = -4;
ushort b = 1;
int c = -0;
uint d = 1;
long e = 4L; // = 4l;
unsigned long f = 7UL; // = 7ul = 7uL = 7Ul;
long long g = -9LL; // = -9ll
unsigned long long h = 9ULL; // = 9ull = 9uLL = 9Ull;
```

### Floating-point number types

```c
float x = 9.5f;
double y = 9.5;
```

### Enum types

```c
enum enum_name {e_val0, e_val1, e_val2, e_val3 = 10, e_val4, e_val5 = -1, e_val6};
enum enum_name enum_instance;
enum_instance = e_val9; // 0
enum_instance = e_val1; // 1
enum_instance = e_val4; // 11
enum_instance = e_val6; // 0
```

### Character types

```c
char c = 'c'
c = '9'
c = 35; // '#', see ASCII table
unsigned char t = '9'
```

## Operators

### Arithmetic operators

```c
int x;
x = 4 + 2; // 6
x = 4 - 2; // 2
x = 4 * 2; // 8
x = 4 / 2; // 2
x = 7 % 3; // 1
x++ = 1;   // 2
x-- = 7;   // 6
```

### Logical operators

```c
_Bool a = 0;
_Bool b = 1;
_Bool c;
c = a && b; // 0
c = a || b; // 1
c = !a ^ b; // 0
c = !a; // 1
```


### Assignment operators

```c
int a = 8;
int b = 7;
int c;
c = a; // 8
c += b; // 15
c -= a; // 7
c *= -b; // -56
```

### Relational operators

```c

```

## Preprocessor directives

### `include`: include libraries
```c
// Preprocessor directives begin by hash/pond sign
# include <stdio.h>  // Angular brackets to look for the file in standard system directories
# include "mylib.h"  // Apostrophes to look first in the current directory
```

### `ifndef` and `define`: avoid code duplication
```c

```

## Input/Output

### Command-line arguments

```c
int main(){
    // Program logic here
}

int main(int rgc, char *argv[]){
    // Program logic with command-line arguments here
}
```

### `printf` (output)

```c
printf("Here the message with %s param %d holders", var_param1, var_param2, etc);
```

### `scanf` (input)

```c
int i
char str[100]
scanf("%d %s", &i, str)
```