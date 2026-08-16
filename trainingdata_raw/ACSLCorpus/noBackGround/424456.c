#include <stdbool.h>

/*@
    requires \valid_read(input + (0..2));
    requires ((3) == 3 &&
    1 <= (input)[0] <= 9 &&
    1 <= (input)[1] <= 9 &&
    1 <= (input)[2] <= 9);
    ensures \result == (input[1] - input[0] == input[2] - input[1]);
*/
bool func(int* input) {
    int a;
    int b;
    int c;
    bool condition1;
    
    a = input[0];
    b = input[1];
    c = input[2];
    
    //@ assert 1 <= a && a <= 9;
    //@ assert 1 <= b && b <= 9;
    //@ assert 1 <= c && c <= 9;
    
    condition1 = (b - a) == (c - b);
    
    return condition1;
}
