#include <stdio.h>
#include "calc.h"

int main()
{
    int a = 10, b = 5;
    add(a, b);
    sub(a, b);
    return 0;
}

// STEPS;
// After step 3, there may be errors encounterd in Windows OS but works fine will the Ubuntu System perfectly.


// 1 -> Creating object file for header file (gcc -c lib_add.c lib_sub.c -fpic)
// fpic is required to create a shared (dynamic) library which creates position independent code.

// 2 -> gcc *.o -shared -o lib_calc.so == dynamic library created
//3 -> gcc -c main.c -o main.o
// 4 -> gcc -o main main.o -L. -l_calc 

// after above command have to run ./main to get the output but if there is error encounterd then run below command

// export LD_LIBRARY_PATH=: {Your current path directory full using pwd command}
// then run ./main.