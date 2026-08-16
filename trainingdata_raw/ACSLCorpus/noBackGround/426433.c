#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    requires a == (int)a && b == (int)b && c == (int)c;
    ensures \result == (b - a == c - b);
*/
bool func(int a, int b, int c)
{
    //@ assert a == (int)a;
    //@ assert b == (int)b;
    //@ assert c == (int)c;
    
    return b - a == c - b;
}
