#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == true <==> (((a) == (b) + 1 && (b) == (c) + 1) || ((a) == (b) - 1 && (b) == (c) - 1));
*/
bool func(int a, int b, int c)
{
    //@ assert 1 <= a <= 9;
    //@ assert 1 <= b <= 9;
    //@ assert 1 <= c <= 9;
    
    return (a == b + 1 && b == c + 1) || (a == b - 1 && b == c - 1);
}
