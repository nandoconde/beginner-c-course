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

### Boolean types

TODO

### Array types

```c
// Creation
int int_storage[8]
```

### Character strings
```c
// String of 19 characters, v[19] is '\0'
char v[20]
// Initialized string, automatically adds '\0' at the end
char word[] = {'N','o','t',' ','f','u','n','n','y'}
char word2[] = {"Way better!"}
// If explicit size, account for '\0'
char word3[7] = {"Hello!"}

#include <string.h>
char src[50] = {"La donna e mobile"}
char dest[50]
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
// See more in guide
```

### Relational operators

```c
int x = 8;
int y = 9;
x == y; // False
x != y; // True
x > y;  // True
x >= y; // True
x < y;  // False
x <= y; // False
```

## Control flow

### Conditional execution - `if - else`

```c
int a = 1;
// Single-line if
if (a > 1)
    printf("Hello, smaller");

// Multiline if
if (a == 1){
    ++a;
    printf("Now it is bigger!");
}

// Single-line if-else
if (a > 1)
    printf("Hello, smaller");
else
    printf("It turnt nigger over time");

// Multiline multi-condition if-else
if (a == 1){
    ++a;
    printf("Now it is not bigger!");
} 
else if (a == 2){
    printf("This is the end");
} 
else {
    printf("Stop it");
}
```

### Ternary operator - `?:`

```c
int a = 9;
int b = 0;
(a > 8) ? (a += b) : (b += a);
```

### Selector - `switch - case`

```c
int a = 9;
switch (a){
    case 7:
        printf("7");
        break;
    case 8:
        printf("8");
        break;
    case 9:
        printf("9");
        break;
    default:
        printf("Default");
}
```

### Redirection - `goto`

```c
// Don't use this
comehere : printf("Tak");
int a = 8;
a *= 9;
if (a < 27>)
    goto comehere;
```

### Repeated execution - `for` and `while`

```c
int z = 0;
for (int i = 1, j = 2; i+j < 10; i *= 2, j -= 2){
    printf("\nHi, I just wanna say \"Hello!\" for the %d time", i+j);
}
while (z > -5){
    printf("z = %d\n", z);
    z--;
}
do{
    printf("z = %d\n", z);
    z++;
} while (z < 10)
```


## Preprocessor directives

### `include`: include libraries
```c
// Preprocessor directives begin by hash/pond sign
# include <stdio.h>  // Angular brackets to look for the file in standard system directories
# include "mylib.h"  // Apostrophes to look first in the current directory
```

### `define`: define constants
```c
// TAXRATE will be substituted at compile time everywhere by this value
#define TAXRATE 0.015
```

### `ifndef`: avoid code duplication if already defined
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