# C guide

- [C guide](#c-guide)
  - [Files](#files)
    - [Header files](#header-files)
  - [Variables](#variables)
    - [Declaration](#declaration)
    - [Primitive types](#primitive-types)
      - [Integer types](#integer-types)
      - [Floating point types](#floating-point-types)
      - [Enum types](#enum-types)
      - [Character types](#character-types)
      - [Character strings](#character-strings)
      - [Boolean type](#boolean-type)
    - [Pointer types](#pointer-types)
      - [Pointer initiallization](#pointer-initiallization)
      - [Addressing](#addressing)
      - [Constants](#constants)
      - [Void pointers](#void-pointers)
    - [Array types](#array-types)
      - [Declaration](#declaration-1)
      - [Access](#access)
      - [Initialization](#initialization)
      - [Multidimensional](#multidimensional)
      - [Variable-length array](#variable-length-array)
      - [Arrays as pointers](#arrays-as-pointers)
    - [Composite types - `struct`](#composite-types---struct)
    - [Constants](#constants-1)
    - [Scope](#scope)
  - [Dynamic memory allocation](#dynamic-memory-allocation)
    - [`malloc` and `free`](#malloc-and-free)
    - [`calloc` and `free`](#calloc-and-free)
    - [`realloc` and `free`](#realloc-and-free)
  - [Functions](#functions)
    - [User-defined](#user-defined)
      - [Prototypes](#prototypes)
      - [Parameters (inputs)](#parameters-inputs)
      - [Return (output)](#return-output)
    - [Operators](#operators)
      - [Arithmetic](#arithmetic)
      - [Logical](#logical)
      - [Assignment](#assignment)
      - [Relational](#relational)
      - [Bitwise](#bitwise)
      - [`sizeof`](#sizeof)
      - [Ternary operator](#ternary-operator)
      - [Pointer](#pointer)
      - [Casting operators](#casting-operators)
      - [Precedence](#precedence)
    - [Casting](#casting)
      - [Implicit casting](#implicit-casting)
      - [Explicit casting](#explicit-casting)
    - [`main`](#main)
  - [Control flow](#control-flow)
    - [Conditional execution - `if-else`](#conditional-execution---if-else)
    - [Ternary operator `?:`](#ternary-operator-)
    - [Selector - `switch - case`](#selector---switch---case)
    - [Redirection - `goto`](#redirection---goto)
    - [Repeated execution - `for` and `while`](#repeated-execution---for-and-while)
      - [`for` loop](#for-loop)
      - [`while` and `do-while`](#while-and-do-while)
    - [Loop control - `break` and `continue`](#loop-control---break-and-continue)
  - [Libraries](#libraries)
    - [Bool library](#bool-library)
    - [String and character libraries](#string-and-character-libraries)
    - [Standard library](#standard-library)
    - [Standard definitions library](#standard-definitions-library)
    - [Limits library](#limits-library)
    - [Vararg library](#vararg-library)
    - [Time library](#time-library)
    - [Error library](#error-library)
    - [IO library](#io-library)
      - [Streams](#streams)
      - [Reading](#reading)
      - [Writing](#writing)
      - [Position](#position)
    - [Math libraries](#math-libraries)
    - [Assertions library](#assertions-library)
  - [Preprocessor directives](#preprocessor-directives)
    - [`include` directive](#include-directive)
    - [`define` directive](#define-directive)
  - [Compilation](#compilation)
    - [Flags](#flags)

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

#### Character strings

Its literals use double-quote enclosing. A string with a single character 
cannot be directly casted into a `char`.

In order to write special characters, scaping must be used (with a backslash)
before the character being escaped.

The *null character* `'\0'` is introduced at the end of each string in order for 
the compiler to know where it ends. This means that the length of a string is 
always one character greater than the actual number of readable characters.
(Do not confuse with the `NULL` keyword.)

If initialized, use list of single-quote characters (hard) or list of a single
double-quote string (easiest), and leave size automatic for the compiler, and 
it will inser the *null character* at the end. If not, the *null character* is
not introduced, and will cause errors while trying to read the char array. So,
**always leave size automatic for the compiler** (if possible). If oversized, 
the *null character* is still added, and the remaining are not set to anything.

Assignment to char arrays cannot be done naïvely:
- Use element-by-element assignment, forget not the *null character*
- Use `strncpy()`

Equality between char arrays through:
- Element-by-element loop
- `strcmp()`

#### Boolean type

The `_Bool` type stores either 0 or 1. Only programmed into C99 and later. 
See the [stdbool](#bool-library) for flavor.

### Pointer types

Pointer types store memory addresses, i.e.: they *point* towards the memory
location where a particular variable can be found. They are type-dependent,
which means that a pointer is not just a pointer, but a pointer *to* a value of
type `T`. They have their own format specifier for printing, `%p`.

The size of a pointer is machine-dependent, and can be obtained through:
```c
(int)sizeof(p)
```

#### Pointer initiallization

Pointers must be initiallized at creation. If the memory address is yet 
unknown they must be initiallized to `NULL` or `0` but, in order to be able to 
do it, the `stddef` library must be `#include`'d. `NULL` can be tested using 
`p == NULL` or `!p`.

#### Addressing

The **address** of an existing variable can be accessed by `&varname`.

The **contents** of an existing pointer can be accessed by `*pvarname`. This is
known as *dereferencing* a pointer. 

To know the address of a pointer itself, it must be casted to a `void*`.

The variable names for pointers usually begin with `p`, to facilitate 
understanding.

#### Constants

A pointer can both *point* to a constant or *be* a constant in itself. The 
former means that the value to which the pointer addresses cannot be changed 
through dereferencing (`*`); the latter means that the address to which the 
pointer signals cannot be changed, but its contents can.

The syntax for a *pointer to a constant* is:
```c
const int *pnumber = &number
```

The syntax for a *constant pointer* is:
```c
int *const pnumber = &number
```

A *constant pointer to a constant value* can be created combining both:
```c
const int *const pnumber = &number
```

Note that in any of these cases, `number` can be changed accessing to it from
its variable name (`name`) instead of dereferencing the pointer (`pnumber`).

#### Void pointers

Pointers whose pointing datatype is unknown unintentionally or on purpose. They
are mainly used for agnostic implementations or handling objects through 
arguments without knowing their types in advance.

They cannot be dereferenced directly, since it is impossible to know the type
of their outcome: they must be cast to a pointer of definite type before.

### Array types

- Types: same type for all elements
- Size: fixed at declaration
- Indices: 0-based

#### Declaration

Array are declared with `type_of_elements name[size]`, where:
- `type_of_elements` is a `type`
- `name` is a valid variable name (for the array itself)
- `size` is an `int` known at the time of declaration, which must be a literal,
a `define` or a constant.

#### Access

Arrays are accessed with brackets. Valid indices range from 0 to `size` - 1.
If access is attempted with an index outside this range, an 
**out-of-bounds value will be returned silently** (i.e.: without any compiler
warning or error). This may result in:
- **Incorrect results:** always wrong, easily detected
- **Unreliable results:** sometimes wrong, difficult to detect
- **PC memory corruption:** fatal, not always happens, difficult to detect

#### Initialization

An array can be initialized at creation providing a list of values, separated 
by commas (`,`) within curly brackets (`{}`). The list may not be exhaustive; 
in this case, the remaining values are initialized to *zero*. The meaning of 
*zero* depends on the type of the array:

- `int`: 0
- `float`: +0.0

**Designated initializers** allow initializing the array to specific values in 
specific locations, specified by constant integers in the list by square 
brackets (`[]`), followed by `=` and the value. They are a part of ISO C99, but
some compilers support them as an extension of C90. The rest of the values are 
set to zero.

Initializing all elements to a non-zero value requires a loop.

#### Multidimensional

Multidimensionall arrays in C are just arrays of arrays. Values are stored by
last dimension first. They can be initialized with lists of lists or just by 
values, but braces improve legibility. Designated initializers can be used.

#### Variable-length array

It is not that the length of the array is variable, rather the size indicator at
initialization is. 
- Only C99 and later
- They cannot be initialized

#### Arrays as pointers

An array is a pointer that addresses the first element of the array. This means
that addressing an array at the `n`-th element, `array[n]`, is equivalent to
accessing the contents of the pointer advanced n elements, `*(array + n)`. Both
work either if `array` is a pointer variable or an array variable, but 
arithmetic increment or decrement arithmetic (`++` or `--`) only works with 
pointers.

There are two ways to assign an array to a pointer:
- Whole binding: `int *pIntArray = intarray`
- First element address: `int *pIntArray = &intarray[0]`

### Composite types - `struct`

These types store others inside, which can be addressed by name instead of by 
index (as they are in arrays). Another difference with arays is that the 
contents are not limited to variables of the same type, although their types
must be constant across all instances of those `struct`s.

The memory allocated for it is automatically calculated by the compiler. 

Instantiation is similar to `enum`:
```c
// Definition
struct newType{
  int a;
  int b;
};
// Instancing
struct newType new_type_instance;
```

But it is also similar to arrays:
```c
struct newType c = {1, 4}; // a = 1, b = 4
struct newType d = {.b = 4, .a = 1}; // a = 1, b = 4
```

In C11, a tuple (curly braces) can be casted to a struct using ordered or named
arguments:

```c
y = (newType) {1,4};
z = (newType) {-b = 4, .a = 1};
```

A common construction is an array of structures, which are created the same 
way as other arrays, initialization included:

```c
struct newType arr[5];
struct newType arr2[5] = {{1, 4}, {5, 10}, {7, 15}};
struct newType arr3[5] = {[4] = {1, 4}};
struct newType arr4[5] = {[3].a = 1, [3].b = 4};
```

Structures are passed by value, so it is faster and more efficient to pass a 
pointer to a structure to avoid unnecessary copies of the structure being 
dispatched. To address its contents, first they must be dereferenced either:
- using parentheses (because of precedence)
- through the field-of-struct-from-pointer operator
```c
struct newType *pnew_type_instance;
pnew_type_instance = &new_type_instance
(*pnew_type_instance).a = 4
pnew_type_instance -> a = 4
```

A common construction is using a struct of pointers instead of a pointer to a 
struct. This way, its contents can be accessed through dereference directly, 
and it is not as costly to pass them by value:

```c
struct P {
  int *a;
  int *b;
}
int i = 1;
int j = 4;
struct P p = {&i, &j}
*p.a = 5;
*p.b = 10;
```

If structs are returned as pointers by a function, they should be located in 
the heap. (**CHECK THIS**)

### Constants

Symbolic constants can be created through keyword `const`. It allows 
controlling the type of the constant, and its scope (more flexible than 
`#define`). It makes the variable 'read-only', and its value cannot be altered.
Another way to create similar constants is through `enum`.

It allows initializing arrays, included `char` arrays. This is good for 
`formatspec` strings and logs.

### Scope

Local variables are those that can only be accessed from within the function or
code block they have been created. If a local variable has the same name as a 
global variable, the global is "masked", and only the local is accessible in 
the usual way.

Global variables can be accessed by any function in the program. Their 
lifetimes are linked to the program itself. They must be declared outside the 
function. They must be avoided at all costs. Instead, use parameters. If a lot
of data must be passed around, use a struct.

## Dynamic memory allocation

Since arrays must know at compile or runtime what is the maximum number of 
elements, it lacks flexibility for variable-length arrays and situations where
they are encountered (such as reading from a file). Dynamic memory allocation
assigns just enough memory that excess it is not wasted.

It works by assigning memory on the heap, instead of using the stack. When a 
function is called, it stores its contents (arguments and local variables) in
the stack; memory used during the function is freed automatically at the end 
of the call. When memory is allocated in the heap, the user must free it by 
hand. Some guidelines to work with dynamic memory allocation are:

- *Reduce calls to memory allocation functions:* heap  allocation has greater 
  overhead, so it is better used for a few great allocations rather than several
  small ones.
- *Eager memory freeing:* free allocated memory as soon as it has been used, and
  decide on a stable place to perform the freeing (either at the end of its use,
  or in a common subroutine). 
- *Do not overwrite original allocation address:* if it is lost, memory will 
  leak. Extreme care when allocating within a loop.

Dynamic memory allocation functions are `malloc`, `calloc`, and `realloc`. (See
the standard-library section for more.)

### `malloc` and `free`

- Simplest memory allocation function
- Asks for `n` bytes
- Returns a `void` pointer to the first byte
- Returns `NULL` if unable to allocate the memory
  - Because insufficient memory
  - Because of faulty processes
  - Any other detectable reason
- Check for `NULL` first
- Memory must be freed using `free` when finished
  - The program will free it at the end otherwise
  - But it is prone to errors, and may crash the computer
  - After using `free`, set the pointer to `NULL` to avoid problems
- A pointer to the origin must be kept at all times to do it
  - Otherwise, it may consume all memory

```c
// Request 100 bytes
// The actual number of int that it can store will be machine-dependent
int *pNumbers = (int*) malloc(100);

// To ensure a fixed number, use sizeof
int *pXNumbers = (int*) malloc(25*sizeof(int));

// Free mallocs
free(pNumebrs);
free(pXNumbers);

// Set to NULL
pNumbers = NULL
pXNumbers = NULL
```

### `calloc` and `free`

- Asks for allocation of `n` elements
- Initializes memory contents to zero
- Returns a `void` pointer to the first byte
- Returns `NULL` if unable to allocate the memory
  - Because insufficient memory
  - Because of faulty processes
  - Any other detectable reason
- Check for `NULL` first
- Memory must be freed using `free` when finished
  - The program will free it at the end otherwise
  - But it is prone to errors, and may crash the computer
  - After using `free`, set the pointer to `NULL` to avoid problems
- A pointer to the origin must be kept at all times to do it
  - Otherwise, it may consume all memory

```c
// Request 100 elements of type int
int *pNumbers = (int*) calloc(100, sizeof(int));

// Free mallocs
free(pNumebrs);

// Set to NULL
pNumbers = NULL
```

### `realloc` and `free`

- Asks for allocation of `n` **more** bytes
- Transfers the contents of the previous allocation to the new one
- Returns a `void` pointer to the first byte
- Returns `NULL` if unable to allocate the memory
  - Because insufficient memory
  - Because of faulty processes
  - Any other detectable reason
- Check for `NULL` first
- Memory must be freed using `free` when finished
  - The program will free it at the end otherwise
  - But it is prone to errors, and may crash the computer
  - After using `free`, set the pointer to `NULL` to avoid problems
- A pointer to the origin must be kept at all times to do it
  - Otherwise, it may consume all memory

```c
// Request 100 elements of type int
int *pNumbers = (int*) calloc(100, sizeof(int));
int *pNumbers = (int*) realloc(pNumbers, 10 * sizeof(int));

// Free allocations
free(pNumebrs);

// Set to NULL
pNumbers = NULL
```

## Functions

### User-defined

Defined through the `ret_type fun_name(params) {}` syntax, contains three parts:

1. Signature/Header: indicates the type of the result returned, the number, 
order and name of arguments, and the name used to call the function.
2. Body: statements that operate on the arguments and returns a result

Valid function names are the same as those used for variables. Collisions must
be avoided between them and variables and other functions, either user-defined
or library-imported.

#### Prototypes

Statements that define functions (the headers), but without body. Used for
agreement to specify what is expected and what is returned. Ended in semicolon.

They enable the compiler to generate appropriate calling instructions, and 
enable the user to call them anywhere regardless of where they are implemented.
They are usually located in header files.

#### Parameters (inputs)

Parameters are holders for extra information that can be communicated from the
caller to the callee when invoking the function. The actual values that fill 
those parameters are called arguments.

A function may have no parameters (indicate with `void` or leave it empty). If 
an array is passed to the function, its size should also be passed, since there
is no other way to know its size.

All parameters are passed by value. In order to use pass-by-reference, supply
pointers to the actual variables.

#### Return (output)

The function may return a value, computed within the body. The type of the 
returned result must be explicitly declared in the header of the function. The
syntax is always `return expression;`, in which `expression` is evaluated 
before actually returning the value to the caller.

The `return` mechanism always tries to cast the returned data into what the 
header states the return type should be.

If nothing is returned, indicate with `void`. In this case, the function may 
end with `return;`

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

#### Bitwise

Similar to broadcasting.

- `&`: bitwise AND
- `|`: bitwise OR
- `^`: bitwise XOR
- `~`: bitwise NOT (ones' complement)
- `<<`: binary shift to the left (number of times indicated in right hand-side)
- `>>`: binary shift to the right (number of times indicated in right hand-side)

#### `sizeof`

Operator returning the number of bytes occupied by the argument. 

`sizeof` is a **special keyword** in C. It is evaluated at compile time, not at
runtime (except for variable-length arrays).

#### Ternary operator

See Control flow section.

#### Pointer

See Pointers section.

#### Casting operators

See Casting section.

#### Precedence

- Higher precedence first
- Same precedence, associativity order (except unary)
- In general, use parentheses

Precedence order:

1. Postfix operators:
    - `()`, `[]`, `->`, `.`, `++`, `--`
2. Unary operators:
    - `+`, `-`, `!`, `~`, `++`, `(type)`, `*` (pointer), `&`, `sizeof`
    - Right to left associativity
3. Multiplicative
    - `*` (product), `/`, `%`
4. Additive
    - `+`, `-`
5. Shifts
6. Relational (size)
7. Relational (equality)
8. Bitwise
    1. AND (`&`)
    2. XOR (`^`)
    3. OR (`|`)
9. Logical
    1. AND (`&&`)
    2. OR (`||`)
10. Ternary
    - `() ? () : ()`
    - Right to left associativity
11. Assignment (all)
    - Right to left
12. Comma

### Casting

Convert from one type to other. It can be implicit (e.g.: assigning an integer 
literal to a floating-point variable) or explicit.

#### Implicit casting

It happens before direct assignment (assigning a literal of one type to a 
variable of other type) but also before operating (before operating with) mixed
types. Deal with care, they should not be relied upon:

```c
int x = 17;
int y = 8;
double z = x/y; // 2.0 is assigned: 17/8 = 2 -> cast to double
```

The following implicit castings are performed:

- Integer to floating-point
- Floating-point to integer: uses truncation

#### Explicit casting

This is the way to do proper casting. It consists of adding the type of the
desired final variable to the input:

```c
double x = 5.0;
double y = 9.3;
double z = ((int) y) * x; // 45.0
```

### `main`

Entry point to the program. It has two possible signatures: 
1. No arguments, returns `int`
2. Two arguments, returns `int`
    - `int argc`: integer with number of command-line arguments passed to the
    program
    - `char *argv[]`: array of character pointers (strings)
The return value is always the "error code" (even if no error has occurred).

## Control flow

Statements that control the order of execution of the program.

### Conditional execution - `if-else`

Control whether a code block is executed or not, based on the fulfillment of a 
condition.

### Ternary operator `?:`

A fast way to write small `if-else` structures.

### Selector - `switch - case`

A fast way to iterate through all possible types of execution for a given 
variable value.

### Redirection - `goto`

Bad style, don't use.

Uses labels to redirect the flow of the program.

### Repeated execution - `for` and `while`

A block of code (body) is executed several times, changing only certain 
controlled parameters between consecutive executions. Braces can be omitted for
single line statements.

If the number of iterations is known beforehand or can be easily parametrized, 
use `for` loops. If the condition to stop changes dynamically or is impossible
to know before the execution, use `while`.

These loops can be nested one inside the other and within the same loop type.

#### `for` loop

In the *starting condition* part of the condition block, one or several 
variables **of the same type** can be initialized. These will be local to the 
body of the loop, and won't exist later. The variables are set to an initial 
value, and their statements must be comma-separated.

The *continuation condition* is an expression that evaluates to true or false 
(or `0` or  `1`). It is evaluated just after *updating code*. If true, the loop
continues.

The *updating code* is a block of one or several expressions that modify 
the loop variables before checking the *continuation condition*. The 
*updating code* is executed after the whole body of the loop has been 
executed. The updating statements must be comma-separated.

There is no obligation to put any of these parameters. If none present, an 
infinite loop is created, which may be exited using `break`. If just the 
*continuation condition* is present, it is the same as a `while` loop.

#### `while` and `do-while`

A loop that executes while the *continuation condition* is met (true). The 
`do-while` version executes the body at least once, the `while` version 
evaluates the condition first, so potentially none.

### Loop control - `break` and `continue`

`continue` allows skipping the rest of the current iteration and jump directly 
to the next one. In the case of `for` loops, it jumps directly to the 
*updating code*, and then continues to the *continuation condition*. In the 
`while` loops, it skips to the *continuation condition* directly.

`break` exits the loop directly in both cases. It is also used in `switch-case`
statements.



## Libraries

### Bool library

If included, `_Bool` is aliased to `bool` and there are new 
literals available, `true` and `false`.

```c
#include <stdbool.h>
```

### String and character libraries

**String**
- Length - `strlen(s)`
    - It returns `size_t`
    - It changes the string (not immutable)
- Copy - `strcpy(dst, src)` & `strncpy(dst, src, size)`
    - `strcpy` does not check if source fits into dest
    - `strncpy` only copies first `size` characters. Use `sizeof(dst) - 1` to 
       account for `\0`
- Concatenation - `strcat(dst_1, src_2)` & `strncat(dst_1, src_2, size)`
    - `src_2` is appended to the right of `dst_1` in-place
    - It returns the value of the first argument
    - Again, the first version is not safe (may overwrite out-of-bounds memory)
- Comparison - `strcmp(str1, str2)` & `strncpm(str1, str2, size)`
    - `==` can be used to compare only memory
    - Returns 0 if they have the same content
    - Returns positive if `str1` comes ASCII-first (lexical order)
    - Returns negative if `str1` comes ASCII-second (lexical order)
    - The second version compares only the first `size` characters
- Search - `strchr(s, c)` & `strstr(s1, s2)`
    - Find a single character or substring within a string
    - Case sensitive
    - If not found, returns `NULL`
    - `strchr` returns a character pointer to the location of the first 
    occurrence. `c` is expected to be `int`, but it can be softcasted.
    - `strstr` returns a character pointer to the location of the first letter
    of the first occurrence
- Tokenization - `strtok(str, delim)`
    - Split a string by a delimiter

**Character**
- Analysis: works on chars
    - Lowercase - `islower(c)`
    - Uppercase - `isupper(c)`
    - Letters - `isalpha(c)`
    - Digits - `isdigit(c)`
    - Hexadecimal - `isxdigit(c)`
    - Alphanumeric - `isalnum(c)`
    - Control chars - `iscntrl(c)`
    - Printable - `isprint(c)`
    - Printable/Visible - `isgraph(c)`
    - Blank - `isblank(c)`
    - Spacing - `isspace(c)`
    - Punctuation - `ispunct(c)`
- Conversion: works on chars, returns `int`, needs hard casting
    - Uppercase - `toupper(c)`
    - Lowercase - `tolower(c)`

```c
#include <string.h>
#include <ctype.h>
```

### Standard library

**Program/System**
- `exit`: exits program with passed integer code.
- `EXIT_SUCCESS`: constant, defined for successful `exit`
- `EXIT_FAILURE`: constant, defined for failed `exit`
- `abort`
- `atexit`
- `getenv`: gets system envirnonment variable, `NULL` pointer if it does not 
  exist
- `qsort`: sorting function
- `system`: runs a command in the shell

**Numeric parsers**
- `atof(s)`: parse string to `double`
- `atoi(s)`: parse string to `int`
- `atol(s)`: parse string to `long`
- `atoll(s)`: parse string to `long long`
- `strtod(s, s_next)`: parse string until `double` is found, leave pointer to 
the rest of the string in s_next
- `strtof(s, s_next)`: same, but parse to `float`
- `strtold(s, s_next)`: same, but parse to `long double`

**Math functions**
- `abs`: defined for `int` arguments to return `int`.
- `rand`: random number between `0` and `RAND_MAX` (`int`).
- `srand`: seeds the random number generation.

**Dynamic memory allocators**
- `malloc`
TODO

```c
#include <stdlib.h>
```

### Standard definitions library

It includes definitions for:
- `NULL`: null pointer constant
- `size_t`:  type of integer produced by `sizeof`
- `offsetof`: offset in bytes of the member of a struct, in `size_t`
- `ptrdiff_t`: integer type produced by subtracting two pointers
- `wchar_t`: type of integer required to hold a "wide" character (encodings)
```c
#include <stddef.h>
```

### Limits library

Implementation-defined limits and sizes for character and integer types. 
Includes:
- `CHAR_BIT`: no. of bits in a `char`.
- `INT_MAX`:  max number that a signed `int` can represent
- `INT_MIN`:  min number that a signed `int` can represent (negative)
- `UINT_MAX`:  max number that an unsigned `int` can represent
And so on.

```c
#include <limits.h>
```

### Vararg library

Macros and functions for variable arguments.

```c
#include <stdarg.h>
```

### Time library

Macros and functions for time and dates manipulation.

```c
#include <time.h>
```

### Error library

Macros and functions for error reporting.

```c
#include <errno.h>
```

### IO library

*Standard Input/Output* library. Contains `printf`, `scanf`.

```c
#include <stdio.h>
```

Library for interaction with external sources (streams, files, etc.). Files can
be read either in text format or in binary format. Contains definitions for:
- `EOF` constant
- `NULL` constant
- `stdin` constant
- `stdout` constant
- `stderr` constant
- `FILE` structs
- `fpos_t` structs

`fopen(filename, accessMode)` returns pointer to `FILE`.
`fclose(pFile)` closes the file, returns `0` if successful, `EOF` otherwise.
`feof(pFile)` returns nonzero if end-of-file, `0` otherwise.
`fflush(pFile)` flushes data to file, returns `0` (success), `EOF` otherwise.


#### Streams

- Standard input: keyboard (usually)
- Standard output: display screen/console
- Standard error: display scree/console

Reading from standard input is done by `getchar()` and `scanf()`.
Writing to standard output or error is done by `putchar()`, `puts()` and 
`printf()`.

Streams are used as stream pointers, which can be binded to files or other data
streams programatically.

**File modes**
"w": text, overwrite
"a": text, append
"r": text, read
"w+": text, overwrite and read, create if not exists
"a+": text, append and read, create if not exists
"r+": text, write and read

**File pointers**
- Contain information about file
- Contain open mode (`w`, `r`, `+`, etc.)
- Address of the buffer in memory to be used for data
- Pointer to the currenbt position in the file for the next operation
- There is a limit to the max number of files open at the same time 
  (`FOPEN_MAX`)
- Open with `fopen()`, returns a file pointer
  - `FILE *fopen(const char * restrict name, const char * restrict mode)`
  - If unsuccessfull, returns `NULL`
- Always close with `fclose()`
  - If successful, returns 0, else `EOF` (int)
  - After that, reference the pointer to `NULL`

**File operations**
- Renaming: `rename`, return 0 only if successful
- Deleting: `remove()`, return 0 only if successful

`printf` prints information in the shape of strings to the console. Variables 
can be interpolated within the strings that are printed using format 
specifiers. See more information on format specifiers 
[here](https://en.wikipedia.org/wiki/Printf_format_string).

```c
#include <stdio.h>
printf(format_spec_str, var1, var2, etc)
```

#### Reading

`fgetc()` reads a character from a text file that has been opened for reading.
Takes a pointer to a `FILE` and returns a character as an `int`. This is useful
to compare with `EOF` constant, which is an `int`.
`getc()` is the same as `fgetc()`, but it can be implemented as a macro.

`rewind()` moves the position to the beginning of the file. Takes a `FILE` 
pointer.

`fgets()` reads a string from a text file or stream opened for reading. Takes a
character array to store the string in, an `int` number of characters to read, 
and a pointer to the stream. If `\n` char is read, it stops reading but it is 
retained and appended a `\0` char at the end. If no error, returns the pointer
`str`. If error or `EOF` read, `NULL` pointer returned.

`fscanf()` reads formatted input from file. It expects a `FILE` pointer and a
format specifier string. Similar to `scanf()`, but from file. It returns an
`int` with the number of items successfully read and assigned.

#### Writing

`fputc()` write a single character to a text file. Returns character writen if
successful, `EOF` if not. Almost never used, inefficient and slow.
`putc()` is the same as `fputc()`, but it can be implemented as a macro.

`fputs()` writes a (constant) string to a file (passed as pointer). It writes
until `\0` is encountered, and then stops. `\0` is not written to the file.

`fprintf()` writes formatted text to file. It expects a `FILE` pointer and a
format specifier string. It also spects the arguments used to format the string.
If successful, returns number of characters written, negative otherwise.

#### Position

`ftell()` returns the current position within file as a `long`. It means an 
offset in bytes from the beginning of the file. This position is meant to be
used with `fseek()`.

`fseek()` accepts a file pointer and a `long` as offset, plus a starting point:
- `SEEK_SET` for the beginning of the file
- `SEEK_CUR` for the current position in the file
- `SEEK_END` for the end of the file
Text files must use `SEEK_SET`, but binery files can use negative offsets.

`fgetpos()` accepts the `FILE` pointer and a `fpos_t` pointer. It is a type
of struct used in `stdio` to record positions in a file. It is meant to be used
with `fsetpos()`. It stores the info on the `fpos_t` object and returns an `int`
with opcode (0 if everything went OK).

`fsetpos()` is used with `fgetpos()` results to advance to said location.

### Math libraries

**Math**
- `pow`, `sqrt`, `exp`, `log`: return `double`
- `cos`, `sin`, `tan`: return `double`
- `acos`, `asin`, `atan`: return `double`
- `ceil`, `floor`, `round`: return `double`
- `nan`: pass string, return `double` (`NaN` if unparseable)
- `remainder`: returns `double`

**Stdlib**
(see `stdlib`)

```c
#include <math.h>
```

### Assertions library

Used for debugging purposes.

- `assert`: macro

```c
#include <assert.h>
```

## Preprocessor directives

Instructions for the preprocessor program, which executes before the compiler.
It performs source code transformation to lift the burden from the programmer
and automatize some tasks.

### `include` directive

It includes other source files to the current one. This brings code that has
been coded elsewhere to scope, allowing reutilization.

```c
#include <stdio.h>
```

### `define` directive

It allows defining constants throughout the program. They will be substituted 
at compile time. They can appear everywhere through the program, usually 
located at the beginning or in an include file for ease of use and wider 
audience.

Syntax:
- No assignment
- No semicolon

It is also used to load system-dependent constants.

## Compilation

### Flags

- `-Wall`: output all warnings and errors encountered by the parser/compiler