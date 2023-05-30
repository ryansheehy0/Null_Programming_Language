# Null Programming Language
This language is like C, but pleasant to use. It can be compiled to C and use C libraries.

# Differences from C
Anything that isn't in this doc behaves the same as C.

To Do:
    - Garbage collection
    - File paths
        - Header files and #include

## Formatting
- Indentation instead of {}s
- New lines instead of ;s
- Enforced snake_case
    - This can be overwritten with #overwrite on the same line.
- You cannot use typedefs

## Subroutines
- start function instead of main function
    - `int32 start(int32 argc, (char[])[] args)`
- No variadic functions. Use arrays instead.
- Void cannot be used inside functions. Use () instead.
    - Compiles to: func_name(void) and not func_name()
- macro keyword instead of #define

```
macro max(a, b)
    (a > b ? a : b)

macro pi()
    3.14
```


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
int32 str_size = sizeof(str_name) / sizeof(str_name[0])
for(int32 i = 0, i < str_size, i+=1)
    printf("%c", str_name[i])
    //prints out str_name
```

## Math Operators
- ** for exponents
    - Compiles to: pow(a, b)
- There is no ++ or --. Use +=1 or -=1 instead.

## Data types
- Singed ints
    - int8, int16, int32, int64
    - Compiles to: int8_t, int16_t, int32_t, int64_t
- Unsigned ints
    - uint8, uint16, uint32, uint64
    - Compiles to: unsigned int8_t, unsigned int16_t, unsigned int32_t, unsigned int64_t
- Singed floating point numbers
    - float32, float64
    - Compiles to: float, double
- Characters
    - char, uchar
        - Compiles to: signed char, unsigned char
- Booleans
    - bool
        - Compiles to: bool, but can only hold a 0/false or a 1/true

## Arrays and Pointers
- Initializing arrays and pointers is different
    - type[size] array_name
    - ->type ptr_name
- Nothing changes with dereferencing arrays and pointers
- Functions can take arrays with undefined sizes, but to make them usable the size of the array should be another arg(except for strings where \0 can be used to determine its size).
    - `void name(int32 outer_array_size, int32 inner_array_size, (int32[])[] arg)`
        - Compiles to: `void name(int32_t outer_array_size, int32_t inner_array_size, int32_t (*arg)[])`

```
int32 start(int32 argc, (char[])[] args)
    ->int32 ptr
    ->(->int32) double_ptr
    int32[] array
    (int32[])[] double_array
    // Points to an array of ints
        ->(int32[]) pointers_to_array
    // An array of pointers to ints
        (->int32)[] array_of_pointers
    return 0
```

### Pointers to functions

```
int32 add(int32 a, int32 b)
    return a + b

int32 start()
    ->(int32 (int32, int32)) func_ptr1 = add
    // This is also valid
    ->(int32 (int32, int32)) func_ptr2 = &add
    return 0
```

## Match
- There are 3 types of match blocks
    - match
    - match_string
- These all compile to if else statements and not switch statements.
- Match statements are meant to replace switch in C. You cannot use the switch block in NPL.

```
// NPL
int32 match_int = 4
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
match(name)
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

## Type of
- char[] typeof()
_Generic

## Comments
- Can have nested multi-line comments like /* Comment /* Nested Comment */ */
    - When compiled it removes the nested comments
