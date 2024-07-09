// program 1 for checking semicolon in program
int main(){
    int x = 0
    return 0;
}

// Run the command
/*
mingw32-make
>> .\tests\syntaxCheckTest.cpp
*/


//error received
/*
g++ -Iinclude -Wall -Wextra -std=c++17   -c -o tests/sytaxCheckTest.o tests/sytaxCheckTest.cpp
tests/sytaxCheckTest.cpp: In function 'int main()':
tests/sytaxCheckTest.cpp:4:5: error: expected ',' or ';' before 'return'
     return 0;
     ^~~~~~
tests/sytaxCheckTest.cpp:3:9: warning: unused variable 'x' [-Wunused-variable]
     int x = 0
         ^
mingw32-make: *** [<builtin>: tests/sytaxCheckTest.o] Error 1
*/

// success
