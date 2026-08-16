#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result == ((((a) == (b) && (a) != (c)) || ((a) != (b) && (a) == (c)) || ((a) != (b) && (b) == (c)) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert (1 <= (a) <= 9);
    //@ assert (1 <= (b) <= 9);
    //@ assert (1 <= (c) <= 9);
    
    return (a == b && a != c) || (a != b && a == c) || (a != b && b == c);
}
