# Null Programming Language
A simple programming language that can be compiled to C and use C libraries.

## Subroutines
### Functions
return_type function_name(arg1_type arg1_name, arg2_type arg2_name)
- If the function doesn't return anything void can be used.
- The start function is the start of the program.
- You cannot define a function in another function.
- There is no way to make variadic functions in this language.

```
int32 add(int32 a, int32 b)
    return a + b

void do_stuff()
    return

int32 start(int32 args_size, int8 **args)
    print('Hello World!')
    return 0
```

### Macro like functions
macro macro_name(arg1_name, arg2_name)
- Recursion cannot be done in macros.

```
macro add(a, b)
    a + b

macro pi()
    3.14
```
### Variadic functions
- There are n
- Variadic functions are functions that can take a variable number of arguments.
- ... is used to represent a variable number of arguments
    - \$0 or \${0} can be used to get the first argument
    - The type of these arguments has to be specified with the type in front
    - $# gets the number of arguments

Example:
- Executable named print_args
./print_args arg1 arg2 arg3
    - $0 is arg1
    - $1 is arg2
    - $2 is arg3
    - $# is 3

Code:

```
int32 start(string ...)
    for int32 i = 0, i < $#, i+=1
        'Arg ' i ': ' ${i}
    return 0
```

Output:

```
Arg 0: arg1
Arg 1: arg2
Arg 2: arg3
```

## Conditionals
### If

```
int32 a = 0
if a > 0
    'A is positive'
else if a < 0
    'A is negative'
else
    'A is 0'
```

#### Ternary Operators
condition ? if true : if false
- Ternary operators can only be used on one line.

```
int32 a = 5
int32 b = a > 0 ? a : 0 // Only sets b to a if a is positive
```

### While
- You can also use a do while loop by putting do in front of while.

```
bool run = false
while run
    run //Prints out run

do while run
    run //Prints out run

```

### For
for initialization, condition, increment/decrement

```
for int32 i = 0, i < 10, i+=1
    if i == 3
        continue
    if i == 7
        break
    i
//0, 1, 2, 4, 5, 6
```

### Match
- You can put any conditionals in the case. Not just ints.

```
string name = 'C++'
match(name)
    case('C++' || 'Java')
        print('This is Trash\n')
    case('C++')
        print('Why?\n')
    case('C')
        print('This is Good\n')
    case('NPL')
        print('This is the Best\n')
    default
        print('This is nothing\n')
// This will only print THis is Trash

// In C this compiles to
if( strcmp(name, "C++") || name == "Java")
    printf("This is Trash\n")
else if(name == 'C++')
else if(name == 'C')
    print('This is Good\n')
else if(name == 'NPL')
    print('This is Best\n')
else
    print('This is nothing\n')
```

## Printing to the terminal
- To print to the terminal you can just put a string or a variable on a new line.
    - There is automatic string concatenation

```
string test = 'ab'
'This is the value of test: \n' test
//These print the same thing.
'This is the value of test: '
test
```

## Rules for names
- Can only use lower case letters, numbers, and underscores.
- Cannot be a keyword.
- Cannot start with a number

## Operators
### Math Operators

|    |                |
|----|----------------|
| ** | Exponent       |
| *  | Multiplication |
| /  | Division       |
| %  | Modulus        |
| +  | Addition       |
| -  | Subtraction    |
| =  | Assignment     |
| () | Nesting        |

- All math operators can be used as compound operators.

Ex: `A += B is A = A + B` or `A *= B is A = A * B`

### Comparison Operators

|    |                          |
|----|--------------------------|
| <  | Less than                |
| <= | Less than or equal to    |
| >  | Greater than             |
| >= | Greater than or equal to |
| == | Equal to                 |
| != | Not equal to             |
| () | Nesting                  |

### Logical Operators

|      |     |
|------|-----|
| !    | Not |
| &&   | And |
| \|\| | Or  |

### Bitwise Operators

|    |             |
|----|-------------|
| ~  | Inverse     |
| << | Left shift  |
| >> | Right shift |
| &  | And         |
| \| | Or          |
| ^  | Xor         |

- Besides ~, all other bitwise operators can be used as compound operators.

### Unary Operators
- Operations that are only applied to one operand.

|          |                    |
|----------|--------------------|
| -        | negate value       |
| !        | Not                |
| ~        | Bitwise inverse    |
| (type)   | Casting            |
| sizeof() | Gets size in bytes |

### Order of operations
- All precedents are left to right 

|      |                                              |
|------|----------------------------------------------|
| 1st  | ()                                           |
| 2nd  | Unaries: -, !, ~, (type), sizeof()           |
| 3rd  | * / %                                        |
| 4th  | + -                                          |
| 5th  | << >>                                        |
| 6th  | < <= > >=                                    |
| 7th  | == !=                                        |
| 8th  | &                                            |
| 9th  | ^                                            |
| 10th | \|                                           |
| 11th | &&                                           |
| 12th | \|\|                                         |
| 13th | =, +=, -=, *=, /=, %=, <<=, >>=, &=, ^=, \|= |
| 14th | commas                                       |

