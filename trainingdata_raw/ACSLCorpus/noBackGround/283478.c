#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9);
    requires (1 <= (b) <= 9);
    requires (1 <= (c) <= 9);
    ensures \result == true <==> (((a) == (b) && (a) != (c)) || ((a) != (b) && (a) == (c)) || ((a) != (b) && (b) == (c)));
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert (1 <= (a) <= 9);
    //@ assert (1 <= (b) <= 9);
    //@ assert (1 <= (c) <= 9);
    
    return (a == b && a != c) || (a != b && a == c) || (a != b && b == c);
}
