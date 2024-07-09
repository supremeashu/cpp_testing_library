int main()
{
    int x = 0
    int y = x + 1;
    int x = 5; // This should trigger a redeclaration error
    return y;
}
// Run the command
/*
mingw32-make
>> .\tests\syntaxSematicCheck.cpp
*/

// error received
/*
g++ -Iinclude -Wall -Wextra -std=c++17   -c -o tests/syntaxSematicCheck.o tests/syntaxSematicCheck.cpp
tests/syntaxSematicCheck.cpp: In function 'int main()':
tests/syntaxSematicCheck.cpp:4:5: error: expected ',' or ';' before 'int'
     int y = x + 1;
     ^~~
tests/syntaxSematicCheck.cpp:5:9: error: redeclaration of 'int x'
     int x = 5; // This should trigger a redeclaration error
         ^
tests/syntaxSematicCheck.cpp:3:9: note: 'int x' previously declared here
     int x = 0
         ^
tests/syntaxSematicCheck.cpp:6:12: error: 'y' was not declared in this scope
     return y;
            ^
tests/syntaxSematicCheck.cpp:3:9: warning: unused variable 'x' [-Wunused-variable]
     int x = 0
         ^
mingw32-make: *** [<builtin>: tests/syntaxSematicCheck.o] Error 1
*/

// success
