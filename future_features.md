# Future Features

## #include "Folder/.../file.h" or #include "Folder/.../Folder2/file.h"
In Linux, the reason ./ and ../ work in file paths is because there is a requirement that ensures that there can't be 2 or more files/folders with the exact same name within the same folder. What if this concept can be applied recursively to each sub-folder.

If a user can guarantee that there are no conflicting file/folder names recursively within a folder, they can use `#include "Folder/.../file.h"` to allow the compiler to recursively search the Folder and find the file.h because there should only be one file.h.

If there are multiple files/folders with the same name occurring recursively within a folder, the compiler should throw an error. This requirement ensures that file/folder references remain unambiguous and avoids potential conflicts which could cause bugs that are very hard to solve. 

By organizing a project in a folder structure that adheres to these requirements and referencing header files using .../, it becomes possible to rearrange the organization of files/folders within the project without needing to update file paths for each individual header file.

## Garbage collection
Prevent casting to pointers and keep track of references to memory. When there is no more references then free memory automatically.

## export
When the "export" keyword is used the compiler creates a header file and includes the symbol(variable, function, etc) that is exported in that header file.

```
export void exported_function()
    //code

// Compiles to: In .c file
void exported_function(){
    //code
}

// Compiles to: In .h file
#pragma once

void exported_function();
```

## Automatic String Concatenation
- When 2 char*s are next to one another this is automatic string concatenation.

```
->char string = "test."
printf("This is a "string)

// Compiles to. This doesn't work in C. Need to double check.
char *string = "test.";
printf(strcat("This is a", string));
```

