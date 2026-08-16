#include <stdbool.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100);
    ensures \result == (c - b == b - a);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert (-100 <= (c) <= 100);
    //@ assert (-100 <= (b) <= 100);
    //@ assert (-100 <= (a) <= 100);
    //@ assert c - b == c - b;
    //@ assert b - a == b - a;
    
    return (c - b) == (b - a);
}