## Data
### Variables
{const or nothing} {data type} {name}

```
const int32 constant_variable = 0
int32 variable = 0
```

#### Data Types
- Singed ints
    - int8, int16, int32, int64
- Unsigned ints
    - uint8, uint16, uint32, uint64
- Singed floating point numbers
    - float8, float16, float32, float64
- Unsigned floating point numbers
    - ufloat8, ufloat16, ufloat32, ufloat64
- Characters
    - char, uchar
        - These get compiled to char and unsigned char. While int8 gets compiled to int8_t
- Booleans
    - bool

#### Literals
There is no implicit conversion of literals. You cannot do `int32 a = 0.99999` or `int8 character = 'a'`
- int literals
    - 42, -10, 0, 255, etc.
- hexadecimal literals
    - 0x1A, 0xff, 0x10, etc.
- binary literals
    - 0b1010, 0b11011, 0b11, etc.
- float literals
    - 3.14, -2.5, 0.0, etc.
- bool literals
    - true, false, 1, 0
- string literals
    - 'test' is the same as {'t', 'e', 's', 't', '\0'}
        - \' is apostrophe 
        - \n is newline
        - \\ is backslash
        - \0 is null character
        - \$ is $
        - \[ is [
        - \] is ]
        - \t is tab

### Variable functions
#### Casting
    (type)variable
#### Type of
char* typeof()

#### Dynamic Memory
- Garbage collection?
- memaloc
- realoc
- caloc

### Data Structures 
#### Arrays
- Arrays should be set with []s!!!
type *array_name = {0, 0, 0}
type *array_name = 3{0}
type *array_name = 3{1, 2, 3} //is the same as {1, 2, 3, 1, 2, 3, 1, 2, 3}
If no value is specified then the array is initialized with whatever is already in that memory location.
3{} // is the same as { , , , }
You can string together multiple values.
    {1, 2, 3}, 3{4} //is the same as {1, 2, 3, 4, 4, 4}

```
int32 start(int8 **args)
    int8 *string_name1 = {'s', 't', 'r', 'i', 'n', 'g', '\0'}
    int8 *string_name2 = 'string'
    //string_name1 is the same as string_name2
        // Ascii is used to convert a character to an int
    *(string_name1 + 3) = 'o'
    print_string(string_name1)
    //prints out strong

void print_string(int8 *string)
    for int32 i = 0, *(string + i) != '\0', i+=1
        *(string + i)
```

#### Structs
A collection of variables.

```
struct struct_name
    int32 member1
    float member2
    string member3

int32 start(string[] args)
   int32 num_of_args = sizeof(args) / 

   struct struct_name var_name
   var_name.member1 = 10
   var_name.member2 = 0.0
   var_name.member3 = 'String'
   //or
   var_name = {10, 0.0, 'String'}

   stuct_name *stuct_ptr = &var_name
   (*struct_ptr).member1 = 10
```

- Use . operator
    - Struct
    - Enum

## Includes
You can use any C library in NPL
### File paths
- ./Folder_or_File
- ../Folder_or_File
- Folder/.../Folder_or_File
        - Search. Requires user responsibility that there are no 2 files with the same name recursively in a directory.
        - Searches everything recursively and tells if there are 2 things with the same name recursively it throws an error
            - This is to prevent bugs where you do have 2 or more things with the same name recursively where it would be very hard to know why you code wasn't working.

```
#include 
```

## Pointers

|            |                         |
|------------|-------------------------|
| &          | Address of variable     |
| type *name | Creating pointer        |
| *name      | Dereferencing a pointer |

```
int32 a = 10
int32 *b = &a // points to an int32
int32 **c = &b // points to an pointer that points to an int32
'Value of a: ' **c
'Value of b and address of a: ' *c
'Value of c, address of b: ' c 
```

### Pointers to functions

```
// Creating a function
void function_name()
    return

// Setting a function pointer
void () *pfunc = &function_name

// Using a function as an argument
void function_arg(void () *function)
    *function()
    return
```

```
float32 sum(float32 a, float32 b)
    return a + b
float32 sub(float32 a, float32 b)
    return a - b
float32 mult(float32 a, float32 b)
    return a * b
float32 div(float32 a, float32 b)
    return a / b

int32 start(int32 args_size, int8 **args)
    float32 (float32, float32) **prt_function = {&sum, &sub, &mult, &div}
    int8 *users_choice = input('Enter your choice: 0 for sum, 1 for sub, 2 for mult, 3 for div:\n')
    int32 a
    int32 b
    scanf('Enter the 2 numbers: %d %d', a, b)
    [ Note. Other functions can be made to get user input ]
```

## Comments
- // for single line comments
- /* for multi-line comments */
- Can have nested multi-line comments like /* Comment /* Nested Comment */ */
    - When compiled it removes any nested comments.
