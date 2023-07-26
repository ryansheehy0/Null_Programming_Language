
# Null Programming Language(NPL)
A programming language that makes C pleasant to use. It is compiled to C and can use C libraries.

```
 __   __ ______   __ 
|  \ |  |   __  \|  |     
|   \|  |  |__|  |  |     
|       |   ____/|  |     
|  |\   |  |     |  |____ 
|__| \__|__|     |_______|
```

# Differences from C
Anything that isn't in this doc behaves the same as C.

``` 
#include <stdio.h>

int main()
    printf("Hello World!")
    return 0
```

## Table of Contents
- [Formatting](#formatting)
- [Do while loops](#do-while-loops)
- [For loops](#for-loops)
- [Math Operators](#math-operators)
- [Arrays and Pointers](#arrays-and-pointers)
    - [Pointers to functions](#pointers-to-functions)
- [Match](#match)
- [Functions](#functions)
- [Comments](#comments)
- [Why No Garbage collection](#why-no-garbage-collection)
- [Future Features](#future-features)

## Formatting
- Indentation instead of {}s
    - You can indent after single line comments to make folding blocks of code easier.

```
// Code block title
    int test_var
    test_var += 1
    // Some other code
```

- New lines instead of ;s
- goto statements cannot be used in NPL
- Void cannot be used inside functions. Use () instead.
    - Compiles to: `func_name(void)` and not `func_name()`

## Do while loops
- Instead of having the while at the bottom the do and while is on the same line.

```
do while(true)
    // code
```

## For loops
- For loops use ,s instead of ;s

```
char[] str_name = "string"
int str_size = sizeof(str_name)
for(int i = 0, i < str_size, i++)
    printf("%c", str_name[i])
    //prints out str_name
```

## Math Operators
- ** for exponents
    - Compiles to: `pow(a, b)`

## Arrays and Pointers
- Initializing arrays and pointers, casting to arrays and pointers, and returning arrays and pointers from functions are different in NPL.
    - type[size] array_name
    - ->type ptr_name
- Nothing changes with dereferencing arrays and pointers
- Functions can take arrays with undefined sizes, but to make them usable the size of the array should be another arg(except for strings where \0 can be used to determine its size).
    - `void name(int outer_array_size, int inner_array_size, (int[])[] arg)`
        - Compiles to: `void name(int outer_array_size, int inner_array_size, int (*arg)[])`

```
int main(int argc, (char[])[] args)
    ->int ptr
    ->(->int) double_ptr
    int[] array
    (int[])[] double_array
    // Points to an array of ints
        ->(int[]) pointers_to_array
    // An array of pointers to ints
        (->int)[] array_of_pointers
    return 0

->int return_32_bits()
    return malloc(4)

// Compiles to
int main(int argc, char *args[]){
    int *ptr;
    int **double_ptr;
    int array[];
    int double_array[][];
    // Points to an array of ints
        int (*pointers_to_array)[];
    // An array of pointers to ints
        int *array_of_pointers[];
    return 0;
}

int* return_32_bits(){
    return malloc(4);
}
```

### Pointers to functions

```
int add(int a, int b)
    return a + b

int main()
    ->(int (int, int)) func_ptr1 = add
    // This is also valid
    ->(int (int, int)) func_ptr2 = &add
    return 0
```

## Match
- There are 2 types of match blocks
    - match
    - match_string
- These all compile to if else statements and not switch statements.
- Match statements are meant to replace switch in C. You cannot use the switch block in NPL.

```
int match_int = 4
match(match_int)
    case(1)
        printf("This is a 1.\n")
    case(2)
        printf("This is a 2.\n")
    case(3)
        printf("This is a 3.\n")
    default
        printf("This is greater than 3.\n")

// Compiles to:
int match_int = 4;
if( match_int == 1 ){
    printf("This is a 1.\n");
}if else( match_int == 2){
    printf("This is a 2.\n");
}if else( match_int == 3){
    printf("This is a 3.\n");
}else{
    printf("This is greater than 3.\n");
}
```

```
char[] name = "C++"
match_string(name)
    case("C++" || "Java")
        printf("This is Trash.\n")
    case("C++")
        printf("Why?\n")
    case("C")
        printf("This is Good.\n")
    case("NPL")
        printf("This is the Best.\n")
    default
        printf("This is nothing.\n")
// This will only print This is Trash and not Why?

// Compiles to:
char name[] = "C++";
if( !strcmp(name, "C++") || !strcmp(name, "Java") ){
    printf("This is Trash.\n");
}else if( !strcmp(name, "C++") ){
    printf("Why?\n");
}else if( !strcmp(name, "C") ){
    printf("This is Good.\n");
}else if( !strcmp(name, "NPL") ){
    printf("This is the Best.\n");
}else{
    printf("This is nothing.\n");
}
```

## Functions
- There is automatic function prototyping. Meaning the order in which functions are initialized and used doesn't matter.
    - You can call a function that was initialized after the function that is calling it.

```
int main()
    hello_world()
    return 0

void hello_world()
    printf("Hello World\n")

// Compiles to:
void hello_world(void);

int main(void){
    hello_world();
    return 0;
}

void hello_world(void){
    printf("Hello World\n");
}
```

## Comments
- This language allows for nested multi-line comments like `/* Comment /* Nested Comment */ This text is still a comment. */`
    - Compiles to: `/* Comment Nested Comment This text is still a comment. */`

## Why No Garbage collection
In order to allow garbage collection you would have to disallow casting to points to allow the garbage collector to keep track of the pointers.
    The problem is that casting to pointer can be useful especially for very low level programming.
    The solution to this is not a garbage collector, which also adds performance costs, but an IDE that tells you to free some memory to prevent memory leaks.
        This can be simply done by seeing if a function returns a pointer and if it does then it is assumed that the return pointer needs to be freed.

## [Future Features](./future_features.md)
