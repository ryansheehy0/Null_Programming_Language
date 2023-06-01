# Null Programming Language
A language that makes C pleasant to use. It is compiled to C and can use C libraries.

# Differences from C
Anything that isn't in this doc behaves the same as C.

```
#include <stdio.h>

i32 main()
    printf("Hello World!")
    return 0
```

## Formatting
- Indentation instead of {}s
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
i32 str_size = sizeof(str_name) / sizeof(str_name[0])
for(i32 i = 0, i < str_size, i++)
    printf("%c", str_name[i])
    //prints out str_name
```

## Math Operators
- ** for exponents
    - Compiles to: `pow(a, b)`

## Data types
- Other data types in C can be used, but it is not recommended.
- Singed ints
    - `i8, i16, i32, i64`
    - Compiles to: `int8_t, int16_t, int32_t, int64_t`
- Unsigned ints
    - `u8, u16, u32, u64`
    - Compiles to: `unsigned int8_t, unsigned int16_t, unsigned int32_t, unsigned int64_t`
- Floating point numbers
    - `f32, f64`
    - Compiles to: `float, double`
- Characters
    - `char`
        - Compiles to: `signed char`
- Booleans
    - `bool`
        - Compiles to: `_Bool`
        - `true` and `false` can be used

## Arrays and Pointers
- Initializing arrays and pointers is different
    - type[size] array_name
    - ->type ptr_name
- Nothing changes with dereferencing arrays and pointers
- Functions can take arrays with undefined sizes, but to make them usable the size of the array should be another arg(except for strings where \0 can be used to determine its size).
    - `void name(i32 outer_array_size, i32 inner_array_size, (i32[])[] arg)`
        - Compiles to: `void name(int32_t outer_array_size, int32_t inner_array_size, int32_t (*arg)[])`

```
i32 main(i32 argc, (char[])[] args)
    ->i32 ptr
    ->(->i32) double_ptr
    i32[] array
    (i32[])[] double_array
    // Points to an array of ints
        ->(i32[]) pointers_to_array
    // An array of pointers to ints
        (->i32)[] array_of_pointers
    return 0

// Compiles to
int32_t main(int32_t argc, char *args[]){
    int32_t *ptr;
    int32_t **double_ptr;
    int32_t array[];
    int32_t double_array[][];
    // Points to an array of ints
        int32_t (*pointers_to_array)[];
    // An array of pointers to ints
        int32_t *array_of_pointers[];
    return 0;
}
```

### Pointers to functions

```
i32 add(i32 a, i32 b)
    return a + b

i32 main()
    ->(i32 (i32, i32)) func_ptr1 = add
    // This is also valid
    ->(i32 (i32, i32)) func_ptr2 = &add
    return 0
```

## Match
- There are 2 types of match blocks
    - match
    - match_string
- These all compile to if else statements and not switch statements.
- Match statements are meant to replace switch in C. You cannot use the switch block in NPL.

```
// In NPL
i32 match_int = 4
match(match_int)
    case(1)
        printf("This is a 1.\n")
    case(2)
        printf("This is a 2.\n")
    case(3)
        printf("This is a 3.\n")
    default
        printf("This is greater than 3.\n")

// What it compiles to in C
int32_t match_int = 4;
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
// In NPL
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

// In C this compiles to
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

## Comments
- This language allows for nested multi-line comments like `/* Comment /* Nested Comment */ This text is still a comment. */`
    - Compiles to: `/* Comment Nested Comment This text is still a comment. */`
