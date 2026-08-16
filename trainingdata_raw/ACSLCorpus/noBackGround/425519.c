#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 9) && (1 <= (b) && (b) <= 9) && (1 <= (c) && (c) <= 9);
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert (1 <= (a) && (a) <= 9);
    //@ assert (1 <= (b) && (b) <= 9);
    //@ assert (1 <= (c) && (c) <= 9);
    return a < b && b < c;
}
