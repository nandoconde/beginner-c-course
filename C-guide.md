# C guide

## Files

### Header files

- Extension: **.h**
- Case: full lowercase

These files are needed by the linker. They should not contain more code than:

- `#define` directives
- `struct` definitions
- `typedef` statements
- `function` prototypes

## Variables

### Declaration

- All variables must be declared before they are used.
```c
int x;
x = 0;
```

- Several variables of the same type can be declared within the same line:

```c
int x, y, z;
x = 1;
y = 2;
z = 3;
```

- Variables can be initialized at declaration:
```c
int x = 0
```

### Primitive types

Types that are not objects. They are machine-dependent, and 
C-version-dependent. 

#### Integer types

The main type is `int`: signed integer of machine-dependent length. Its 
literals take the shape of signed integers.

However, it can be modified with `long long`, `long`, `short`, and `unsigned` 
for more control. Just using `long long`, `long` and `short` will work too.
`signed` is available too, but it is default.

Literals of `unsigned` end in `U` or `u`. Literals of `long` end in `L` or `l`.
Literals of `unsigned long` are any combinations of the above in that order.
Literals of `long long` are `LL` or `ll`. They can be also `unsigned`.

#### Floating point types

The main type is `double`: double-precision floating point number of 
machine-dependent length. They take 64 bits in x64 systems. All decimal 
literals are interpreted as being `double` except noted otherwise.

There is also `float`, floating point number of reduced length 
(machine-dependent) compared to `double`. Its literals are shaped `12.5f`.

#### Enum types

Selector-like type, `enum` only allows a predefined set of values to be used. 
Very useful for configuration. 

These values can be mapped to `int` in their definitions, either explicitly or 
implicitly, and several values can be mapped to the same integer values.

#### Character types

The main type is `char`. It can only represent ASCII in a meaningful way, but
it can store character bytes of other encoding schemes. With the help of other 
libraries, it may be used to process non-ASCII text. Its literals use single
quotes, `'g'` or `'7'`.

Escape sequences are also  `char`:
- `'\a'`: alert (ANSI C)
- `'\b'`: backspace
- `'\f'`: form feed
- `'\n'`: newline
- `'\r'`: carriage return
- `'\t'`: horizontal tabulation
- `'\v'`: vertical tabulation
- `'\\'`: backslash
- `'\''`: single quote (')
- `'\"'`: double quote (")
- `'\?'`: question mark (?)
- `'\0oo'`: octal value `oo` (`o` ∈ [0, 7])
- `'\xhh'`: hexadecimal value `hh` (`h` ∈ [0, F])

When using more than one character, a `char` array is used, a string.

#### Boolean type
The `_Bool` type stores either 0 or 1. Only programmed into C99 and later. 
See the [stdbool](#bool-library) for flavor.

### Array types

A

### Composite types

A

## Functions

### Operators

#### Arithmetic

- `+`: addition (sum)
- `-`: substraction (difference)
- `*`: multiplication (product)
- `/`: division
- `%`: remainder after division (modulus)
- `++`: increment value by one (pre- or post- depending on location)
- `--`: decrement value by one (pre- or post- depending on location)

#### Logical

- `&&`: AND
- `||`: OR
- `^`: XOR
- `!`: NOT


#### Assignment

- `=`: assign
- `+=`: add and assign
- `-=`: substract and assign
- `*=`: multiply and assign
- `/=`: divide and assign
- `%=`: modulus and assign
- `<<=`: left shift and assign
- `>>=`: right shift and assign
- `&=`: AND and assign
- `|=`: OR and assign
- `^=`: XOR and assign

#### Relational

- `==`: check equality
- `!=`: check difference
- `>`: check greater than
- `<`: check less than
- `>=`: check greater than or equal to
- `<=`: check less than or equal to

### `main`

Entry point to the program. It has two possible signatures: 
1. No arguments, returns `int`
2. Two arguments, returns `int`
    - `int argc`: integer with number of command-line arguments passed to the
    program
    - `char *argv[]`: array of character pointers (strings)

## Libraries

### Bool library

If included, `_Bool` is aliased to `bool` and there are new 
literals available, `true` and `false`.

```c
#include <stdbool.h>
```

### IO library

*Standard Input/Output* library. Contains `printf`, `scanf`.

```c
#include <stdio.h>
```

`printf` prints information in the shape of strings to the console. Variables 
can be interpolated within the strings that are printed using format 
specifiers. See more information on format specifiers 
[here](https://en.wikipedia.org/wiki/Printf_format_string).

```c
#include <stdio.h>
printf(format_spec_str, var1, var2, etc)
```

## Preprocessor directives

Instructions for the preprocessor program, which executes before the compiler.
It performs source code transformation to lift the burden from the programmer
and automatize some tasks.

### `include` directive

It includes other source files to the current one. This brings code that has
been coded elsewhere to scope, allowing reutilization.

If the file is followed by 
```c
#include <stdio.h>
```